## Problem 1
A technician is reviewing a web server log and wants to find every occurrence of the word error. The log contains different capitalizations such as ERROR, Error, and error. The technician also wants to know the line number of each match. Use the file: `logs.log` to complete this task.

### General Steps to solve it
1. Open the terminal.
2. Move to the directory containing the log file.
3. Search for the word error.
4. Ignore capitalization differences.
5. Display line numbers.

### Solution
`grep -ni 'error' logs.log`

> Take a screenshot of your terminal to submit later.

## Problem 2
A technician performed a network scan to discover devices connected to the local network using: `nmap -sP 192.168.1.0/24`. The output of the command has been saved to the file: `nmap_output.txt`. The scan generated a report containing hostnames, IP addresses, and status information. The technician only wants to display the lines that contain IPv4 addresses so they can quickly identify the devices they discovered.

### General Steps to solve it
1. Open the terminal.
2. Move to the directory containing the scan output file.
3. Search for lines that contain text in the format of an IPv4 address.
4. Display only the matching lines.

### Solution
`grep "[0-9]\+\.[0-9]\+\.[0-9]\+\.[0-9]\+" nmap_output.txt`

> Take a screenshot of your terminal to submit later.

## Problem 3
A technician is troubleshooting a computer with five network cards (NICs). They used the ip addr command to view network information. The output contains many details, but the technician only wants to locate the IPv4 addresses assigned to the network cards. The output has been saved to the file `network_info.txt`


### General Steps to solve it
Open the terminal.
Move to the directory containing the file.
Search for lines that contain IPv4 addresses.
Display only the matching lines.

### Solution
`grep "inet [0-9]" network_info.txt`

> Take a screenshot of your terminal to submit later.


## Problem 4
A student is reviewing a Python program for one of his Introduction To Computer Science assignments. The program contains many variables, and the student needs to locate every line where the variable `total_score` appears to understand how it is used. 
  
### General Steps to solve it
Open the terminal.
Move to the directory containing the Python file.
Search for the variable name inside the file.
Display every line where the variable appears.

### Solution
`grep "total_score" grades.py`

> Take a screenshot of your terminal to submit later.

## Problem 5
A Linux administrator has a list of user accounts. They want to display every account except the disabled accounts. The file name is `users.csv`.

### General Steps to solve it
1. Open the terminal.
2. Move to the file location.
3. Exclude lines containing the word guest.
4. Display all remaining lines.

### Solution
`grep -v "disabled" users.txt`

> Take a screenshot of your terminal to submit later.

## Problem 6
A student has a configuration file and wants to number every line in the file so they can easily reference specific settings while troubleshooting. The file is called settings.conf.

### General Steps to solve it
Open the terminal.
Move to the directory containing the file.
Match the beginning of every line.
Display line numbers.

### Solution
`grep -in "^" settings.conf`

> Take a screenshot of your terminal to submit later.



--------

## What will you learn

* Learn how to search for specific text patterns using `grep`
* Practice extracting and displaying specific columns of data using `awk`
* Learn how to modify and replace text using `sed`
* Develop the ability to process structured text files from the Linux terminal
* Practice combining multiple text-processing commands to solve real-world problems

## Complete these instructions before starting this activity
1. In your home directory, clone this repository so you can have all the necessary files: `https://github.com/linuxworkshop67/handling_text`
2. Update your system using the command: `sudo apt update && sudo apt upgrade`
3. Install the packages: `rig`, `bat`, `uuid-runtime` using the command: `sudo apt install rig bat uuid-runtime`

## 1. GREP
* **Definition:**
  * The `grep` command is used to search for text that matches a pattern. Grep will search for a specified pattern line by line in a given file(s) or from the output of a command when using the pipe. You should use grep any time you need to read a file line by line in search of a given string. For example:
  * John needs a list of all email addresses in a csv file that are gmail.com

* **Usage:**<br>
  * With a file(s)
    * `grep` + `option` + `search string` + `file(s)`
  * With the pipe
    * `command` + `|` + `grep` + `option`
* **Basic Examples:**
* Get a list of all the users in a csv file whose email address domain is email.com:
  * `grep -i "email.com" users.csv`
* See [Handling Text Files Part 2 - GREP](https://rapurl.live/s6t) for more examples.

## 2. AWK
* **Definition:**
  * Awk is a scripting language used for processing and displaying text. Awk can work with a text file or from standard output.
* **Usage:**
  * `awk` + `options` + `{awk command}` + `file` + `file to save (optional)`
* **Basic Examples:**
  * Print the first column of every line of a file
    * `awk '{print $1}' ~/Documents/Csv/cars.csv`
  * See [Handling Text Files Part 2 - AWK](https://rapurl.live/olv) for more examples

## 3. SED
* **Definition:**
  * SED is a stream editor that performs operations on files and standard output. For instance, it can search, find and replace, insert, and delete. By using SED, you can edit files without opening them
* **Usage:**
  * `sed` + `options` + `sed script` + `file `
* **Basic Examples:**
  * Print the first column of every line of a file
    * `awk '{print $1}' ~/Documents/Csv/cars.csv`
  * See [Handling Text Files Part 2 - SED](https://rapurl.live/qtu) for more examples

## 4. Redirect STDIN/STDOUT/STDERR (>,>>)
We can redirect the input and output of commands to and from files, as well as connect multiple commands into powerful command pipelines. This works because commands generate two types of output: Standard output and Standard error. Since everything in Linux is a file, these programs send their output to a file called STDOUT and error messages to STDERR. These files are linked to the screen by default, which means that they are not saved into a file but instead displayed in the terminal. Input is sent to STDIN and is attached to the keyboard in the same way that STDOUT and STDERR are attached to the display by default.

### How to save the output of a command to a file?
This is achieved by using the `>`. This will overwrite the content of the file, and if the file does not exist, it will create it. 

**Examples:**
* Get a list of all the users in a csv file whose email address domain is email.com  and save it to a file named: `email.com_users.csv`
  * `grep -i "email.com" users.csv > email.com_users.csv`


### How to append the output of a command to a file?
In the case where you do not want to overwrite the content of a file, you can use `>>` to append the output of a command to a file. 

**Examples:**
* Get a list of all the users in a csv file whose email address domain is gmail.com  and append it to the file: `email.com_users.csv`
  * `grep -i "email.com" users.csv >> email.com_users.csv`

### How to save the error of a command to a file?
To append the error output of a command use: `2>`.

**Examples:**
* Get a list of all the users in a csv file whose email address domain is outlook.com  and append it to the file: `email.com_users.csv. If the file users.csv does not exist, save the error in a file called: error.log.`
  * `grep -i "email.com" users.csv >> email.com_users.csv 2> error.log`

### How to save the output and error of commands to a file?

### Some tips and tricks

## 5. Working with Pipes

## Exercise 1
A server log file `auth.log` contains thousands of entries. Each failed login attempt includes the phrase Failed password. Extract all failed login attempts and save them into a file called `failed_logins.txt`




## 6. Aliases

## 7. Pager Programs