# Installing the Latest Linux Kernel on Debian 13 Using Backports

This guide explains how to install the **latest Linux kernel available from the official Debian 13 (`trixie`) Backports repository** on a fresh Debian 13 installation.

At the time this guide was checked, Debian's `trixie-backports` repository provides a newer kernel than the standard Debian 13 kernel. The `linux-image-amd64` backports meta-package tracks the newest kernel available for 64-bit AMD64 systems.

> **Important:** Debian Backports is not the same thing as installing the newest kernel directly from kernel.org. Backports contains newer Debian-packaged kernels rebuilt specifically for Debian 13. Debian recommends installing individual backported packages rather than enabling Backports as a general source for all packages.

---

## 1. Assumptions

This guide assumes:

- You have a fresh **Debian 13 (Trixie)** installation.
- The system is **AMD64/x86-64**.
- You have an Internet connection.
- You are using Debian's official repositories.
- You want the latest kernel provided by **Debian Backports**, not a manually compiled kernel.
- You want to retain the normal Debian kernel as a fallback.

The commands can be run as `root` or through `sudo`.

If you are already logged in as `root`, remove `sudo` from the commands.

---

# 2. Verify That the System Is Debian 13

First check the Debian release:

```bash
cat /etc/debian_version
```

This displays the installed Debian version.

A Debian 13 installation should report a version beginning with:

```text
13
```

You can also check the distribution information:

```bash
cat /etc/os-release
```

This displays information such as:

```text
PRETTY_NAME="Debian GNU/Linux 13 (trixie)"
VERSION_CODENAME=trixie
```

The important value is:

```text
VERSION_CODENAME=trixie
```

Debian 13 uses `trixie` as its codename. Debian's current repository configuration uses the `trixie`, `trixie-updates`, and `trixie-security` suites.

---

# 3. Check the Current Kernel

Before changing anything, determine which kernel you are currently running:

```bash
uname -r
```

Example:

```text
6.12.38+deb13-amd64
```

This tells you the kernel currently running.

For more complete information:

```bash
uname -a
```

Example:

```text
Linux debian 6.12.38+deb13-amd64 #1 SMP PREEMPT_DYNAMIC Debian 6.12.38-1 x86_64 GNU/Linux
```

The `x86_64` portion confirms that you are running an AMD64-compatible system.

---

# 4. Update the Existing Debian Installation

Before adding Backports, update the normal Debian repositories.

```bash
sudo apt update
```

This downloads the latest package information from your configured Debian repositories.

Then upgrade the currently installed packages:

```bash
sudo apt upgrade
```

This installs available updates without intentionally removing packages.

On a fresh installation, it is preferable to perform this step before installing a newer kernel.

If packages were held back, perform:

```bash
sudo apt full-upgrade
```

`full-upgrade` allows APT to install or remove packages when necessary to complete dependency changes.

---

# 5. Configure the Debian Backports Repository

Debian 13 uses the modern **deb822** repository configuration format. Debian recommends this format for Trixie.

Create the Backports repository file:

```bash
sudo vim /etc/apt/sources.list.d/debian-backports.sources
```

The command opens the new repository configuration file in Vim.

Enter:

```text
Types: deb
URIs: https://deb.debian.org/debian
Suites: trixie-backports
Components: main
Enabled: yes
Signed-By: /usr/share/keyrings/debian-archive-keyring.gpg
```

Save and exit Vim:

```text
:wq
```

The important values are:

| Setting | Purpose |
|---|---|
| `Types: deb` | Enables binary Debian packages |
| `URIs:` | Specifies the official Debian mirror |
| `Suites: trixie-backports` | Selects Debian 13 Backports |
| `Components: main` | Uses the official Debian `main` component |
| `Enabled: yes` | Enables the repository |
| `Signed-By:` | Tells APT which Debian archive keyring to use |

This configuration follows Debian's official Backports instructions.

---

# 6. Update APT

After adding Backports, update the package database:

```bash
sudo apt update
```

This causes APT to download package information from `trixie-backports`.

You should see output containing something similar to:

```text
Get:1 https://deb.debian.org/debian trixie-backports InRelease
```

If you do not see `trixie-backports`, stop here and correct the repository configuration before installing the kernel.

---

# 7. Verify That the Backports Kernel Is Available

Check which version of `linux-image-amd64` is available:

```bash
apt policy linux-image-amd64
```

The output should contain something similar to:

```text
linux-image-amd64:
  Installed: (none)
  Candidate: 7.1.8-1~bpo13+1
  Version table:
     7.1.8-1~bpo13+1 100
        100 https://deb.debian.org/debian trixie-backports/main amd64 Packages
     ...
```

The exact version will change over time.

Do **not** hard-code the kernel version into your installation command. Use Debian's `linux-image-amd64` meta-package instead.

At the time this guide was checked, Debian's `linux-image-amd64` Backports package was version `7.1.8-1~bpo13+1` and depended on the corresponding `7.1.8` kernel.

---

# 8. Understand the `linux-image-amd64` Meta-Package

The package you want is:

```text
linux-image-amd64
```

It is a **meta-package**.

It does not itself contain the complete kernel. Instead, it depends on the current kernel package supplied by Debian.

This is important because it means you should generally install:

```bash
linux-image-amd64
```

rather than manually installing a package such as:

```text
linux-image-7.1.8+deb13-amd64
```

The meta-package allows Debian to update you to newer kernel releases in the Backports repository as they become available.

Debian's package information explicitly describes `linux-image-amd64` as a package that depends on the latest Linux kernel for AMD64 systems.

---

# 9. Install the Latest Backports Kernel

Install the kernel using:

```bash
sudo apt install -t trixie-backports linux-image-amd64
```

### Explanation

```text
sudo
```

Runs the command with administrative privileges.

```text
apt install
```

Installs the specified package.

```text
-t trixie-backports
```

Tells APT to obtain the package from Debian Backports.

```text
linux-image-amd64
```

Installs the AMD64 kernel meta-package.

Debian's official Backports documentation specifically recommends using either:

```bash
apt install <package>/trixie-backports
```

or:

```bash
apt install -t trixie-backports <package>
```

when installing a package from Backports.

---

# 10. Install Kernel Headers

Kernel headers are not required merely to boot the kernel, but they are strongly useful if you intend to use software that builds kernel modules.

Examples include:

- NVIDIA drivers
- VirtualBox modules
- VMware modules
- DKMS packages
- Some Wi-Fi drivers
- Other third-party kernel modules

Install the matching headers meta-package:

```bash
sudo apt install -t trixie-backports linux-headers-amd64
```

The `linux-headers-amd64` meta-package tracks the headers corresponding to the current AMD64 kernel.

For a desktop/workstation, installing both packages is therefore appropriate:

```bash
sudo apt install -t trixie-backports linux-image-amd64 linux-headers-amd64
```

---

# 11. Install Recommended Firmware

A newer kernel can support newer hardware, but the kernel may still require firmware packages for specific devices.

For a typical Debian 13 system, ensure the firmware repository is enabled.

Check whether the firmware package is installed:

```bash
dpkg -l firmware-linux-free
```

You can also install the free firmware package:

```bash
sudo apt install firmware-linux-free
```

If your Debian installation uses `non-free-firmware`, which is common for modern hardware, install the relevant firmware packages from that repository as well.

For example:

```bash
sudo apt install firmware-linux
```

If APT reports that a package does not exist, do not force it. The exact firmware package required depends on the hardware.

Debian 13 includes `non-free-firmware` in its standard repository configuration for hardware firmware.

---

# 12. Verify That the New Kernel Was Installed

List installed kernel packages:

```bash
dpkg -l 'linux-image*' | grep '^ii'
```

This displays installed kernel packages.

You should see entries resembling:

```text
ii  linux-image-6.12.x+deb13-amd64
ii  linux-image-7.1.8+deb13-amd64
ii  linux-image-amd64
```

The exact versions will vary.

You can also list the kernel files in `/boot`:

```bash
ls -lh /boot/vmlinuz*
```

Example:

```text
/boot/vmlinuz-6.12.x+deb13-amd64
/boot/vmlinuz-7.1.8+deb13-amd64
```

This confirms that the kernel image exists on the filesystem.

---

# 13. Check the Kernel Modules

List the installed module directories:

```bash
ls -1 /lib/modules/
```

You should see something similar to:

```text
6.12.x+deb13-amd64
7.1.8+deb13-amd64
```

The directory corresponding to the newer kernel confirms that its modules were installed.

---

# 14. Update the GRUB Bootloader

Normally, installing the Debian kernel automatically triggers the necessary bootloader configuration.

You can explicitly regenerate the GRUB configuration:

```bash
sudo update-grub
```

This searches `/boot` for installed kernels and generates the GRUB menu entries.

You should see output resembling:

```text
Found linux image: /boot/vmlinuz-7.1.8+deb13-amd64
Found initrd image: /boot/initrd.img-7.1.8+deb13-amd64
```

The important part is that GRUB detects the newly installed kernel.

---

# 15. Reboot the System

Reboot:

```bash
sudo reboot
```

This terminates the current operating system session and restarts the computer.

During startup, GRUB should normally select the newest installed Debian kernel automatically.

---

# 16. Verify the Running Kernel

After logging back into Debian, run:

```bash
uname -r
```

You should now see the new kernel version.

For example:

```text
7.1.8+deb13-amd64
```

The exact version will depend on the current Backports repository.

This is the most important verification step.

You are not verifying that the kernel is merely installed; you are verifying that the system actually **booted into it**.

---

# 17. Verify the Kernel's Debian Package Origin

You can check which repository supplied the installed meta-package:

```bash
apt policy linux-image-amd64
```

You should see the Backports version installed.

For example:

```text
Installed: 7.1.8-1~bpo13+1
Candidate: 7.1.8-1~bpo13+1
```

The `~bpo13` portion identifies the package as a Debian 13 Backports package.

You can also inspect the exact kernel package:

```bash
dpkg -l | grep 'linux-image-[0-9]'
```

---

# 18. Check Which Kernel GRUB Will Boot

You can inspect the GRUB configuration:

```bash
grep -E '^menuentry ' /boot/grub/grub.cfg
```

This displays the kernel entries known to GRUB.

You may see entries resembling:

```text
menuentry 'Debian GNU/Linux' ...
menuentry 'Advanced options for Debian GNU/Linux' ...
```

The actual kernel entries are normally inside the Advanced Options submenu.

A simpler way to inspect the installed kernels is:

```bash
ls -1 /boot/vmlinuz*
```

---

# 19. Keep the Backports Kernel Updated

Once the Backports kernel meta-package is installed, normal package updates can maintain it.

Run periodically:

```bash
sudo apt update
```

Then:

```bash
sudo apt upgrade
```

Because Debian Backports packages are configured with special priorities, Backports are not treated as a general replacement for the stable Debian repository. Debian specifically recommends opting into individual Backports packages rather than upgrading the entire system from Backports.

To explicitly ensure that the kernel is selected from Backports:

```bash
sudo apt install -t trixie-backports linux-image-amd64 linux-headers-amd64
```

This is also useful when you want to force APT to evaluate the current Backports versions.

---

# 20. Check for a Newer Kernel

You can check the available kernel version at any time:

```bash
apt policy linux-image-amd64
```

Look at:

```text
Installed:
Candidate:
```

For example:

```text
Installed: 7.1.8-1~bpo13+1
Candidate: 7.1.8-1~bpo13+1
```

If the `Candidate` version is newer than `Installed`, a newer kernel is available.

Install it with:

```bash
sudo apt install -t trixie-backports linux-image-amd64 linux-headers-amd64
```

Then reboot:

```bash
sudo reboot
```

After reboot:

```bash
uname -r
```

---

# 21. Do Not Remove the Older Kernel Immediately

After installing a new kernel, Debian normally keeps older kernels installed.

This is desirable.

If the new kernel has a problem with:

- NVIDIA drivers
- Wi-Fi
- Bluetooth
- GPU acceleration
- virtualization
- storage
- networking
- USB devices
- DKMS modules

you can select the older kernel from GRUB.

Do not immediately purge the previous kernel simply because the new kernel works.

A good configuration is to have at least:

```text
Current kernel
Previous known-good kernel
```

available.

---

# 22. Booting an Older Kernel

If the new kernel fails to boot correctly:

1. Reboot the computer.
2. Enter the GRUB menu.
3. Select:

```text
Advanced options for Debian GNU/Linux
```

4. Select the previous kernel.

For example:

```text
Debian GNU/Linux, with Linux 7.1.8+deb13-amd64
Debian GNU/Linux, with Linux 6.12.x+deb13-amd64
```

After selecting the older kernel, verify it with:

```bash
uname -r
```

---

# 23. Check for DKMS Problems

If you use proprietary drivers or other third-party kernel modules, check DKMS after installing the new kernel:

```bash
dkms status
```

This shows whether DKMS modules have been successfully built for the installed kernels.

A healthy result might look similar to:

```text
nvidia/xxx.xx, 7.1.8+deb13-amd64, x86_64: installed
```

If a module reports:

```text
added
```

or:

```text
built
```

but not:

```text
installed
```

investigate the DKMS build before relying on the new kernel.

This is particularly important when using NVIDIA hardware.

---

# 24. Check Loaded Kernel Modules

After booting the new kernel:

```bash
lsmod
```

This displays currently loaded kernel modules.

To check a particular module:

```bash
lsmod | grep nvidia
```

or:

```bash
lsmod | grep nouveau
```

Replace the module name with the driver you want to investigate.

---

# 25. Check Kernel Messages for Errors

Check kernel errors:

```bash
sudo dmesg --level=err,warn
```

This displays kernel messages classified as errors or warnings.

For a more targeted search:

```bash
sudo dmesg | grep -iE 'error|fail|firmware'
```

This searches kernel messages for common hardware or driver problems.

For example, missing firmware may appear as:

```text
firmware: failed to load ...
```

---

# 26. Check the Kernel Command Line

Display the parameters passed to the kernel:

```bash
cat /proc/cmdline
```

Example:

```text
BOOT_IMAGE=/boot/vmlinuz-7.1.8+deb13-amd64 root=/dev/...
```

This is useful when troubleshooting boot parameters, GPU problems, IOMMU, virtualization, or other kernel configuration issues.

---

# 27. Check the Kernel Build Information

Use:

```bash
uname -a
```

This provides:

- Kernel name
- Hostname
- Kernel release
- Kernel build
- Architecture

You can also use:

```bash
uname -r
```

for just the kernel release.

---

# 28. Complete Installation Procedure

For a fresh Debian 13 AMD64 installation, the essential procedure is:

### Step 1 — Update Debian

```bash
sudo apt update
```

Updates APT's package database.

```bash
sudo apt full-upgrade
```

Installs all available Debian updates.

### Step 2 — Add Backports

```bash
sudo vim /etc/apt/sources.list.d/debian-backports.sources
```

Create the Backports repository configuration.

Insert:

```text
Types: deb
URIs: https://deb.debian.org/debian
Suites: trixie-backports
Components: main
Enabled: yes
Signed-By: /usr/share/keyrings/debian-archive-keyring.gpg
```

### Step 3 — Refresh APT

```bash
sudo apt update
```

Downloads the package information for Backports.

### Step 4 — Check the Available Kernel

```bash
apt policy linux-image-amd64
```

Shows the installed and available kernel versions.

### Step 5 — Install the Backports Kernel

```bash
sudo apt install -t trixie-backports linux-image-amd64 linux-headers-amd64
```

Installs the newest Debian 13 AMD64 kernel and its matching headers from Backports.

### Step 6 — Regenerate GRUB

```bash
sudo update-grub
```

Ensures GRUB detects the newly installed kernel.

### Step 7 — Reboot

```bash
sudo reboot
```

Starts the computer using the new kernel.

### Step 8 — Verify

```bash
uname -r
```

Confirms which kernel is actually running.

---

# 29. One-Command Installation After Backports Is Configured

Once the Backports repository has been configured, the actual kernel installation can be reduced to:

```bash
sudo apt update && sudo apt install -t trixie-backports linux-image-amd64 linux-headers-amd64
```

The first command updates APT's package information.

The second installs the current Backports kernel and headers.

Then:

```bash
sudo reboot
```

After the system restarts:

```bash
uname -r
```

---

# 30. Recommended Verification Checklist

After installation, verify all of the following:

```bash
cat /etc/os-release
```

Confirms that the system is Debian 13/Trixie.

```bash
apt policy linux-image-amd64
```

Confirms that the kernel meta-package is coming from Backports.

```bash
dpkg -l 'linux-image*' | grep '^ii'
```

Confirms that the kernel packages are installed.

```bash
ls -1 /lib/modules/
```

Confirms that the kernel modules exist.

```bash
ls -lh /boot/vmlinuz*
```

Confirms that the kernel images exist.

```bash
sudo update-grub
```

Confirms that GRUB detects the kernel.

```bash
uname -r
```

Confirms that the new kernel is actually running.

```bash
dkms status
```

Checks third-party kernel modules.

```bash
sudo dmesg --level=err,warn
```

Checks for kernel-level errors and warnings.

---

# 31. Important Distinction: Backports vs. Debian Testing

Do **not** replace:

```text
trixie
```

with:

```text
forky
```

in an attempt to get an even newer kernel.

`trixie-backports` is specifically designed to provide newer packages while keeping the main operating system on Debian 13 stable. Debian's Backports documentation states that Trixie Backports contains newer packages built for Debian 13 and recommends selectively opting into individual Backports packages.

Do not add the following merely to obtain a newer kernel:

```text
deb https://deb.debian.org/debian forky main
```

That would introduce Debian Testing packages and is a fundamentally different configuration.

---

# 32. Important Distinction: Backports vs. Manually Installing Kernel.org Kernels

This procedure does **not** install a kernel manually from:

```text
https://kernel.org/
```

Instead, Debian provides the kernel as a normal `.deb` package.

That means Debian handles:

- Kernel installation
- Module installation
- Initramfs generation
- GRUB integration
- Package upgrades
- Package removal
- Kernel headers
- Debian-specific patches
- Debian package dependencies

This is substantially easier to maintain than manually installing a kernel.

---

# 33. Current Kernel Situation

Debian's Backports repository is actively updated. The exact kernel version in this guide should therefore **not** be treated as a permanent version number.

The correct procedure is always:

```bash
apt update
apt policy linux-image-amd64
```

and then:

```bash
sudo apt install -t trixie-backports linux-image-amd64
```

At the time this guide was checked, Debian's Backports package metadata identified `linux-image-amd64` as the meta-package for the latest AMD64 kernel, while the repository contained newer kernel series than the stock Debian 13 kernel.

This approach automatically follows Debian's current Backports kernel rather than requiring the guide to be rewritten every time Debian publishes a newer kernel.

---

# 34. Final Recommended Command Sequence

For a normal fresh Debian 13 AMD64 desktop/workstation, the complete sequence is:

```bash
sudo apt update
```

Update package information.

```bash
sudo apt full-upgrade
```

Bring the fresh Debian installation completely up to date.

```bash
sudo vim /etc/apt/sources.list.d/debian-backports.sources
```

Create the Backports repository configuration.

Insert:

```text
Types: deb
URIs: https://deb.debian.org/debian
Suites: trixie-backports
Components: main
Enabled: yes
Signed-By: /usr/share/keyrings/debian-archive-keyring.gpg
```

Then:

```bash
sudo apt update
```

Load the Backports package information.

```bash
apt policy linux-image-amd64
```

Verify the available Backports kernel.

```bash
sudo apt install -t trixie-backports linux-image-amd64 linux-headers-amd64
```

Install the newest AMD64 kernel and matching headers.

```bash
sudo update-grub
```

Regenerate the GRUB configuration.

```bash
sudo reboot
```

Restart into the new kernel.

After reboot:

```bash
uname -r
```

Confirm that the new kernel is running.

Finally:

```bash
dkms status
```

Check that third-party kernel modules were successfully built for the new kernel.

---

## Summary

The correct Debian 13 Backports workflow is:

```text
Debian 13
   │
   ├── Debian Stable repositories
   │
   └── trixie-backports
          │
          └── linux-image-amd64
                    │
                    └── latest Debian 13 Backports kernel
```

The critical command is:

```bash
sudo apt install -t trixie-backports linux-image-amd64 linux-headers-amd64
```

Do not hard-code a kernel version. The `linux-image-amd64` meta-package is specifically designed to track the latest AMD64 kernel supplied by Debian's repository.

Debian Backports is intentionally disabled for normal package selection, so merely adding the repository does **not** turn Debian 13 into a Backports-based distribution. The `-t trixie-backports` option explicitly selects Backports for the kernel installation, which is the behavior Debian documents and recommends.