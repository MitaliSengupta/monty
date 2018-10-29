# Monty Language Interpreter
## About
- This is an introductory project that explains:
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables
- How to work with git submodules
---

## Requirements
- Ubuntu 14.04 LTS
- GCC version 4.8.4 with flags: -Wall -Werror -Wextra and -pedantic
---

## Installation
1. Clone the repository
`https://github.com/mitalisengupta/monty.git`

2. Compile the program
`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

3. Run the program as follows:
- Usage: `monty <file.m>`
- Ex: `./monty ./bytecodes/00.m`

There are multiple `.m` files to choose from in the bytcodes files that run different Opcode functionality. Below is a table of all the Opcode options. Each file in the bytcodes folder contains different Opcodes that run their specific functionality.

| Opcode Name   | Opcode Description |
| :-----------: | :------------------- |
| push          | *pushes an element on to the stack* |
| pall          | *prints all the values on the stack, starting from the top* |
| pint          | *prints the value at the top of the stack* |
| pop           | *removes the top element of the stack* |
| swap          | *swaps the top two elements of the stack* |
| add           | *adds the top two elements of the stack* |
| nop           | *doesn't do anything* |
| sub           | *subtracts the top element of the stack from the second top element of the stack* |
| div           | *divides the second top element of the stack by the top element of the stack* |
| mul           | *multiplies the second top element of the stack with the top element of the stack* |
| mod           | *computes the modulus of the second top element of the stack by the top element of the stack* |
| comments (#)  | *add a # to the beginning of the line to comment in the file* |
| pchar         | *prints the ASCII equivalent of the number at the top of the stack* |
| pstr          | *prints the ASCII equivalent of the numbers stored in each element in the stack, starting from the top* |
| rotl          | *rotates the top element of the stack to the bottom of the stack* |
| rotr          | *rotates the bottom element of the stack to the top of the stack* |

---

## Example
```
Pandora666$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
Pandora666$ ./monty ./bytecodes/000.m
3
2
1
0
6
5
4
3
2
1
0
Pandora666$
---
```
## Other files

- monty.h - *Header file; Contains function, struct and global variable declarations*
- bytecodes - *A directory containing test files used while making this program*
---
   
### Technologies Used
* Language: C
* Operating System: Ubuntu 14.04 LTS (Trusty64)
* Style: [Betty](https://github.com/holbertonschool/Betty)
* Compiler: GCC
---

### Author
Mitali Sengupta

<img src="http://pluspng.com/img-png/twitter-png-file-png-image-200.png" width=2% height=2%/> [@aadhibangalan](https://twitter.com/aadhibangalan) 

<img src="https://assets-cdn.github.com/images/icons/emoji/octocat.png" width=2% height=2%/>[MitaliSengupta](https://github.com/MitaliSengupta)
