# Package manifest and resource hashes v2

The installed `texo-stdlib-manifest-v2` records compiler and TEXO_IR major
revisions, profile requirements, and every regular installed resource as a
lexically sorted relative path with lowercase SHA-256. Backend identity
metadata and standard-library files use the same record form. Absolute prefix,
timestamps, and directory enumeration order are excluded so equal clean
installations compare byte-for-byte.
