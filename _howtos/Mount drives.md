---
layout: page
title: C
---

# {{page.title}}

## 1. Identify the drives:  
* Command: `lsblk`
* Example Output:

```bash
NAME        MAJ:MIN RM  SIZE RO TYPE MOUNTPOINTS
sda           8:0    0 59.6G  0 disk 
├─sda1        8:1    0    1G  0 part /boot/efi
└─sda2        8:2    0 58.6G  0 part /
nvme0n1     259:0    0  1.8T  0 disk 
└─nvme0n1p1 259:1    0  1.8T  0 part 
```

* Look for your new hard drive and note its **device name** and **mount point status** (it should be blank if not mounted). I am working with an NVME drive so mine is: `nvme0n1p1`
* Get the device id: `sudo blkid`
* Example output:

```bash
/dev/nvme0n1p1: LABEL="storage" UUID="79dd393e-506c-4206-a2ba-a00f6f43a146" BLOCK_SIZE="4096" TYPE="ext4" PARTUUID="9229826c-1d5d-44f1-86ea-a0a1f8e3701b"
/dev/sda2: UUID="857e1f0d-e7e2-44f2-9a7b-8d9919e2b730" BLOCK_SIZE="4096" TYPE="ext4" PARTUUID="2b2398cc-d143-465b-8b19-3a4c87a4c679"
/dev/sda1: UUID="4AD1-C83C" BLOCK_SIZE="512" TYPE="vfat" PARTUUID="c26e0617-ade6-44c0-af4e-87dddd5e7ce4"
```

The important line in this case is:

```bash
/dev/nvme0n1p1: 
LABEL="storage" 
UUID="79dd393e-506c-4206-a2ba-a00f6f43a146" 
BLOCK_SIZE="4096" 
TYPE="ext4" 
PARTUUID="9229826c-1d5d-44f1-86ea-a0a1f8e3701b"
```
## 2.  Create mount point
I want this drive to be in `/media` so the command would be: `sudo mkdir -pv /media/rap/bkdrive`
Example output:

```bash
mkdir: created directory '/media/rap'
mkdir: created directory '/media/rap/bkdrive'
```

## 3. Mount the drive
Command: `sudo mount -v /dev/nvme0n1p1 /media/rap/bkdrive`
We use the mount command and the options are the drive + the mount point.
Example output:

```bash
mount: /dev/nvme0n1p1 mounted on /media/rap/bkdrive.
```

## 4. Verify the mount
Just check if the mount point is there. Example commands:

`ls -R /media/` <br>
`df -h /media/rap/bkdrive` <br>
`lsblk` <br>

Example output:

```bash
# ls -R /media
/media:
rap

/media/rap:
bkdrive

/media/rap/bkdrive:
lost+found
ls: cannot open directory '/media/rap/bkdrive/lost+found': Permission denied

# df -h /media/rap/bkdrive/
Filesystem      Size  Used Avail Use% Mounted on
/dev/nvme0n1p1  1.8T   28K  1.7T   1% /media/rap/bkdrive

# lsblk
NAME        MAJ:MIN RM  SIZE RO TYPE MOUNTPOINTS
sda           8:0    0 59.6G  0 disk 
├─sda1        8:1    0    1G  0 part /boot/efi
└─sda2        8:2    0 58.6G  0 part /
nvme0n1     259:0    0  1.8T  0 disk 
└─nvme0n1p1 259:1    0  1.8T  0 part /media/rap/bkdrive
```

## 5. Auto mount the drive on system reboot
Edit the `/etc/fstab` file with a text editor and add the following line:

```bash
UUID=your-uuid-here  mount/point/path  filesystem  defaults  0  2
```

In my case it would be:

```bash
UUID=79dd393e-506c-4206-a2ba-a00f6f43a146  /media/rap/bkdrive  ext4  defaults  0  2
```

Then test fstab: `sudo mount -a` Did you see an error message? if Yes, you have  a typo.

## 6. Set permissions

We need to give ownership of this path to our user so we can use the drive freely

```bash
sudo chown -Rv rap:rap /media/rap/bkdrive 
sudo chmod -Rv 755 /media/rap/bkdrive
```
Example output:

```bash
changed ownership of '/media/rap/bkdrive/lost+found' from root:root to rap:rap
changed ownership of '/media/rap/bkdrive' from root:root to rap:rap
mode of '/media/rap/bkdrive' retained as 0755 (rwxr-xr-x)
mode of '/media/rap/bkdrive/lost+found' changed from 0700 (rwx------) to 0755 (rwxr-xr-x)
```

## 7. Reboot and see if your mount point is there

```bash
sudo telinit 6
# once rebooted sign in
ls -R /media/rap/
```
