Raspberry Pi Wireless
=====================

The Raspberry Pi 3 B/B+ and Zero-Wireless have on-board wifi adapters. The
following steps are needed to enable the adapter with this BSP.

1. Install Firmware
-------------------
The Broadcom firmware can be obtained from:

    https://github.com/RPi-Distro/firmware-nonfree.git

From the brcm subdirectory you need just the following files:

  * brcmfmac43430-sdio.bin
  * brcmfmac43430-sdio.txt

for the 3B, or:

  * brcmfmac43455-sdio.bin
  * brcmfmac43455-sdio.clm_blob
  * brcmfmac43455-sdio.txt

for the 3B Plus.

Create a directory on the RPi rootfs and copy these files as follows:

    $ sudo mount -t ext4 /dev/mmcblk0p2 /mnt
    $ cd /mnt
    $ sudo mkdir -p lib/firmware/brcm
    $ sudo cp /path/to/firmware-nonfree/brcm/brcmfmac43???-sdio.* lib/firmware/brcm/
    $ cd
    $ sudo umount /mnt

Boot the rpi and log in. To verify the wireless interface has been detected use
`ifconfig -a` and you should see `wlan0` listed along with `eth0` and `lo`.

    wlan0     Link encap:Ethernet  HWaddr fe:26:12:bb:23:4b
              UP BROADCAST MULTICAST  MTU:1500  Metric:1
              RX packets:0 errors:0 dropped:0 overruns:0 frame:0
              TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
              collisions:0 txqueuelen:1000
              RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)

The hardware address will vary by device.

2. Test Wireless
----------------
To quickly test connectivity to a wifi hub, the following steps may be used:

Edit the `/etc/wpa_supplicant.conf` file so it looks something like this:

    ctrl_interface=/var/run/wpa_supplicant
    ctrl_interface_group=0
    update_config=1

    network={
        scan_ssid=1
        ssid="SSID"
        proto=WPA
        key_mgmt=WPA-PSK
        psk="PASSWORD"
    }

Then start the wireless connection with:

    # ifconfig wlan0 up
    # wpa_supplicant -i wlan0 -c /etc/wpa_supplicant.conf -B
    # dhclient wlan0

This assumes your access point provides a dynamic IP address using DHCP and
that you are using WPA security.

If all goes well you should have a wireless connection.

3. Using Network Manager
------------------------
For a configuration that will be persistent over reboots, network manager can
be used. This is not the only option, `systemd-networkd` can also be used, or
you could even use the method used for testing, but add the three commands to
`/etc/rc.local` to have them execute each time the board boots.

Network manager is not included in the rootfs by default, so first it should
be added to a build. One method to do that is to add it to the local.conf file
before building the rootfs.

    $ echo "IMAGE_INSTALL_append = \" networkmanager-nmcli\"" >> conf/local.conf

The use bitbake to build as usual.

On the target, once booted with the firmware in place (as above), the following
commands can be used:

    # nmcli con add type wifi con-name <NAME> ifname wlan0 ssid <SSID>
    # nmcli con modify <NAME> wifi-sec.key-mgmt wpa-psk
    # nmcli con modify <NAME> wifi-sec.psk <PASSWORD>
    # nmcli con up <NAME>

To verify this, reboot and log in. The wireless network should be established
automatically.
