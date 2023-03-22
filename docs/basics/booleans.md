## Booleans
Motion uses ```true``` and ```false``` for booleans.
Booleans can be evaluated with the following operators:
 * "==" Equals
 * "<"  Less Than
 * ">"  Greater Than
 * "<=" Less Than or Equal
 * ">=" Greater Than or Equal
 * "!"  Not
 * "&&" And
 * "||" Or

These operators can be combined and used anywhere a boolean is expected (see [control structures](https://github.com/UPWRD1/motionLang/blob/main/docs/basics/control%20structures)).

```
if ((x = 3) || ((x >= 10) && (x != 7))) {
    print "Successful"
}
