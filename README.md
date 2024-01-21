# Interpreter for Monty ByteCodes files.

A simple interpreter for Monty ByteCode files written in C. It reads a bytecode file line by line and executes the bytecode commands on a Stack or Queue.

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language.
There can not be more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

## Getting Started

You can start by cloning this repo into your machine by following these commands:

```bash

git clone https://github.com/AhmadYousif89/monty
cd monty

```

All files were compiled on Ubuntu 20.04 LTS using the __GCC__ compiler with the following options:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

so make sure you have the gcc compiler installed.

To run the program simply type:
 ```bash
./monty <monty file>
```

### Available operation codes:


|__Opcode__|__Description__|
|:---------|:-------------:|
|stack     |An opcode that sets the insertion mode to a Stack (LIFO). This is the default behavior.|
|queue     |An opcode that sets the insertion mode to a Queue (FIFO).|
|push      |Pushes an element onto the stack. e.g (push 1 onto the stack)|
|pint      |Prints the value at the top of the stack.|
|pall      |Prints all the values on the stack, starting from the head of the stack.|
|pop       |Removes an element from the stack or queue.|
|nop       |This opcode doesn't do anything.|
|swap      |Swaps the top to elements of the stack.|
|add       |Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.|
|sub       |Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|div       |Divides the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|mul       |Multiplies the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|mod       |Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|pchar     |Prints a character representation for the number stored in the top node of the stack. e.g (H)|
|pstr      |Prints a string representation of all the numbers stored in the stack from the top. e.g (olleH)|
|prevs     |Prints a string representation of all the numbers stored in the stack in reverse order. e.g (Hello)|
|rotl      |Rotates the stack from top to bottom.|
|rotr      |Rotates the bottom of the stack to the top of the stack.|
|# 	       |Lines that starts with the (#) symbol will be trated as a comment.|
|//	       |Lines that starts with the (//) symbol will be trated as a comment.|


### Examples

To test the monty interpreter create a text file that contain the bytecode operations then save the file with the extension __(.m)__.
Here is an example of a __test.m__ file that contains the following opcodes:

![m1](https://github.com/AhmadYousif89/monty/assets/90717578/acff510a-d8ad-4d3e-a0e2-c46f11d6baf4)


and the output on the terminal will look like this:


![m2](https://github.com/AhmadYousif89/monty/assets/90717578/c1e1130f-3d59-483b-a7d1-a22080b72d71)

more opcode tests:

![mi2](https://github.com/AhmadYousif89/monty/assets/90717578/2cfa1474-fe75-4b7e-9365-3e17e5d6596b)

and the results are

![mo2](https://github.com/AhmadYousif89/monty/assets/90717578/b8284aac-73b2-4a34-9ac7-478411600f9d)


#### Aurthor

[Ahmad Yousif](https://github.com/AhmadYousif89)
