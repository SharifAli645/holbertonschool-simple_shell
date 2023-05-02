# Simple shell

![Portada de shell](https://dotrungquan.info/wp-content/uploads/2021/07/shell-script.jpeg)

## Table of Contents
1. [General Info](#general-info)
2. [Installation](#installation)
3. [Description of File Structure](#description-of-file-structure)
4. [Example Command](#example-command)
5. [Authors](#authors)

## Table of Contents

## General Info
***
The Simple Shell is a simple UNIX command interpreter written entirely in C. The program runs based on bash commands obtained from the command line interface (CLI) given by the user. The respective command typed by the user is then parsed and executed as if in a regular UNIX shell.

## Installation
***
```
$ git clone git@github.com:SharifAli645/holbertonschool-simple_shell.git
$ cd holbertonschool-simple_shell
```
Compile it with:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
Interactive mode:

```
$ ./hsh
```

Non-interactive mode:

```
$ echo "ls -la" | ./hsh
```

## Description of File Structure

Contains a brief description of the working files of the project.

1. [build.c](build.c)
  * ``builtin_function()`` - function that checks if the command is a built-in:
  * ``exit_builtin()`` - function that execute 'exit' built-in:
  * ``env_builtin()`` - function that prints the environment:
2. [environ.c](environ.c)
  * ``_getenv()`` - function that gets the environment value from a env. variable:
  * ``get_location()`` - function that locates the command path:
3. [func_strings.c](func_strings.c)
  * ``_atoi()`` - functions that converts a string to an integer:
  * ``_strlen()`` - counts characters:
  * ``_strcmp()`` - function that compares two string:
  * ``_strdup()`` - function that returns a pointer to a:
  * ``_strcat()`` - function that concatenates two strings:
4. [hand_strings.c](hand_strings.c)
  * ``_memcpy()`` - function that copies memory area:
  * ``_strcpy()`` - function that copies one source string to a array:
5. [simple_shell.c](simple_shell.c)
  * ``(eval_fork)`` - function that receives the child and father:
  * ``(eval_token)`` - function that is in charge of tokenization:
  * ``(sig_handler)`` - function that print prompt:
  * ``(main)`` - main function:
5. [spaces.c](spaces.c)
  * ``(only_spaces)`` - function that evaluates blanks:
6. [AUTHORS](AUTHORS) - List of contributors.
7. [man_1_simple_shell](man_1_simple_shell) - Basic manual page.

## Example Command

**Example 1**
```
$ ./hsh
#code: pwd
/root/holbertonschool-simple_shell
#code: ls
AUTHORS  environ.c       hand_strings.c  main.h                  README.md       spaces.c
build.c  func_strings.c  hsh             man_1_simple_shell.swp  simple_shell.c  test
#code: exit
$
```
**Example 2**
```
$ echo "ls" | ./hsh
AUTHORS  environ.c       hand_strings.c  main.h                  README.md       spaces.c
build.c  func_strings.c  hsh             man_1_simple_shell.swp  simple_shell.c  test
```

## Authors
| [<sub> Guillermo Alvarado </sub>](https://github.com/Sonnydread) | [<sub> Sharif Abuhadba </sub>](https://github.com/SharifAli645) | [<sub> Johana Herrera </sub>](https://github.com/Johana-RHP) |
| :---: | :---: | :---: |
