# Raspberry Pi BSP

COMPATIBLE_MACHINE = "rpi"

# Currently, only the standard kernel is supported
TARGET_SUPPORTED_KTYPES = "standard"

# We don't have a BSP-specific branch in the repository
KBRANCH_DEFAULT_standard = "standard/base"

# Use machine-specific configuration files
SRC_URI += "file://${MACHINE}-standard.scc"
SRC_URI += "file://${MACHINE}-standard.cfg"
