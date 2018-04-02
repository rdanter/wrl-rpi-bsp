#@TYPE: Machine inc.
#@NAME: Raspberry Pi common configuration settings

# Use the standard kernel
PREFERRED_PROVIDER_virtual/kernel = "linux-yocto"

SOC_FAMILY = "rpi"
include conf/machine/include/soc-family.inc

# The RPi does not have a real-time clock
MACHINE_FEATURES = "apm sdio vfat ext3 usbhost keyboard screen"
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

# The bootloader looks for a bzImage file
KERNEL_IMAGETYPE = "Image"

# Use the ARM serial interface for a console
SERIAL_CONSOLE = "115200 ttyAMA0"

# Generate a tar archive of the rootfs by default
IMAGE_FSTYPES ?= "tar.bz2"
