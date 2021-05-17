# Raspberry Pi BSP - 5.10 Kernel

require linux-yocto-rpi.inc

# Base off the RPi 4 BSP-specific branch in the repository
# so we have most of the RPi patches applied already
KBRANCH_rpi = "v5.10/standard/bcm-2xxx-rpi"

FILESEXTRAPATHS_prepend := "${THISDIR}/linux-yocto-5.10:"

