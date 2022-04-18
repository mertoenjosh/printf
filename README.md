# 0x10. C - printf

# Description.

This is a team project
Expectation :
.How to use git in a team setting
.Applying variadic functions to a big project
.The complexities of printf
.Managing a lot of files and finding a good workflow

# prototype

    int _printf(const char *format, ...);

# usage

.Prints a string to the standard output, according to a given format
.All files were created and compiled on Ubuntu 14.04.4 LTS using GCC 4.8.4 with the command gcc -Wall -Werror -Wextra -pedantic \*.c
.Returns the number of characters in the output string on success, -1 otherwise
.Call it this way: \_printf("format string", arguments...) where format string can contain conversion specifiers and flags, along with regular characters

# Tasks

These are all the tasks of this project, the ones that are completed link to the corresponding files.

0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
   Write a function that produces output according to format.
   c : converts input into a character
   s : converts input into a string

1. Education is when you read the fine print. Experience is what you get if you don't
   Handle the following conversion specifiers:
   d : converts input into a base 10 integer
   i : converts input into an integer

2. Just because it's in print doesn't mean it's the gospel
   Create a man page for your function
