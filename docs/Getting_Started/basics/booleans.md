# Booleans and Atoms
## Atoms
There are three Atom types in Motion: `true`, `false`, and `nil`.

## Booleans
Motion uses ```true``` and ```false``` for booleans.
Booleans can be evaluated with the following operators:
 * `==` Equals
 * `<`  Less Than
 * `>`  Greater Than
 * `<=` Less Than or Equal
 * `>=` Greater Than or Equal
 * `!`  Logical `Not`
 * `and` Logical `And`
 * `or` Logical `Or`

These operators can be combined and used anywhere a boolean is expected (see [control structures](https://github.com/UPWRD1/motionLang/blob/main/docs/basics/control%20structures)).

```
if ((x = 3) or ((x >= 10) and (x != 7))) {
    print "Successful"
}
```

## Nil
Nil, or null, represents "no value". It is not `false`, or `0`. It is its own type, and is not equivilent to anything, except another `nil`.

Variables which are declared without an initial assignent are automatically set to `nil`.
```
~> var x; 
~> print x;
nil
```
> **Why nil, and not null?**
> The Motion compiler and VM is written in C. `Null` is a keyword in C, while `nil` is not. In order to ease the development of Motion, `nil` was chosen to avoid confusing the two.

