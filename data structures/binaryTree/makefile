CFLAGS  = -ansi -pedantic 


aprog : binaryTreeTest.o binaryTree.o 
	gcc -o aprog binaryTreeTest.o binaryTree.o
	
binaryTree.o : binaryTree.c binaryTree.h
	gcc -c $(CFLAGS) binaryTree.c
binaryTreeTest.o : binaryTreeTest.c binaryTree.h
	gcc -c $(CFLAGS) binaryTreeTest.c