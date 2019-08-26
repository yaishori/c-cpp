#ifndef H_BINTREE
#define H_BINTREE

typedef struct Tree Tree;
enum order {PREORDER, POSTORDER, INORDER};
typedef void (* BSTFunc)(int val);


Tree* createTree();
void treeDestroy(Tree* tree);
void insert2BST(Tree* tree,int val);
void searchBST(Tree* tree,int val);
void walkTree(Tree* tree,BSTFunc func,enum order orderFunc);
void deleteFromBST(Tree* tree,int val);

#endif