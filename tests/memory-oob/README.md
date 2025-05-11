`angelix src test.c oracle 1 2 3 --assert assert.json --defect guards --synthesis-level extended-inequalities`

This was a simple practice see how angelix can infer bounds.

What is interesting is that, angelix generated upper bound fixes depending on the test case. 

Angelix cannot infer that the bounds depends on the size of the array (if the array was created with malloc, it would throw an error. I'm not sure how that would affect the repair.)