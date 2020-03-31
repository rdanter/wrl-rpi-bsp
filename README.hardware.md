Raspberry Pi BSP
================

1. Supported Boards
-------------------

This BSP has been tested on the following boards:

  * Raspberry Pi Model B Rev 1
  * Raspberry Pi 2 Model B Rev 1.1
  * Raspberry Pi 3 Model B Rev 1.2
  * Raspberry Pi 3 Model B Plus Rev 1.3

Untested, but these should also work using the "rpi" configuration:

  * Raspberry Pi Model A/A+/B+
  * Raspberry Pi Zero
  * Raspberry Pi Zero Wireless
  * Compute Module

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

* The hardware address of the Bluetooth controller appears as AA:AA:AA:AA:AA:AA
  which seems to be an issue with bluez. See:

    https://raspberrypi.stackexchange.com/questions/69222/why-is-bluetooth-address-now-showing-up-as-aaaaaaaaaaaa


4. Change History
-----------------

The following table lists the major changes to the BSP.

Date       | Description
-----------|-------------
2020-01-20 | Ported to WRL LTS 19 RCPL 2.
2018-11-14 | Ported to WRL LTS 18.
2018-04-05 | Add Raspberry Pi 3 support.
2018-04-02 | Add Raspberry Pi 2 support.
2017-11-27 | Ported to WRL LTS 17 RCPL 1.
2017-10-02 | Initial version for WRL 9 RCPL 11.


[1]: https://www.raspberrypi.org/documentation/hardware/raspberrypi/README.md
