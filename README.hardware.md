Raspberry Pi BSP
================

1. Supported Boards
-------------------

This BSP has been tested on the following boards:

  * Raspberry Pi Zero W Rev 1.1
  * Raspberry Pi 1 Model B Rev 1
  * Raspberry Pi 2 Model B Rev 1.1
  * Raspberry Pi 3 Model B Rev 1.2
  * Raspberry Pi 3 Model B Plus Rev 1.3

Untested, but these should also work using the "rpi" configuration:

  * Raspberry Pi Model A/A+/B+
  * Raspberry Pi Zero
  * Compute Module

NOTE: There is an official Wind River BSP for the Raspberry Pi 4.

Further details of the Raspberry Pi hardware variations can be found on the
[RaspberryPi.org][1] web site.


2. Features
-----------

The following features have been tested:

* Serial console (`ttyAMA0` & `ttyS0`)
* HDMI console (`tty1`)
* SD / microSD card reader (`mmcblk0`)
* USB interface with:
  + On-board wired Ethernet (`eth0`)
  + External USB storage devices (`sd`)
* On-board wireless Ethernet (`wlan0`)
* On-board Bluetooth (`hid0`)
* I2C bus


3. Known Issues
---------------

The following problems have been identified with this BSP:

* Several RPi boards have built-in wireless (wifi) and bluetooth (bt) support.
  The drivers for these devices require binary firmware blobs which are not
  free, therefore they have not been included in this BSP.
  See docs/Wireless.md for more details.


[1]: https://www.raspberrypi.org/documentation/hardware/raspberrypi/README.md
