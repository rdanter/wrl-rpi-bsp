#@TYPE: Machine inc.
#@NAME: rpi layer

PREFERRED_PROVIDER_virtual/kernel_rpi = "linux-yocto"

DEFAULTTUNE = "arm1176jzfshf"
require conf/machine/include/tune-arm1176jzf-s.inc

SOC_FAMILY = "rpi"
include conf/machine/include/soc-family.inc

MACHINE_FEATURES = "apm sdio vfat ext3 usbhost keyboard screen"
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

KERNEL_IMAGETYPE = "Image"

SERIAL_CONSOLE = "115200 ttyAMA0"

VC4_CMA_SIZE_rpi = "cma-64"

IMAGE_FSTYPES ?= "tar.bz2"
