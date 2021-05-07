# Raspberry Pi BSP - 5.4 Kernel

require linux-yocto-rpi.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/linux-yocto-5.4:"

# Base off the RPi 4 BSP-specific branch in the repository
# so we have most (all?) of the RPi patches applied already
KBRANCH_rpi = "v5.4/standard/bcm-2xxx-rpi"
