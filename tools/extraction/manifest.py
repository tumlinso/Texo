#!/usr/bin/env python3
"""Combine migration records and reject unaccounted source removal."""

import argparse
import hashlib
import json
from pathlib import Path


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', type=Path, required=True)
    parser.add_argument('--cellerator', type=Path, required=True)
    parser.add_argument('--texo', type=Path, required=True)
    parser.add_argument('--compiler-moves', type=Path, required=True)
    parser.add_argument('--numerical-moves', type=Path, required=True)
    parser.add_argument('--native-remainder', action='append', default=[])
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    original = {r['path']: r for r in json.loads((args.baseline / 'files.json').read_text())}
    moves = {}
    for row in json.loads(args.compiler_moves.read_text()):
        old, new = row['source'], row['destination']
        if old not in original:
            raise ValueError(f'compiler source absent from captured baseline: {old}')
        destination = args.texo / new
        preserved = row.get('historical_bytes_preserved', False)
        moves[old] = {'source_path': old, 'source_sha256': original[old]['sha256'],
                      'destination_repository': 'Texo', 'destination_path': new,
                      'destination_sha256': digest(destination),
                      'transformation': 'byte-preserved' if preserved else 'compiler-extraction',
                      'remove_source': True}
        if preserved and digest(destination) != original[old]['sha256']:
            raise ValueError(f'historical evidence was changed: {old}')
    for old in args.native_remainder:
        if old not in moves or not (args.cellerator / old).is_file():
            raise ValueError(f'missing explicitly split native source: {old}')
        moves[old]['remove_source'] = False
        moves[old]['transformation'] = 'split-native-and-compiler-test'
    numerical = json.loads(args.numerical_moves.read_text())
    for row in numerical['moves']:
        old, new = row['from'], row['to']
        if old in moves:
            raise ValueError(f'source assigned to two owners: {old}')
        moves[old] = {'source_path': old, 'source_sha256': original[old]['sha256'],
                      'destination_repository': 'Cellerator', 'destination_path': new,
                      'destination_sha256': digest(args.cellerator / new),
                      'transformation': 'native-' + row['kind'], 'remove_source': True}
    missing = sorted(path for path in original
                     if not (args.cellerator / path).exists() and path not in moves)
    if missing:
        raise ValueError('source removals missing migration records:\n' + '\n'.join(missing))
    edits = []
    for rel, before in sorted(original.items()):
        path = args.cellerator / rel
        if (rel in moves and moves[rel]['remove_source']) or 'sha256' not in before or not path.is_file():
            continue
        after = digest(path)
        if after != before['sha256']:
            edits.append({'path': rel, 'source_sha256': before['sha256'],
                          'destination_sha256': after})
    result = {'format': 'texo-source-extraction', 'version': 1,
              'source_repository': 'https://github.com/tumlinso/Cellerator',
              'source_commit': (args.baseline / 'head.txt').read_text().strip(),
              'baseline_inventory_sha256': digest(args.baseline / 'files.json'),
              'source_index_sha256': digest(args.baseline / 'index.original'),
              'moves': sorted(moves.values(), key=lambda row: row['source_path']),
              'edits': edits}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'moves': len(moves), 'native_moves': len(numerical['moves']),
                      'edits': len(edits), 'unaccounted_removals': 0}))


if __name__ == '__main__':
    main()
