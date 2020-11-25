FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

# Use our own fstab to make sure boot partition is mounted
SRC_URI += "file://fstab"

