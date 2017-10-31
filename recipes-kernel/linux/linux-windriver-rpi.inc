# Raspberry Pi

# Currently, only the standard kernel is supported
TARGET_SUPPORTED_KTYPES_rpi = "standard"

# We don't have a BSP-specific branch in the repository
KBRANCH_DEFAULT_standard_rpi = "standard/base"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://rpi-standard.scc"
SRC_URI += "file://rpi-standard.cfg"
