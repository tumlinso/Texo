"""Exercise extraction failures independently of the migrated source tree."""

import importlib.util
from pathlib import Path
import tempfile
import unittest

spec = importlib.util.spec_from_file_location('extraction_audit', Path(__file__).with_name('audit.py'))
audit = importlib.util.module_from_spec(spec)
spec.loader.exec_module(audit)


class ExtractionAuditTests(unittest.TestCase):
    def test_native_toolchain_is_allowed(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'CMakeLists.txt').write_text('set(CMAKE_CXX_COMPILER clang++-18)\n')
            header = root / 'include/Cellerator/model.hh'
            header.parent.mkdir(parents=True)
            header.write_text('#include <Cellerator/compute/operation/operation_core.hh>\n')
            self.assertEqual(audit.source_errors(root), [])

    def test_native_source_cannot_import_compiler(self):
        for include in ('Cellerator/compiler/ast/nodes.hh', 'Texo/ast/nodes.hh',
                        'Cellerator/geometry/compiler/compile_geometry.hh'):
            with self.subTest(include=include), tempfile.TemporaryDirectory() as directory:
                root = Path(directory)
                (root / 'CMakeLists.txt').write_text('project(native LANGUAGES CXX)\n')
                path = root / 'src/numerical.cc'
                path.parent.mkdir()
                path.write_text(f'#include <{include}>\n')
                self.assertTrue(audit.source_errors(root))

    def test_install_rejects_tools_headers_and_private_recovery(self):
        for path in ('bin/cellerator', 'bin/celleratord',
                     'include/Cellerator/compiler/frontend/parser.hh',
                     'include/Cellerator/sdk/runtime.hpp',
                     'share/cellerator/stdlib/core.cell',
                     '.extraction-recovery/original-source.tar.gz'):
            with self.subTest(path=path):
                self.assertTrue(audit.package_errors([path], 'fixture'))
        self.assertEqual(audit.package_errors([
            'include/Cellerator/modeling/model.hh', 'lib/libCellerator.a',
            'cellerator/_native.cpython-313-x86_64-linux-gnu.so'], 'fixture'), [])

    def test_sdist_version_prefix_does_not_hide_old_source(self):
        self.assertTrue(audit.package_errors(['cellerator-0.1.0/src/compiler/parser.cc'], 'fixture'))
        self.assertTrue(audit.package_errors(['cellerator-0.1.0/old-source.cc'], 'fixture',
                                            {'old-source.cc'}))

    def test_modified_historical_bytes_are_detected(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            native = root / 'Cellerator'
            texo = root / 'Texo'
            native.mkdir()
            texo.mkdir()
            artifact = texo / 'receipt.txt'
            artifact.write_text('original evidence\n')
            original = audit.digest(artifact)
            manifest = {'moves': [{'source_path': 'receipt.txt',
                                   'destination_repository': 'Texo',
                                   'destination_path': 'receipt.txt',
                                   'source_sha256': original,
                                   'destination_sha256': original,
                                   'transformation': 'byte-preserved'}]}
            self.assertEqual(audit.manifest_errors(manifest, native, texo), [])
            artifact.write_text('rewritten evidence\n')
            self.assertTrue(audit.manifest_errors(manifest, native, texo))


if __name__ == '__main__':
    unittest.main()
