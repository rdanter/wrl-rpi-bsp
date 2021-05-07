# Raspberry Pi BSP

COMPATIBLE_MACHINE = "rpi"

# Currently, only the standard kernel is supported
TARGET_SUPPORTED_KTYPES = "standard"

# Make sure we check out the HEAD of the branch
SRCREV_machine_rpi = "${AUTOREV}"

# Use machine-specific configuration files
SRC_URI += "file://${MACHINE}-standard.scc"
SRC_URI += "file://${MACHINE}-standard.cfg"
