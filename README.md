# evalexpr
Arithmetic expression evaluator handling both standard notation and reverse polish notation (RPN).
## Project Description
This project was made after two weeks on learning in C during my third year (ING1) at EPITA. Made in rouglhy two days it has the purpose to evaluate arithmetic expression, which is then displayed on stdout and returns the error code.
## Makefile
- Produces the 'evalexpr' binary
```sh
make all 
```
- Runs the testsuite
```sh
make check
```
- Deletes everything produced by make
```sh
make clean
```
## Error handling
If any error occurs, nothing will be printed on stdout.
- 0, No error (or empty input).
- 1, Lexical error.
- 2, Syntax error.
- 3, Arithmetical error (division or modulo by 0, negative power)
- 4, Any other error
## How to use
The program can either be called with no argument and handle infix notation or with -rpn and handle
RPN. All other arguments are invalid.
```sh
echo "1 + 1" | ./evalexpr
```
```sh
echo "5 2 2 ^ 3 + *" | ./evalexpr -rpn
