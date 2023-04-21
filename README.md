# Motion ↗️:

Motion is a dynamically typed general purpose programming language designed to help developers write fast, clean, and efficient code for a modern world.

Motion is created in pure ANSI C, with no dependancies.

Motion is a variation of the Lox language found at www.craftinginterpreters.com and is licensed under GNU GPL v3.0.

## Syntax

Motion's syntax aspires to be fresh, readable, and clean.

```python
## Comments are cool.

var x; ## Declared variables are set to nil.
var y => 10; var z => 2;
## ^^^^ Multiline statements with ";"

print x * y;

func add(a, b) => {
	var new => (a + b);
	print new;
	return new;
}
```

For more examples, see [examples](/example)

## Why Motion?
* ###  :rocket: Motion is Speedy.
	- On benchmarks, Motion is almost twice as fast as a similar python program!
* ### :bulb: Motion is Simple.
	- Motion has a familiar, welcoming syntax. Everything "just works".
* ### :lock: Motion is Safe.
	- A secure bytecode VM and JIT Compiler means safety issues are far and few.
* ### :floppy_disk: Motion is Small.
	- No external dependancies and pure C means Motion is tiny, fitting at 130KB. That's small enough to fit on a floppy disk!

## Contribution
See [Contribution](docs/Getting_Started/contributing.md)

## Features
Motion supports (or will support):

* :heavy_check_mark: Dynamic Typing
* :heavy_check_mark: First Class Functions & Objects
* :heavy_check_mark: Logical & Arithmetic Operators
* :heavy_check_mark: Loops and Control Flow
* :heavy_check_mark: Scoped Variables
* :heavy_check_mark: Closures
* :heavy_check_mark: Classes, Superclasses, & Inheritance
* And more! (hopefully)

## Are you Ready to get Moving?
See [Getting Started](docs/Getting_Started/Installation.md)
