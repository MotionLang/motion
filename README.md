# Motion

Motion is a dynamically typed general purpose programming language designed to help developers write fast, clean, and efficient code for a modern world.

Motion is created in pure ANSI C, with no dependancies.

Motion is a variation of the Lox language found at www.craftinginterpreters.com and is licensed under GNU GPL v3.0.

## Syntax

Motion's syntax aspires to be fresh, readable, and clean.

```
## Comments are cool.

var x; ## Declared variables are set to nil.
var y = 10; var z = 2;

## ^^^^ Multiline statements with ";"

print x * y;

func add(a, b) {
	var new = (a + b);
	print new;
	return new;
}

```

For more examples, see ```/examples```

## Contribution

Motion is still in development. As such, I want to implement the basics as a solo project before others help. Please wait for version one before creating requests.

However, more tests are always welcome. 
To add a new test, fork the repository. Then, update  [```test.py```](tests/test.py) found in ```/tests```, and submit a pull request.

## Features

Motion supports (or will support):

* :heavy_check_mark: Dynamic Typing
* :heavy_check_mark: First Class Functions & Closures
* :heavy_check_mark: Logical & Arithmetic Operators
* :heavy_check_mark: Loops
* :heavy_check_mark: Variables and scope
* :heavy_check_mark: Comments
* And more! (hopefully)

## Compiling

If you want to compile, first clone the repo using:

### Git:
	git clone https://github.com/UPWRD1/motionLang.git
	
### Github CLI:
	`gh repo clone UPWRD1/motionLang`

Then, use the following command:




After compilation, run

`
build/motion
`
in a terminal.

Makefile suppport coming soon.
