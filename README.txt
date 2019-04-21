~~~~~~~~~~~~~~~~~~~~~~
author: jonathan pham
cs4280 program translation
p0 due 03/01/2018
~~~~~~~~~~~~~~~~~~~~~~
I decided to write the program in C. All tasks for P0 are achieved!
~~~~~~~~~~~~~~~~~~~~~~
***How to run program***
~~~~~~~~~~~~~~~~~~~~~~
after creating executing file 'p0' via 'make', run the program as follows:

1) ./p0 [filename] // filename is an optional argument

**note that I included input.file1 in my directory for testing with contents
verbatum to our lecture**

2) ./p0 // read from keyboard until simulated EOF, then CTR+D

3) ./p0 < file // redirects from file 

the program will run for any of the above options and will output preorder, inorder, postorder
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Traversals are written in corresponding functions
1) printInorder()
2) printPreorder()
3) printPostorder()
4) buildTree()

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
makefile written using Suffix rules
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
