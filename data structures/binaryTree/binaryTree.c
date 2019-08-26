#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

struct Node{
	int val;
	struct Node* left;
	struct Node* right;
};
typedef struct Node Node;

struct Tree{
	Node* root;
};



static void postOrderNode(Node* root,BSTFunc func);
static void preOrderNode(Node* root,BSTFunc func);
static void inOrderNode(Node* root,BSTFunc func);
static Node* insert2BSTnode(Node* root,int val);
static int searchBSTnode(Node* root,int val);
static void walk(Node* node,BSTFunc func,enum order orderFunc);
static Node* deleteFromNode(Node* root,int val);
void treeDestroyNode(Node* root);


static void inOrderNode(Node* root,BSTFunc func){
 if (root!=NULL){
 	inOrderNode(root->left,func);
	func(root->val);
	inOrderNode(root->right,func);
 }
}

static void preOrderNode(Node* root,BSTFunc func){
 if (root!=NULL){
 	func(root->val);
 	preOrderNode(root->left,func);
 	preOrderNode(root->right,func);
 }
 
}

static void postOrderNode(Node* root,BSTFunc func){
 if (root!=NULL){
	 postOrderNode(root->left,func);
	 postOrderNode(root->right,func);
	 func(root->val);
 }
}

Tree* createTree(){
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root=NULL;
	return tree;
}

void treeDestroy(Tree* tree){
	treeDestroyNode(tree->root);
}

void treeDestroyNode(Node* root){
	 if( root!=NULL)
    {
        treeDestroyNode(root->left);
        treeDestroyNode(root->right);
        free(root);
    } 
}

static Node* createNode(int val){
	Node* node= (Node*)malloc(sizeof(Node));
	node->val=val;
	node->right=NULL;
	node->left=NULL;
	printf("%d\n",node->val);
	return node;
}
void insert2BST(Tree* tree,int val){
	insert2BSTnode(tree->root,val);
}

static Node* insert2BSTnode(Node* root,int val){

	 if (root==NULL){
	 	return createNode(val);
	 }
	 if(root->val<val){
	 	root->right= insert2BSTnode(root->right,val);
	 }
	 else if(root->val>val){
	 	root->left= insert2BSTnode(root->left,val);
	 }
	 
	 return root;
}

void searchBST(Tree* tree,int val){
	searchBSTnode(tree->root,val);
}

static int searchBSTnode(Node* root,int val){
	while(root!=NULL){
		if(root->val>val){
			root=root->left;
		}
		else if(root->val<val){
			root=root->right;
		}
		else{
			return 1;
		}
	}
	return 0;
}

void deleteFromBST(Tree* tree,int val){
	deleteFromNode(tree->root,val);
}

static Node* leftiestNode(Node* node){ 
    Node* myNode = node; 
	while (myNode->left != NULL){ 
        myNode = myNode->left; 
	}
    return myNode; 
}
static Node* deleteFromNode(Node* root,int val){
	Node* temp;
    if (root == NULL){
		return root; 
	}
    if (root->val > val) {
        root->left = deleteFromNode(root->left, val); 
	}
  
    else if (root->val< val){ 
        root->right = deleteFromNode(root->right, val); 
	}
	/*root->val == val*/
    else{ 
        /*one child*/
        if (root->left == NULL){ 
            temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL){ 
            temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        /*two childs */
        temp = leftiestNode(root->right);  
        root->val = temp->val; 
  
        root->right = deleteFromNode(root->right, temp->val); 
    } 
    return root; 
} 

void walkTree(Tree* tree,BSTFunc func,enum order orderFunc){
	enum order myorder=orderFunc;
	if(myorder==PREORDER){
		preOrderNode(tree->root,func);
	}
	if(myorder==INORDER){
		inOrderNode(tree->root,func);
	}
	if(myorder==POSTORDER){
		postOrderNode(tree->root,func);
	}
	return;
}

