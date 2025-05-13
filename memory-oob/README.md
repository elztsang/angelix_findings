# memory-oob
To run this repair, execute this command in `tests\memory-oob`:\
`angelix src test.c oracle 1 2 3 --assert assert.json --defect guards --synthesis-level extended-inequalities`

This was a simple practice see if/how angelix can infer bounds.

The intended behavior of the program is simple. If the input is within bounds of the static array (size 10), return the element at the specified index. Else, return -1 to indicate an invalid access.

Angelix generated upper bound fixes depending on the test case instead of the array size. To be fair, I did not define a variable for the size of the array, but it still would have use constants since the size of the array is static. Basically, angelix cannot infer that the output depends on the size of the array, if the size of the array is not meaningful (we don't really use it at all).

For the first patch, test case 3 inputted 11. This told the repair program: "When the input is 11, the program should return -1." Logically, it made a repair based on that constant: `(! (x >= 10))` which is the same as `(x < 10)`. And this *does* follow the bounds of the array...but only because the test case conveniently matched the array bounds.

This leads to the current test case 3, with an input of 100, to generate the fix `(! (x >= 99))`. Even if I added an additional test case, it wouldn't help, only lower the constant depending on the test case.

Also, I'm not sure why, but running the same command multiple times for the same test cases results in different repairs. I've also gotten `(! (100 == x))` and `(99 > x)`. I suppose there is something about angelix that does not make its repair process strict as to always result in the same outcome?
