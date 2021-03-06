
<div align="center">

# Monty

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python)

</div>

## π Table of Contents

- [Monty](#monty)
	- [π Table of Contents](#-table-of-contents)
	- [π§ About](#-about)
		- [The Monty language](#the-monty-language)
	- [π Getting Started](#-getting-started)
		- [Prerequisites](#prerequisites)
		- [Compiling](#compiling)
	- [π Usage](#-usage)
	- [βοΈ Author](#οΈ-author)
	- [Reference](#reference)

## π§ About

### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## π Getting Started

clone the repo and follow the instructions below

### Prerequisites

This project only requires gcc 4.8.4

check your version with

```c
gcc -v
```

### Compiling

clone the repo and run

```c
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## π Usage
After compiling you can run

```c
./monty <filename>
```

to interpret any file containing monty bytecode

## βοΈ Author

- [@travis1999](https://github.com/travis1999)

## Reference

- `push` - pushes an element to the stack
- `pall` - prints all the values on the stack, starting from the top of the stack.
- `pint` - prints the value at the top of the stack, followed by a new line.
- `swap` - swaps the top two elements of the stack.
- `add`  - adds the top two elements of the stack.
- `nop`  - doesnβt do anything.
- `pop`  - removes the top element of the stack.