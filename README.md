# Simple Shell
----
!["Holberton Logo"](https://www.holbertonschool.com/holberton-logo-twitter-card.png)

## What is Simple shell?

This is a simple implementation of  command-line interpreter for the Unix operating system created by holberton students **Nildiert Jimenez** and **Ricardo Gutierrez**. 

See [Unix Shell](https://en.wikipedia.org/wiki/Unix_shell)

----
## Learning objetives
* Who designed and implemented the original Unix operating system.
* Who wrote the first version of the **UNIX** shell
* Who invented the B programming language (the direct predecessor to the C programming language).
* Who is [Ken Thompson](https://github.com/kyeeh/simple_shell).
* How does a shell work .
* What is a **pid** and a **ppid**.
* How to manipulate the environment of the current process.
* What is the difference between a function and a system call.
* How to create processes.
* What are the three prototypes of main.
* How does the shell use the **PATH** to find the programs.
* How to execute another program with the execve system call.
* How to suspend the execution of a process until one of its children terminates.
* What is **EOF** / “end-of-file”?

----
## Requirements

* All your files will be compiled on **Ubuntu 14.04 LTS**.
* Your C programs and functions will be compiled with **gcc 4.8.4** using the flags *-Wall -Werror -Wextra and -pedantic*.
* All your files should end with a new line.
* Your code should use the [Betty style](https://github.com/holbertonschool/Betty/wiki).
* No more than 5 functions per file.
* All your header files should be include guarded.
* Use system calls only when you need to.

----
## Files incluided in this repository
File |  Description
------------ | -------------
README.md | README file
cmd_utils.c |  Functions of previous projects
error_handler.c | Management errors
exec.c | File that execute the functions of the OS system
exec_buil_comm.c | File that execute the builtins functions
exit.c | Function of exit
find_path.c | Find the path 
fork.c | Create a new proccess
history.c | Create a history and add nodes
man_1_simple_shell | manpage
parser.c | Split the input
prompt.c | Receives the string of characters
shell.c | Content the main function
shell.h | Header file
stat.c | Verify the status of a command in the system
utils.c | Strings functions

----
## Quick start

### Basic Installation
simple_shell is installed by running the following commands in your terminal.

    git clone https://github.com/kyeeh/simple_shell.git

After that simple_shell can compile using

    gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell

To start, write the following:

    ./simple_shell

----
## Basic operation
When the shell reads the entry, it proceeds through a sequence of operations.

    ls -la

In general terms, the shell reads your entry and divides it into words and operators

ls | -la
------------ | -------------

The shell then analyzes these tokens in commands and other constructs, redirects the input and output as needed, executes the specified command, waits for the output state of the command, and makes that output status available. for further inspection or processing.

    total 88
    drwxrwxr-x  3 vagrant vagrant  4096 Apr 12 18:35 .
    drwxr-xr-x 10 vagrant vagrant  4096 Apr 12 18:35 ..
    drwxrwxr-x  8 vagrant vagrant  4096 Apr 12 18:35 .git
    -rw-rw-r--  1 vagrant vagrant     7 Apr  7 23:28 .gitignore~
    -rw-rw-r--  1 vagrant vagrant    28 Apr  7 23:07 README.md
    -rw-rw-r--  1 vagrant vagrant   806 Apr 12 12:26 error_handler.c
    -rw-rw-r--  1 vagrant vagrant   304 Apr 12 12:26 exec.c
    -rw-rw-r--  1 vagrant vagrant   749 Apr 12 12:26 fork.c
    -rwxrwxr-x  1 vagrant vagrant 13639 Apr 10 21:27 hsh
    -rw-rw-r--  1 vagrant vagrant   806 Apr 12 12:26 prompt.c
    -rw-rw-r--  1 vagrant vagrant   513 Apr 12 12:26 read_line.c
    -rw-rw-r--  1 vagrant vagrant   827 Apr 12 12:26 shell.c
    -rw-rw-r--  1 vagrant vagrant   680 Apr 12 12:26 shell.h
    -rw-rw-r--  1 vagrant vagrant   258 Apr 12 12:26 stat.c
    -rwxrwxr-x  1 vagrant vagrant 13966 Apr 12 12:26 test
    -rw-rw-r--  1 vagrant vagrant   161 Apr 12 12:26 util.c


----
## Builtin functions
Function | Description | Usage
------------ | ------------- | -------------
env | Show the environment variables |     To show the environment variables

----
## Examples
### Interactive Mode

    $ cat test_ls_2
    /bin/ls
    /bin/ls

### Non-Interactive Mode

    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2

----
## changelog
* 12-Apr-2019 Creation

----
## Contributors
* [Nildiert Jimenez](https://github.com/nildiert)
* [Ricardo Rodriguez](https://github.com/kyeeh/simple_shell)
