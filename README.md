README: 
# R-FORTH Interpreter
This is a simple R-FORTH interpreter implemented in C.
## Usage
1. Clone the repository:
2. git clone https://github.com/zeropegasus/CredentialDancersFORTH
3. cd R-FORTH
4. Make
5. ./build/bin/R-FORTH

## Commands:

define <word> <commands>: Define a new word with a sequence of commands.

<number>: Push a number onto the stack.

+, -, *, /, %: Arithmetic operations.

>, <, =: Comparison operations.

&, |, !: Logical operations.

push <number>: Push a number onto the stack.

pop: Pop the top element from the stack.

dup: Duplicate the top element on the stack.

swap: Swap the top two elements on the stack.

over: Duplicate the second element on the stack.

rot: Rotate the top three elements on the stack.

drop: Remove the top element from the stack.

2swap: Swap the top two pairs of elements on the stack.

2dup: Duplicate the top two elements on the stack.

2over: Duplicate the second pair of elements on the stack.

2drop: Remove the top two pairs of elements from the stack.

divmod: Push the quotient and remainder of the division of the top two elements onto the stack.

