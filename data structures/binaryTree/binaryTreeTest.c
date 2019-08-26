#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

void printval(int val){
	printf("%d ",val);
}

int main(){
	BSTFunc func=printval;
	Tree* tree = createTree();
	printf("hhh\n");
	insert2BST(tree,7);
	printf("inorder\n");
	walkTree(tree,func,INORDER);
	insert2BST(tree,4);
	insert2BST(tree,3);
	insert2BST(tree,5);
	insert2BST(tree,10);
	insert2BST(tree,11);
	insert2BST(tree,8);
	printf("preorder\n");
	walkTree(tree,func,PREORDER);
	printf("\n");
	printf("postorder\n");
	walkTree(tree,func,POSTORDER);
	printf("\n");
	printf("inorder\n");
	walkTree(tree,func,INORDER);
	printf("\n");
	
	deleteFromBST(tree,5);
	deleteFromBST(tree,7);
	
	printf("inorder\n");
	walkTree(tree,func,INORDER);
	
	treeDestroy(tree);
	
	return 0;
}