#ifndef TREE_H
#define TREE_H

typedef int KeyType;
typedef struct
{
    int data;
    KeyType key;
} TreeEntry;
typedef struct TreeNode
{
    TreeEntry Entry;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
} TreeNode;

typedef struct Tree
{
    TreeNode*root;
    int size;
    int depth;
} Tree;

typedef struct TreeNode TreeNode;
typedef struct Tree Tree;
void CreateTree(Tree *ptree);
void ClearTree(Tree *ptree);
unsigned char treeempty(Tree *ptree);
unsigned char treefull(Tree *ptree);
int treesize(Tree *ptree);
void treedepth(Tree *ptree);
void preorder(Tree *ptree,void(*pf)(TreeEntry));
void inorder(Tree *ptree,void(*pf)(TreeEntry)); 
void postorder(Tree *ptree,void(*pf)(TreeEntry));
void insertTreeRec2(Tree *ptree,TreeEntry *pe);
void insertTreeIter(Tree *ptree,TreeEntry *pe);
int insertTreeRec(TreeNode **pt,TreeEntry *pe);
void clearTreeRec2(Tree *treeNode);
void cleartreeRec(TreeNode *treeNode);
void AVL_Insert(Tree *ptree,TreeEntry *pe);
int deleteItemIter(TreeNode** ptree,TreeEntry *pe,KeyType key);




#endif