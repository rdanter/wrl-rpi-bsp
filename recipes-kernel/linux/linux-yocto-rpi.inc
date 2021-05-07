# Raspberry Pi BSP

COMPATIBLE_MACHINE = "rpi"

# Currently, only the standard kernel is supported
TARGET_SUPPORTED_KTYPES = "standard"

# Base off the RPi 4 BSP-specific branch in the repository
# so we have most (all?) of the RPi patches applied already
KBRANCH_rpi = "v5.4/standard/bcm-2xxx-rpi"

# Make sure we check out the HEAD of the branch
SRCREV_machine_rpi = "${AUTOREV}"

# Use machine-specific configuration files
SRC_URI += "file://${MACHINE}-standard.scc"
SRC_URI += "file://${MACHINE}-standard.cfg"
