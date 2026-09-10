## What will you learn

* Learn how to search for specific text patterns using `grep`
* Practice extracting and displaying specific columns of data using `awk`
* Learn how to modify and replace text using `sed`
* Develop the ability to process structured text files from the Linux terminal
* Practice combining multiple text-processing commands to solve real-world problems

## Complete these instructions before starting this activity
1. In your home directory, clone this repository so you can have all the necessary files: `https://github.com/linuxworkshop67/handling_text2`
2. Update your system using the command: `sudo apt update && sudo apt upgrade`
3. Install the packages: `rig`, `bat`, `uuid-runtime` using the command: `sudo apt install rig bat uuid-runtime`****
4. Run the following command to generate the files we will use in this activity. These files are the same files used in Lab 8 and in the presentations Handling Text Files Part 1 and Handing Text Files part 2. If you have already run these commands, skip this section. You can check if you have the file by listing the directory `~/Documents/sample_files`. If the ls command returns an error message, you do not have the files.
```bash
cd ~/Documents/ && git clone https://github.com/linuxworkshop67/sample_files
```

## GREP
* **Definition:**
  * The `grep` command is used to search for text that matches a pattern. Grep will search for a specified pattern line by line in a given file(s) or from the output of a command when using the pipe. You should use grep any time you need to read a file line by line in search of a given string. 
  * For example:
	  * John needs a list of all email addresses in a `csv` file that are gmail.com

* **Usage:**
  * With a file(s)
    * `grep` + `option` + `search string` + `file(s)`
  * With the pipe
    * `command` + `|` + `grep` + `option`
* **Basic Examples:**
	* Get a list of all the users in a `csv` file whose email address domain is email.com:
	  * `grep -i "email.com" users.csv`
	* See [Handling Text Files Part 2 - GREP](https://rapurl.live/s6t) for more examples.
### Grep Exercises
#### Problem 1
A technician is reviewing a web server log and wants to find every occurrence of the word error. The log contains different capitalization such as `ERROR`, `Error`, and `error`. The technician also wants to know the line number of each match. Use the file: `logs.log` to complete this task.
<br>
**General Steps to solve it***
1. Open the terminal.
2. Move to the directory containing the log file.
3. Search for the word error.
4. Ignore capitalization differences.
5. Display line numbers.

> Solution IMAGE goes here
> `grep -ni 'error' logs.log`


<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('grep_practice1');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.

#### Problem 2
A technician performed a network scan to discover devices connected to the local network using: `nmap -sP 192.168.1.0/24` (You do not need to run this command).  The output of the command has been saved to the file: `nmap_output.txt`. The scan generated a report containing host names, IP addresses, and status information. The technician only wants to display the lines that contain IPv4 addresses so they can quickly identify the devices they discovered.

**General Steps to solve it***
1. Open the terminal.
2. Move to the directory containing the scan output file.
3. Display some of the lines in the file `nmap_output.txt` to understand its general structure
4. An IPv4 address is a 32-bit number represented in decimal form as four octets (e.g., 192.168.0.1). Each octet ranges from 0 to 255. Create a pattern that will allow you to match a string like an IPv4 address. See [here](https://docs.google.com/drawings/d/e/2PACX-1vRfCWNXM1Bs4ZKPEQwAxVreK939tZL7xZVo3m_3FiGbBQ-7idaxY0x0I6NH9_Dt_8eVjFvGc4wryK7L/pub?w=1440&h=1080) for a breakdown of the regular expression 
5. Search for lines that contain text in the format of an IPv4 address.
6. Display only the matching lines.

> Solution here
> `grep "[0-9]\+\.[0-9]\+\.[0-9]\+\.[0-9]\+" nmap_output.txt`

<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('grep_practice2');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>


> Take a screenshot of your terminal to submit later.

#### Problem 3
A Linux administrator has a list of user accounts. They want to display every account except the disabled accounts. The file name is `users.csv`.

**General Steps to solve it**
1. Open the terminal.
2. Move to the file location.
3. Exclude lines containing the word `disabled`.
4. Display all remaining lines.

> Solution
> `grep -v "disabled" users.txt`

<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('grep_practice3');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>


> Take a screenshot of your terminal to submit later.

#### Problem 4
A student has a configuration file and wants to number every line in the file so they can easily reference specific settings while troubleshooting. The file is called `settings.conf`.

**General Steps to solve it**
1. Open the terminal. 
2. Move to the directory containing the file. 
3. Match the beginning of every line. 
4. Display line numbers.

> Solution
> `grep -in "^" settings.conf`

<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('grep_practice4');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.

## AWK
* **Definition:**
  * Awk is a scripting language used for processing and displaying text. Awk can work with a text file or from standard output.
* **Usage:**
  * `awk` + `options` + `{awk command}` + `file` + `file to save (optional)`
* **Basic Examples:**
  * Print the first column of every line of a file
    * `awk '{print $1}' ~/Documents/Csv/cars.csv`
  * See [Handling Text Files Part 2 - AWK](https://rapurl.live/olv) for more examples

### Awk exercises
#### Problem 1
A technician exported a list of employees. The file contains employee IDs, names, and departments. The technician only wants to see employee names. Use the file `employees.txt` to solve this problem.

**General Steps to solve it**
1. Open the terminal.
2. Move to the directory containing the file.
3. Display only the second column.

> Solution 
> `awk '{print $2}' employees.txt`


<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('awk_practice1');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.

#### Problem 2
An instructor is reviewing a configuration file and wants to display each line with its line number. Use the file `settings.conf`

**General Steps to solve it**
1. Open the terminal.
2. Move to the file location.
3. Display each line along with its line number.

> Solution 
> `awk '{print NR, $0}' settings.conf`


<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('awk_practice2');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.

#### Problem 3
A professor has a grade report and wants to identify students who scored 90 or higher. Use the file `grades.txt` The professor also wants to get the class average.

**General Steps to solve it**
1. Open the terminal.
2. Move to the file location.
3. Examine the score column.
4. Display only students with scores of 90 or higher.

> Solution 
> `awk -F',' '$2 >= 90 {print $0}' grades.txt`
> `awk -F',' '{sum += $2} END {print sum/NR}' grades.txt`


<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('awk_practice3');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.


#### Problem 4
A store manager has a file containing sales amounts and wants to calculate the total sales for the day.

**General Steps to solve it**
1. Open the terminal.
2. Move to the file location.
3. Add the values from every line.
4. Display the final total.


> Solution 
> `awk -F',' '{sum += $2} END {print sum}' sales.txt`


<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('awk_practice4');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.

## SED
- **Definition:**
    - SED is a stream editor that performs operations on files and standard output. For instance, it can search, find and replace, insert, and delete. By using SED, you can edit files without opening them
- **Usage:**
    - `sed` + `options` + `sed script` + `file`
- **Basic Examples:**
    - Print the first column of every line of a file
        - `awk '{print $1}' ~/Documents/Csv/cars.csv`
    - See [Handling Text Files Part 2 - SED](https://rapurl.live/qtu) for more examples

### Sed exercises
#### Problem 1
A technician has a configuration file for `server01` which is running `NGINX`.  The company changed the `port`, and the technician wants to see what the file would look like after the change. Use the file `nginx.conf`

**General Steps to solve it**

1. Open the terminal.
2. Move to the directory containing the file.
3. Replace all occurrences of `listen 80` with `listen 8080`.
4. Display the result on the screen.

> Solution 
> `sed 's/listen 80/listen 8080/g' nginx.conf`


<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('sed_practice1');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.

#### Problem 2
A student received a CSV file that uses colons instead of commas. The student wants to display the file using commas. Use the file `users_and_ips.csv`

**General Steps to solve it**

1. Open the terminal.
2. Move to the file location.
3. Replace every colon with a comma.
4. Display the modified output.

> Solution 
> `sed 's/:/,/g' users_and_ips.csv`

<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('sed_practice2');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.

#### Problem 3
An administrator has a large configuration file and wants to display only line 5. Use `settings.conf`

**General Steps to solve it**
1. Open the terminal.
2. Move to the file location.
3. Select line 5.
4. Display only that line.

> Solution 
> `sed -n '5p' settings.conf`

<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('sed_practice3');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.

#### Problem 4
A student created a text file with extra blank lines. The student wants to display the file without the empty lines. Use the file line `notes.md`

**General Steps to solve it**
1. Open the terminal.
2. Move to the file location.
3. Remove empty lines from the output.
4. Display the cleaned text.

> Solution 
> `sed /^$/d notes.md`

<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('sed_practice4');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.


#### Problem 5
A Linux administrator wants to review only the active settings in a configuration file. Comment lines begin with the # character. Use the `apache2.conf` file.

**General Steps to solve it**
1. Open the terminal.
2. Move to the file location.
3. Remove lines that start with `#`.
4. Display only active settings.

> Solution 
> `sed '/^#/d' apache2.conf`

<button class="btn btn-primary fs-5 mb-4 mb-md-0 mr-2" name="SolutionShow" onclick="var x = document.getElementById('sed_practice5');if (x.style.display === 'none') {x.style.display = 'block';} else {x.style.display = 'none';}">Show Solution</button>

> Take a screenshot of your terminal to submit later.

#### Problem 6




### Redirect STDIN/STDOUT/SDERR (>,>>)
We can redirect the input and output of commands to and from files, as well as connect multiple commands into powerful command pipelines. This works because commands generate two types of output: Standard output and Standard error. Since everything in Linux is a file, these programs send their output to a file called STDOUT and error messages to STDERR. These files are linked to the screen by default, which means that they are not saved into a file but instead displayed in the terminal. Input is sent to STDIN and is attached to the keyboard in the same way that STDOUT and STDERR are attached to the display by default.

### How to save the output of a command to a file?
This is achieved by using the `>`. This will overwrite the content of the file, and if the file does not exist, it will create it. 

**Examples:**
* Get a list of all the users in a csv file whose email address domain is email.com  and save it to a file named: `email.com_users.csv`
  * `grep -i "email.com" users.csv > email.com_users.csv`
* See [Handling Text Files Part 2](https://rapurl.live/851) for more examples.

### How to append the output of a command to a file?
In the case where you do not want to overwrite the content of a file, you can use `>>` to append the output of a command to a file. 

**Examples:**
* Get a list of all the users in a csv file whose email address domain is gmail.com  and append it to the file: `email.com_users.csv`
  * `grep -i "email.com" users.csv >> email.com_users.csv`
* See [Handling Text Files Part 2](https://rapurl.live/851) for more examples.

### How to save the error of a command to a file?
To append the error output of a command use: `2>`.

**Examples:**
* Get a list of all the users in a csv file whose email address domain is outlook.com  and append it to the file: `email.com_users.csv. If the file users.csv does not exist, save the error in a file called: error.log.`
  * `grep -i "email.com" users.csv >> email.com_users.csv 2> error.log`
* See [Handling Text Files Part 2](https://rapurl.live/851) for more examples.
### How to save the output and error of commands to a file?
To append the successful output and error output of a command use: `&>` 

**Examples:**
* List all the files in home directory that match specific file extensions
	* `ls ~/*.sh ~/*.md &> all_output.txt`  
 * See [Handling Text Files Part 2](https://rapurl.live/851) for more examples.

### STDIN/STDOUT/SDERR Exercises

#### Problem 1

#### Problem 2

#### Problem 3

## Working with Pipes
