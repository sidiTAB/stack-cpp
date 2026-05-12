# Stack — Array Implementation in C++

A menu-driven program implementing the stack ADT on a fixed-capacity array, with two applications: string reversal and parenthesis balancing.

## Operations
- `push`, `pop`, `peek`, `display` — handled by a `Stack` class
- `reverseString` — reverses a word by pushing each character then popping them back
- `checkParentheses` — verifies that `()`, `[]` and `{}` are correctly matched in an expression

Overflow and underflow are checked before every write or read.

## Build & run
```bash
g++ stack.cpp -o stack
./stack
```

On Windows:
```bash
g++ stack.cpp -o stack.exe
stack.exe
```

## Menu
```
1. Push
2. Pop
3. Peek
4. Display
5. Reverse a word
6. Check parentheses
7. Exit
```

## Course
COM206 — Data Structures
