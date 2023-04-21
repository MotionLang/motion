# Getting Started with Motion
## Part 1: Welcome and Installation

## Intro
Welcome! If you are reading this, then you are on the path to start developing with Motion. In this guide, you will learn the basics of installing, running, and programming in Motion.

---

## Installation
Motion is available for download as a precompiled binary, or you can compile from source.

### Compiling from source
If you have the Official Github CLI, you can clone the repo using

`gh repo clone UPWRD1/motionLang`

If you wish to use git, run 

`git clone https://github.com/UPWRD1/motionLang`

Alternatively, download the zip file, and extract.

Once you have a copy of the repository, run `make` in a terminal. 
This will build the most recent version of Motion.

> In order to make it easier to use Motion, consider adding the executable to your path. If you are on a unix system, and in the Motion directory, run this: 
> `export PATH=$PATH:/workspaces/motion/bin/` in a terminal to add Motion to your path. 
> If you do this, remember to run `motion` instead of `bin/motion`.

To confirm your install of motion, run `bin/motion --info`. If something like this appears,

```
Motion v1.0.0

Motion is licensed under GPLv3. See https://www.gnu.org/licenses/gpl-3.0.en.html for more information.

Type -h for help.
```
then congratulations. You have sucessfully installed Motion!

---

## Hello World
To launch the REPL, either run `bin/motion` or, if you have added Motion to your path, `motion`. This will launch a Dynamic Read-Eval-Print-Loop (REPL), for you to explore, which looks like this:
```
Motion v0.0.5
Ctrl-C to Exit

~> 
```
In keeping with tradition, your first program will be a simple, "Hello world!". You do not need to type the `~>` in the REPL.
```
~> print "Hello World!";
Hello World!
```

Notice the optional parentheses around the `print` statement. This is because `print` is a keyword, not a function.
> The version numbers of your install of Motion may be different. However, this is fine for our purposes.

If you recieve an error, check your code to make sure that your code matches the example. 

## [Next ~>](motion/docs/Getting_Started/basics/variables.md)
