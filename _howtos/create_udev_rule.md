---
title: Create a udev rule
layout: page
---
# {{page.title}}

# How to create a udev rule for 8BitDo Ultimate C 2.4G Wireless Controller

If you are using Debian 12 and have an 8BitDo Ultimate C 2.4G Wireless Controller, you may notice that it does not work well on Debian. A common workaround is to create a udev rule. Follow these steps to get that done:


## Step 1: Get device id:
Use the `lsusb` command. Example output:

```bash
Bus 001 Device 022: ID 2dc8:3106 8BitDo Ultimate C 2.4G Wireless Controller 
```

## Step 2: Check if the kernel sees the controller
1. Unplug the controller
2. Plug the controller back and run this command right away: `sudo dmesg | tail -n 30`
3. Example output:

```bash
[ 3108.216203] usb 1-11: New USB device strings: Mfr=1, Product=2, SerialNumber=3
[ 3108.216204] usb 1-11: Product: IDLE
[ 3108.216205] usb 1-11: Manufacturer: 8BitDo
[ 3108.216206] usb 1-11: SerialNumber: FDF22320B2
[ 3108.221381] hid-generic 0003:2DC8:3016.0008: hiddev1,hidraw4: USB HID v1.10 Device [8BitDo IDLE] on usb-0000:00:14.0-11/input0
[ 3108.596917] usb 1-11: USB disconnect, device number 23
[ 3109.068779] usb 1-11: new full-speed USB device number 24 using xhci_hcd
[ 3109.222060] usb 1-11: New USB device found, idVendor=2dc8, idProduct=3106, bcdDevice= 1.14
[ 3109.222063] usb 1-11: New USB device strings: Mfr=1, Product=2, SerialNumber=3
[ 3109.222064] usb 1-11: Product: Ultimate C 2.4G Wireless Controller 
[ 3109.222065] usb 1-11: Manufacturer: 8BitDo
[ 3109.222066] usb 1-11: SerialNumber: FDF22320B2
```

## Step 3: create udev rule
1. Run: `sudo vim /etc/udev/rules.d/99-8bitdo-ultimate-c.rules`
2. Add the following:

```bash
ACTION=="add", ATTRS{idVendor}=="2dc8", ATTRS{idProduct}=="3106", RUN+="/sbin/modprobe xpad", RUN+="/bin/sh -c 'echo 2dc8 3106 > /sys/bus/usb/drivers/xpad/new_id'"
```

## Step 4: Reload the rules

1. `sudo udevadm control --reload-rules && sudo udevadm trigger`
2. Unplug the controller and plug it back in. 
3. Everything should be working now