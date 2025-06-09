---
layout: page
title: Linux
---

# {{page.title}}

## Tips

* **How to move the launcher?** 
```bash
gsettings set org.gnome.shell.extensions.dash-to-dock show-apps-at-top true
```
* **How to disable desktop icons (GNOME)?** 
	* In the extensions manager, set the Desktop icons to False 


## Systemd
### Introduction
* A service, or daemon, is a program that performs a
particular duty
* The SysV init (SysV) was based on the Unix System V initialization daemon.
* The systemd initialization method is the new kid on the block
* it is now the most popular system service initialization and management mechanism.
* Classically, service startups are handled by the init program. This program can be located in the /etc/, the /bin/, or the /sbin/ directory.
* The `pstree -­p 1` command shows you a diagram depicting the parent process of every every service

### How to find out which init system my Linux Machine uses
1. `which init`  Shows you the absolute path of the init program binary
2. `sudo readlink -f absolute/path/of/init/binary`

Additionally, you can use the ps command to look at which program has process id 1: `ps -­ p 1`

Keep in mind that there are other init systems aside from SysV and Systemd. For example, the now discontinued `upstart`. The following Linux Distributions use Upstart:
* Fedora v9–v14
* openSUSE v11.3–v12.2
* RHEL v6
* Ubuntu v6.10–v15.04

Systemd is currently the most used init system although it faces a lot of criticism for not adhering to the Unix Philosophy

### Managing Systemd Systems
With systemd services can be started: 
* When the system boots
* When a particular hardware component is attached to the system
* When certain other services are started, and so on. 
* Some services can be started based on a timer.

#### Systemd units
A unit defines a service, a group of services, or an action. Each unit consists of a name, a type, and a configuration file. There are currently 12 different systemd unit types, as follows:
  * automount
  * device
  * mount
  * path
  * scope
  * service
  * slice
  * snapshot
  * socket
  * swap
  * target
  * timer

The `systemctl` utility is the main gateway to managing systemd and system services.

<br>
 **Basic Formula**: `systemctl` + `option` +  `command`  + `service name`
<br>

The command:  `systemctl list-units` provides a list of the various units currently loaded in your Linux system. Units are identified by their name and type using the format name.type. System services (daemons) have unit files with the `.service` extension. For example in the case of ssh, it would be: `sshd.service`

> Many displays from the `systemctl` utility use the less pager by default. Thus, to exit the display, you must press the Q key. If you want to turn off the systemctl utility’s use of the less pager, tack the `––no-­pager` option on the command.

Group of services are started via target unit files. For example, at system startup the default.target unit is responsible for all the services that are set to start on system starts. This default.target (at least in Ubuntu) is setup as a symbolic link to another target unit file. 
Here is how you can find out which target unit file is linked to:

1. `find / -name default.target 2>/dev/null`
2. `readlink -f /usr/lib/systemd/system/default.target`
3. `systemctl get-­default`

The first command is used to find the absolute path of the default.target file. The second command is used to see the unit file it links to
The systemctl command here is used to see the current default.target. Systemctl is a much more efficient way of doing the same thing command 1 and 2 did.

> Always use the systemctl command as different distros may store the unit files in different directories.

#### Commonly used system boot target unit files

| name                  | Description                                                                                                                                                                |
| --------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| graphical.target      | Provides multiple users access to the system via local terminals and/or through the network. Graphical user interface (GUI) access is offered.                             |
| multi-user.target     | Provides multiple users access to the system via local terminals and/or through the network. No GUI access is offered.                                                     |
| network-online.target | Provides a target that runs after the system has established a connection to the network. This is useful for starting applications that require the network to be present. |
| runlevelN-target      | Provides backward compatibility to SysV init systems, where n is set to 1–5 for the desired SysV runlevel equivalence.                                                     |


* The master systemd configuration file is the `/etc/systemd/system.conf` file.

### Service Unit Files
* Service unit files contain information, such as: 
	* Which environment file to use, 
	* When a service must be started, 
	* What targets want this service started, and so on.
* Config files are located in the following directories. If a config file exist in two or more directories, one takes precedence over the other:
	* `/etc/systemd/system/`
	* `/run/systemd/system/`
	* `/usr/lib/systemd/system/`

>**Be aware**
>There are times when you may need to do changes to systemd's configuration. You ***should not modify*** any unit files in the `/lib/systemd/system/` or `/usr/lib/systemd/system/` directory. Instead copy the file to the /etc/systemd/system/ directory and modify it there. This modified file will take precedence over the original unit file left in the original directory. Also, it will protect the modified unit file from software updates.
>
>If you just have a few additional components, you can extend the configuration. Using
>super user privileges, create a new subdirectory in the `/etc/systemd/system/` directory
>named `service.service-­name.d`, where `service-­name` is the service’s name.

* The command to view service unit files is: `systemctl list-­unit-­files`
* Unit files has enablement state which refers to when the service is started
* There are 3 main enablement states:
	* `enabled`: Service starts at system boot.
	* `disabled`: Service does not start at system boot.
	* `static`: Service starts if another unit depends on it. Can also be manually started.
* However, there are 12 states in total
* To see what directory or directories store a particular systemd unit file(s), use the systemctl utility. Ex: `systemctl cat cron.service`

* Example output:

```bash
# /lib/systemd/system/cron.service
[Unit]
Description=Regular background program processing daemon
Documentation=man:cron(8)
After=remote-fs.target nss-user-lookup.target

[Service]
EnvironmentFile=-/etc/default/cron
ExecStart=/usr/sbin/cron -f $EXTRA_OPTS
IgnoreSIGPIPE=false
KillMode=process
Restart=on-failure

[Install]
WantedBy=multi-user.target
```

* The example outputs shows:
	* The `cron.service` unit file’s base name and directory location.
	* The file's configuration sections:
		* `[Unit]`
			* Contains the basic directives. A directive is a setting that modifies a configuration, such as the After setting.
				* **After** - Sets this unit to start after the designated units.
				* **Before** - Sets this unit to start before the designated units.
				* **Description** - Describes the unit
				* **Documentation** - Sets a list of Uniform Resource Identifiers (URIs) that point to documentation sources. The URIs can be web locations, particular system files, info pages, and man pages.
				* **Conflicts** - Sets this unit to not start with the designated units. If any of the designated units start, this unit is not started
				* **Requires** - Sets this unit to start together with the designated units. If any of the designated units do not start, this unit is not started.
				* **Wants** - Sets this unit to start together with the designated units. If any of the designated units do not start, this unit is still started
				* Note: See `man -­k systemd`  and `man systemd.directives` for more information on systemd's unit files 
		* `[Service]`
			* Sets configuration items, which are specific to that service. Common directvies are:
				* **ExecReload** -Indicates scripts or commands (and options) to run when unit is reloaded.
				* **ExecStart** -Indicates scripts or commands (and options) to run when unit is started.
				* **ExecStop** - Indicates scripts or commands (and options) to run when unit is stopped.
				* **Environment** - Sets environment variable substitutes, separated by a space.
				* **Environment File** - Indicates a file that contains environment variable substitutes
				* **RemainAfterExit** - Set to either no (default) or yes. If set to yes, the service is left active even when the process started by ExecStart terminates. If set to no, then ExecStop is called when the process started by ExecStart terminates.
				* **Restart** - Service is restarted when the process started by ExecStart terminates. Ignored if a `systemctl` restart or `systemctl` stop command is issued. Set to no (default), on-­success, on-­failure, on-­abnormal, on-­watchdog, on-­abort, or always.
				* **Type** - Sets the startup type.
					* Note: The type directive is a more complex than the rest. This directive can be set to at least six different specifications. These are the most common:
						* **forking**: ExecStart starts a parent process. The parent process creates the service’s main process as a child process and exits.
						* **simple**: (Default) ExecStart starts the service’s main process.
						* **oneshot**: ExecStart starts the service’s main process, which is typically a configuration setting or a quick command, and the process exits.
						* **idle**: ExecStart starts the service’s main process, but it waits until all other start jobs are finished.
		* `[Install]`
			* Determine what happens to a particular service if it is enabled or disabled. 
				* An enabled service is one that starts at system boot.
				* A disabled service is one that does not start at system boot.
				* Commonly used directives are:
					* **Alias**: Sets additional names that can be used to denote the service in `systemctl` commands.
					* **Also**: Sets additional units that must be enabled or disabled for this service. Often the additional units are socket type units.
					* **RequiredBy**: Designates other units that require this service.
					* **WantedBy**: Designates which target unit manages this service.

### Target Unit Files
* The primary purpose of target unit files is to group together various services to start at system boot time.
* The default target unit file, default.target, is symbolically linked to the target unit file used at system boot
* The command: `systemctl get-­default` is used to see the current default target
* You can use `systemctl cat graphical.target` to see the graphical target directive

### Understanding the systemctl command
* The `systemctl` command is used to handle services.
* Viewing the status of a service: `systemctl status ssh`
![[Pasted image 20250521121400.png]]

#### Other systemctl commands:

| Command           | Description                                                                                                                                                                                                                                                                                                                                                                  |
| ----------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| daemon-reload     | Load the unit configuration file of the running designated unit(s).                                                                                                                                                                                                                                                                                                          |
| disable           | Mark the designated unit(s) to not be started automatically at system boot time.                                                                                                                                                                                                                                                                                             |
| enable            | Mark the designated unit(s) to be started automatically at system boot time.                                                                                                                                                                                                                                                                                                 |
| mask              | Prevent the designated unit(s) from starting. The service cannot be started using the start command or at system boot. Use the ––now option to immediately stop any running instances as well. Use the ––running option to mask the service only until the next reboot or unmask is used.                                                                                    |
| restart           | Stop and immediately restart the designated unit(s).                                                                                                                                                                                                                                                                                                                         |
| start             | Start the designated unit(s).                                                                                                                                                                                                                                                                                                                                                |
| status            | Display the designated unit’s current status.                                                                                                                                                                                                                                                                                                                                |
| stop              | Stop the designated unit(s).                                                                                                                                                                                                                                                                                                                                                 |
| reload            | Load the service configuration file of the running designated unit(s) to make<br>service configuration changes without stopping the service. Note that this is different from the daemon-­reload command.                                                                                                                                                                    |
| umask             | Undo the effects of the mask command on the designated unit(s).                                                                                                                                                                                                                                                                                                              |
| is-­<br>active    | Shows if the services is active or not                                                                                                                                                                                                                                                                                                                                       |
| is-enabled        | shows if the service is enabled                                                                                                                                                                                                                                                                                                                                              |
| is-failed         | shows failed if the given service has reached a failed state                                                                                                                                                                                                                                                                                                                 |
| is-system-running | shows 'running' if everything is running well with your system.<br>shows 'degraded' if one or more units have failed<br>shows 'maintenance' if the system is running in emergency/recovery mode<br>shows 'initializing' if the system is starting (on boot)<br>shows 'starting' when the system is still booting<br>shows 'stopping' when the system is starting to shutdown |

> **WARNINGS** 
> Use the daemon-­reload command if you need to load systemd unit file configuration changes for a running service. Use the reload command to load a service’s modified configuration file.
> 
> Use caution when employing the systemctl mask command on a service. This links the service to the /dev/null (black hole) to prevent any kind of service startup. This has been described as the “third level of off.” You will not be able to start the service manually. Also, the service will not start at boot time if you did not employ the ––running option when you used mask on it. You can reenable the ability to start the service by using the systemctl unmask command on it.


#### Is it possible to change from one target to another?
The `isolate` command is handy for jumping between system targets. When this command is used along with a target name for an argument, all services and processes not enabled in the listed target are stopped. Any services and processes enabled and not running in the listed target are started.

1. Get the current target: `systemctl get-default`
2. Switch to another target: `systemctl isolate multi-­user.target`

Keep in mind that there are two other special targets:

* **Rescue Target** 
	* When you jump your system to the rescue target, the system mounts all the local file systems, only the root user is allowed to log into the system, networking services are turned off, and only a few other services are started. 
	* The `systemctl is-­system-­running` command will return the maintenance status. Running disk utilities to fix corrupted disks is a useful task in this particular target.

**Emergency Target** 
* When your system goes into emergency mode, the system only mounts the root file system, and it mounts it as read-­only. Similar to rescue mode, it only allows the root user to log into the system, networking services are turned off, and only a few other services are started. 
* The `systemctl is-­system-­running` command will return the maintenance status. If your system goes into emergency mode by itself, there are serious problems. This target is used for situations where even rescue mode cannot be reached.

> **TIP**
> You can use systemctl to reboot, poweroff and halt the system. These are additional targets: `systemctl isolate reboot`
> 
> If your bootloader is GRUB2, you can also reach a given target from the bootloader which is useful when troubleshooting:
> 1. Move your cursor to the menu option that typically boots your system and press the E key to edit it.
> 2. Scroll down and find the line that starts with the linux16 command.
> 3. Press the End key to reach the line’s end. 
> 4. Press the spacebar and type `systemd.unit=target-­name.target`, where target-­name is the name of the target you want your system to activate. 

#### Looking at the systemd-analyze command
This utility can help investigate your system’s boot performance and check for potential system initialization problems. 

* `systemd-­analyze verify`: Allows you to check all your system’s unit files for problems.
* `systemd-­analyze verify sshd.service`: only checks the sshd.service unit file.
* `systemd-­analyze time`: provides time information concerning your system’s initialization.
* `systemd-­analyze ––no-­pager blame`: This display starts with those units that took the longest to initialize. At the bottom of the list are the units that initialized the fastest. It is a handy guide for troubleshooting initialization problems.

### Digging deeper into Systemd
