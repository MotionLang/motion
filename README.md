# Motion

Motion is a dynamically typed general purpose programming language designed to help developers write fast, clean, and efficient code for a modern world.

Motion is created in pure C, with no dependancies.

Motion is a variation of the Lox language found at www.craftinginterpreters.com.

Motion is licensed under GNU GPL v3.0.

## Syntax

Motion's syntax aspires to be fresh, readable, and clean.

```motion
## Comments are cool.

var: x; ## Declared variables are set to nil.
var: y = 10; var: z = 2;

## ^^^^ Multiline statements with ";"

print x * y;

```

For more examples, see ```/examples```

## Contribution

Motion is still in development. As such, I want to implement the basics as a solo project before others help. Please wait for version one before creating requests.
Otherwise, support of any kind is welcome!

## Features

Motion supports (or will support):

* Dynamic Typing
* First Class Functions & Closures
* Classes
* Automatic Memory Management with Garbage Collection
* Logical & Arithmetic Operators
* While Loops
* And more! (hopefully)

## Compiling

If you want to compile, first clone the repo.

Then, use the following command:

```bash
gcc  -fdiagnostics-color=always -g -Wall *.c -o output
```

Alternatively, in vscode, use the ```tasks.json``` file found in ```./vscode```.

After compilation, run

```bash
build/output
```

in a terminal.

Makefile suppport coming soon.
