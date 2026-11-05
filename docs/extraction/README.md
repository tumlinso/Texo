# Cellerator extraction

The compiler extraction was applied on 2026-11-05. Texo received 2,189 files;
66 numerical files were rehomed within Cellerator. Another 78 Cellerator files
were updated to repair consumers, build configuration, packaging, and ownership
documentation. The move preserves the existing compiler work; it does not settle
Texo's research language or make the full compiler a finished product.

The [source migration manifest](source-migration.json) records original content
hashes, destinations, transformed content hashes, and native integration edits.
It accounts for every source removal. The split support-product test retains a
native test in Cellerator and transfers the original language-facing test to Texo.
The [validation record](validation.json) records the checks and their limits.

Cellerator retains modeling, neural components, numerical operations,
derivatives, geometry planning, execution preparation, providers, and runtime
contracts. Its native Cell library no longer archives compiler implementations.
Its SDK installations, Python wheel, and source distribution were checked for
compiler payload. The Cellerator source and installed public APIs do not require
Texo. Numerical implementations were preserved through the ownership and naming
changes; a pre-existing geometry test type-name error was corrected locally.

Texo uses its own headers, namespaces, tools, package names, language annotations,
and resource identities. The source, IR, and profile suffixes are `.texo`,
`.texoir`, and `.texoprofile`; persisted formats use Texo identities and major
version 2. The focused host bootstrap and an installed consumer pass. Remaining
compiler/backend integration is described in the [development guide](../development.md).

Historical records retain their original bytes and identifiers. In particular,
536 historical records were checked against the captured originals. Original
staged changes, working-tree patches, and the source snapshot are preserved in
the ignored local `.extraction-recovery/20261105/` directory. The remaining
read-only compiler benchmark workspace and its local experiment payloads were
moved there as an intact directory without changing contents or permissions.
Recovery material is excluded from published source and installed packages.

Existing Cellerator staged entries, unrelated files, and the protected style and
cellular geometry documents were verified unchanged. Publication uses dedicated
extraction commits, preserving unrelated local edits and staging. For shared
integration files, `published_sha256` records the extraction-only commit content
alongside the validated working-tree content. Project Control returned
`workflow_task_already_active` without a handle;
the existing task and authority were left untouched, and no native workflow
completion is claimed. No GPU workloads or performance measurements were run.

Run the ownership and package audit with:

```sh
python tools/extraction/audit.py --cellerator /path/to/Cellerator \
  --manifest docs/extraction/source-migration.json \
  --install /path/to/fresh-sdk-install --archive /path/to/cellerator.whl
```
