# memory-param
To run this repair, execute this command in `tests\memory-param`:\
`angelix src test.c oracle 1 2 3 4 5 6 --assert assert.json --defect if-conditions --synthesis-level mixed-conditional`

After the trying the memory-oob experiment, I wanted to get angelix to infer the size of the array as bounds. This meant I had to do something meaningful with the array size instead of leaving it static, and I decided to make it a variable length.

This experiment made me realize, again, the importance of choosing test cases and their effects on repair. While seemingly a simple repair, it took a lot of trial and error to get the program to understand the intended behavior of the program, which we need to provide with test cases.

When I first was building my test cases, I knew I needed these:
- array access less than 0
- array access greater than the size of the array
- array access greater than 0 and less than the size of the array

I only used one test case that was "passing AND success" (as in, it was within the bounds). This resulted in angelix generating repairs with the upper bound as a constant of that test case instead of a variable.

For example, test case 1 creates an array of size 7 and accesses index 2. This passes the original program since 2 is non-negative, but it also follows the intended behavior of accessing an index within specified bounds (size = 7).

Since I had no other test case satisfying these constraints, the repair program did what it was supposed to, with the information provided: "When x == 2, this test case passes." What ended up happening was the repair used 2 as it's repair case.\
Therefore, I had to create another "in-bounds" test case (#6) to have angelix infer the relationship between the array size and the index.\
You can see this in the image below.\
![alt text](https://github.com/elztsang/angelix_findings/blob/main/memory-param/constant_example.png)

This resulted in the final intended repair [here](https://github.com/elztsang/angelix_findings/blob/main/memory-param/src-2025-Apr19-074942.patch) which was a huge success!

### notes
I think I made more test cases than were "necessary" for a correct fix since I kept making additional tests in "hope" that the program would be repaired. It may be worth trying to design an efficient test suite standard to avoid this in the future. This could be beneficial for when we need to generate test cases based on eBPF verifer error logs.
