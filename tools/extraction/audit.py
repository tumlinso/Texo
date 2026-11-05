#!/usr/bin/env python3
"""Check source ownership and freshly built distributions after extraction."""

import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import re
import tarfile
import zipfile


SOURCE_SUFFIXES = {'.h', '.hh', '.hpp', '.cuh', '.c', '.cc', '.cpp', '.cu', '.ccm'}
SOURCE_ROOTS = ('include', 'src', 'modules', 'bindings', 'tests', 'examples', 'tools', 'cmake')
RETIRED_ROOTS = ('src/compiler/', 'include/Cellerator/compiler/',
                 'include/Cellerator/sdk/', 'cmake/compiler/',
                 'tools/cellerator/', 'tools/celleratord/', 'stdlib/', 'profiles/')
NATIVE_RENAMES = ('include/Cellerator/geometry/compiler/', 'src/geometry/compiler/',
                  'include/Cellerator/execution/joint_compiler/',
                  'src/execution/joint_compiler/',
                  'include/Cellerator/profiling/joint_compiler/')
REVERSE_INCLUDE = re.compile(
    r'Cellerator/(?:compiler|sdk)/|[<"]Texo/|\btexo::|'
    r'Cellerator/(?:geometry/compiler|execution/joint_compiler|profiling/joint_compiler)/|'
    r'::joint_compiler\b|::geometry::compiler\b|\bcompile_geometry\b')
RETIRED_BUILD = re.compile(
    r'(?:src|cmake)/compiler/|tools/celleratord?/|Cellerator::Compiler\b|'
    r'Cellerator_HAS_COMPILER\s+(?:TRUE|ON)|\bcellerator_compile_cell\b')


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def source_errors(cellerator):
    errors = []
    for root in RETIRED_ROOTS + NATIVE_RENAMES:
        path = cellerator / root
        if path.exists() and any(p.is_file() for p in path.rglob('*')):
            errors.append(f'retired source tree remains: {root}')
    for root in SOURCE_ROOTS:
        for path in (cellerator / root).rglob('*'):
            if not path.is_file():
                continue
            is_source = path.suffix in SOURCE_SUFFIXES
            is_build = path.name == 'CMakeLists.txt' or path.suffix == '.cmake'
            if not is_source and not is_build:
                continue
            content = path.read_text(errors='replace')
            pattern = REVERSE_INCLUDE if is_source else RETIRED_BUILD
            for number, line in enumerate(content.splitlines(), 1):
                if pattern.search(line):
                    errors.append(f'{path.relative_to(cellerator)}:{number}: retired dependency')
    for path in (cellerator / 'CMakeLists.txt',):
        for number, line in enumerate(path.read_text().splitlines(), 1):
            if RETIRED_BUILD.search(line):
                errors.append(f'{path.name}:{number}: retired build dependency')
    return errors


def manifest_errors(manifest, cellerator, texo):
    errors = []
    roots = {'Cellerator': cellerator, 'Texo': texo}
    for entry in manifest['moves']:
        old = cellerator / entry['source_path']
        destination = roots[entry['destination_repository']] / entry['destination_path']
        if not destination.is_file():
            errors.append(f'missing migration destination: {destination}')
        elif digest(destination) != entry['destination_sha256']:
            errors.append(f'migration destination changed: {destination}')
        if entry.get('remove_source', True) and old != destination and old.exists():
            errors.append(f'migration source remains: {old}')
        if entry.get('transformation') == 'byte-preserved' and destination.is_file():
            if digest(destination) != entry['source_sha256']:
                errors.append(f'historical bytes changed: {destination}')
    for entry in manifest.get('edits', []):
        path = cellerator / entry['path']
        expected = {entry['destination_sha256']}
        if entry.get('published_sha256'):
            expected.add(entry['published_sha256'])
        if not path.is_file() or digest(path) not in expected:
            errors.append(f'native integration file changed: {path}')
    return errors


def package_errors(names, label, removed_sources=()):
    errors = []
    for name in names:
        path = PurePosixPath(name)
        # Source distributions normally have one project/version directory.
        variants = (str(path), str(PurePosixPath(*path.parts[1:])))
        for rel in variants:
            retired = any(rel.startswith(root) for root in RETIRED_ROOTS + NATIVE_RENAMES)
            installed = (rel in ('bin/cellerator', 'bin/celleratord') or
                         rel.startswith(('share/cellerator/stdlib/',
                                         'share/cellerator/profiles/')))
            if retired or installed or rel in removed_sources:
                errors.append(f'{label}: retired compiler payload: {name}')
                break
        if '.extraction-recovery' in path.parts:
            errors.append(f'{label}: private recovery payload: {name}')
    return errors


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cellerator', type=Path, required=True)
    parser.add_argument('--texo', type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument('--manifest', type=Path)
    parser.add_argument('--install', type=Path, action='append', default=[])
    parser.add_argument('--archive', type=Path, action='append', default=[])
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    errors = source_errors(args.cellerator)
    removed = set()
    if args.manifest:
        manifest = json.loads(args.manifest.read_text())
        errors += manifest_errors(manifest, args.cellerator, args.texo)
        removed = {entry['source_path'] for entry in manifest['moves']
                   if entry.get('remove_source', True)}
    for prefix in args.install:
        if not prefix.is_dir():
            errors.append(f'missing install prefix: {prefix}')
            continue
        names = [str(p.relative_to(prefix)) for p in prefix.rglob('*') if p.is_file()]
        errors += package_errors(names, str(prefix))
    for archive in args.archive:
        if zipfile.is_zipfile(archive):
            with zipfile.ZipFile(archive) as reader:
                names = reader.namelist()
        else:
            with tarfile.open(archive) as reader:
                names = reader.getnames()
        errors += package_errors(names, str(archive), removed)
    result = {'status': 'pass' if not errors else 'fail', 'errors': errors,
              'installs_checked': len(args.install), 'archives_checked': len(args.archive)}
    if args.output:
        args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))
    return bool(errors)


if __name__ == '__main__':
    raise SystemExit(main())
