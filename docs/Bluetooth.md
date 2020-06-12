Raspberry Pi Bluetooth
======================

The Raspberry Pi 3 B/B+ and Zero-Wireless have on-board Bluetooth adapters. The
following steps are required to enable the adapters with this BSP.

1. Install Firmware
-------------------
See `Wireless.md` for details of where to find and how to install the firmware.

In addition, the following Bluez firmware files are needed:

  * BCM43430A1.hcd - for the RPi 3B
  * BCM4345C0.hcd  - for the RPi 3B Plus

These resolve issues with the hardware address being read as all AA's.

2. Test Bluetooth
-----------------
The following steps may be used to quickly test Bluetooth functionality using a
Bluetooth keyboard. The commands below may be entered via a remote terminal,
e.g. using ssh.

The on-board Bluetooth controller is connected to the CPU via a serial port, so
the first step is to attach the driver to the device:

    # btattach -B /dev/ttyAMA0 -P bcm -S 115200 -N &
    [1] 336
    Attaching Primary controller to /dev/ttyAMA0
    Switched line discipline from 0 to 15
    Device index 0 attached

Then bring up the device:

    # hciconfig hci0 up

From this point the `bluetoothctl` utility can be used to start the relevant
agents and scan for devices as follows:

    # bluetoothctl
    Agent registered
    [bluetooth]# default-agent
    Default agent request successful
    [bluetooth]# discoverable on
    Changing discoverable on succeeded
    [CHG] Controller AA:AA:AA:AA:AA:AA Discoverable: yes
    [bluetooth]# scan on
    Discovery started
    [CHG] Controller AA:AA:AA:AA:AA:AA Discovering: yes
    [NEW] Device 0C:FC:83:81:26:D6 Bluetooth  Keyboard

At this point we have found the hardware address of the keyboard so we can pair
with it. At one point you will be prompted to enter a pin code, enter the code
(on the Bluetooth keyboard) and press return:

    [bluetooth]# pair 0C:FC:83:81:26:D6
    Attempting to pair with 0C:FC:83:81:26:D6
    [CHG] Device 0C:FC:83:81:26:D6 Connected: yes
    [agent] PIN code: 173774
    [CHG] Device 0C:FC:83:81:26:D6 Modalias: usb:v05ACp022Cd011B
    [CHG] Device 0C:FC:83:81:26:D6 UUIDs: 00001124-0000-1000-8000-00805f9b34fb
    [CHG] Device 0C:FC:83:81:26:D6 UUIDs: 00001200-0000-1000-8000-00805f9b34fb
    [CHG] Device 0C:FC:83:81:26:D6 ServicesResolved: yes
    [CHG] Device 0C:FC:83:81:26:D6 Paired: yes
    Pairing successful
    [CHG] Device 0C:FC:83:81:26:D6 ServicesResolved: no
    [CHG] Device 0C:FC:83:81:26:D6 Connected: no

In order for the keyboard to connect without needing a pin code in future it
should be declared trusted:

    [bluetooth]# trust 0C:FC:83:81:26:D6
    [CHG] Device 0C:FC:83:81:26:D6 Trusted: yes
    Changing 0C:FC:83:81:26:D6 trust succeeded

We can stop scanning for new devices:

    [bluetooth]# scan off
    Discovery stopped
    [CHG] Controller AA:AA:AA:AA:AA:AA Discovering: no

Now we connect to the keyboard in order to start receiving entries:

    [bluetooth]# connect 0C:FC:83:81:26:D6
    Attempting to connect to 0C:FC:83:81:26:D6
    [CHG] Device 0C:FC:83:81:26:D6 Connected: yes
    Connection successful
    [CHG] Device 0C:FC:83:81:26:D6 ServicesResolved: yes

Finally we can exit the `bluetoothctl` utility:

    [Bluetooth  Keyboard]# quit

At this point it should be possible to log in on the console using the newly
configured keyboard.

The pairing will be remembered over a reboot, but you will need to re-run the
first two commands again to enable the Bluetooth controller:

    # btattach -B /dev/ttyAMA0 -P bcm -S 115200 -N &
    [1] 336
    Attaching Primary controller to /dev/ttyAMA0
    Switched line discipline from 0 to 15
    Device index 0 attached
    # hciconfig hci0 up

This could be automated through systemd.
