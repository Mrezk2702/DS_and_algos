#include "Tree.h"

#include "Stack3.h"
#include "stdlib.h"






void CreateTree(Tree *ptree)
{
  ptree->root=NULL;
  ptree->size=0;    
    ptree->depth=0;
}

unsigned char treeempty(Tree *ptree)
{
    return ptree==NULL||ptree->root == NULL;
}

unsigned char treefull(Tree *ptree)
{
    (void)ptree; // to avoid unused parameter warning
    return 0;
}


int treesize(Tree *ptree)
{
    return ptree? ptree->size: 0;
 
}
int treeSizeRec(TreeNode *ptree)
{
    if(ptree==NULL)
    {
        return 0;
    }
    else
    {
        return 1+treeSizeRec(ptree->left)+treeSizeRec(ptree->right);
    }
}

int treeSizeRec2(Tree *ptree)
{
    return ptree? treeSizeRec(ptree->root): 0;
}

int treeDepthRec(TreeNode *ptree)
{
    if(ptree==NULL)
    {
        return 0;
    }
    else
    {
        int leftDepth=treeDepthRec(ptree->left);
        int rightDepth=treeDepthRec(ptree->right);
        return (leftDepth>rightDepth?leftDepth:rightDepth)+1;
    }
}
int treeDepthRec2(Tree *ptree)
{
    return ptree? treeDepthRec(ptree->root): 0;
}

void preorder_helper(TreeNode **ptree,void(*pf)(TreeEntry))
{
    if(ptree==NULL||*ptree==NULL||pf==NULL)
        return; //protection against NULL POINTERS

    pf((*ptree)->Entry);
    preorder_helper(&((*ptree)->left),pf);
    preorder_helper(&((*ptree)->right),pf);
  
}

void preorder(Tree *ptree,void(*pf)(TreeEntry))
{
    if(ptree==NULL||pf==NULL)
        return;
    preorder_helper(&(ptree->root),pf);
}


static void inorder_helper(TreeNode **ptree,void(*pf)(TreeEntry))
{
    if(ptree==NULL||*ptree==NULL||pf==NULL)
        return;


        inorder_helper(&((*ptree)->left),pf);
        pf((*ptree)->Entry);
        inorder_helper(&((*ptree)->right),pf);
}

void inorder(Tree *ptree,void(*pf)(TreeEntry))
{
    if(ptree==NULL||pf==NULL)
        return;
    inorder_helper(&(ptree->root),pf);
}
static void inorder_iter(TreeNode *ptree,void(*pf)(TreeEntry))
{
    // declare a stack to hold nodes
    Stack s;
    void* p=(void*)ptree;
    if(p)
    {
       // initialize stack
       CreateStack(&s);

       do
       {
           // go to the leftmost node
           while(p)
           {
               // push p onto stack
               Push(&s,p);
               // move to left child
               p=(void*)((TreeNode*)p)->left;
           }
           // pop from stack
           Pop(&s,&p);
           // visit the node
           pf(((TreeNode*)p)->Entry);
           // go to the right subtree
           p=(void*)((TreeNode*)p)->right;
       }while(p||!StackEmpty(&s));

    }
 
}



static void postorder_helper(TreeNode **ptree,void(*pf)(TreeEntry))
{
    if(ptree==NULL||*ptree==NULL||pf==NULL)
        return;
    postorder_helper(&((*ptree)->left),pf);
    postorder_helper(&((*ptree)->right),pf);
    pf((*ptree)->Entry);
}
void postorder(Tree *ptree,void(*pf)(TreeEntry))
{
    if(ptree==NULL||pf==NULL)
        return;
    postorder_helper(&(ptree->root),pf);
}

void clearTreeAux(TreeNode **treeNode)
{
    if(*treeNode)
    {
        clearTreeAux(&((*treeNode)->left));
        clearTreeAux(&((*treeNode)->right));
        free(*treeNode);
    }
}

void clearTreeRec(TreeNode **treeNode)
{
    clearTreeAux(treeNode);
    *treeNode=0;
}


void clearTreeRec2(Tree *ptree)
{
    if(ptree==NULL)
        return;
    clearTreeRec(&(ptree->root));
    ptree->size=0;
    ptree->depth=0;
}

int insertTreeRec(TreeNode **pt,TreeEntry *pe)
{
    if(pt == NULL || pe == NULL)
    return -1; // invalid parameters
    if(*pt==NULL)
    {
        *pt=malloc(sizeof(TreeNode));
        if (*pt == NULL)
        return -1;
        (*pt)->Entry=*pe;
        (*pt)->left=NULL;
        (*pt)->right=NULL;
    }
    else if(pe->key<(*pt)->Entry.key)
    {
        return insertTreeRec(&((*pt)->left),pe);
    }
    else if(pe->key>(*pt)->Entry.key)
    {
        return insertTreeRec(&((*pt)->right),pe);
    }
    else
    {
        return 0;
        // If key already exists, insertion is ignored
    }
    return 1;
}

int insertTreeAux(TreeNode **pt,TreeEntry *pe)
{
    if(pt == NULL || pe == NULL )
        return -1; // invalid parameters
    if(*pt==0)
    {
        *pt=(TreeNode*)malloc(sizeof(TreeNode));
        if(*pt==0)
            return -1; //memory allocation failed
        (*pt)->Entry=*pe;
        (*pt)->left=0;
        (*pt)->right=0;
        return 1;
    
    }
    else if(pe->key<(*pt)->Entry.key)
    {
       return insertTreeAux(&((*pt)->left),pe);
    }
    else if(pe->key>(*pt)->Entry.key)
    {
        return insertTreeAux(&((*pt)->right),pe);
    }
    else
    {
        return 0; //key already exists
    }

}

void insertTreeRec2(Tree *ptree,TreeEntry *pe)
{
    int res=insertTreeAux(&(ptree->root),pe);
    if(res==1)
    {
        ptree->size++;
    }
    

}
void insertTreeIter(Tree *ptree,TreeEntry *pe)
{
    TreeNode *pt,*prev,*curr;
     if(ptree==NULL||pe==NULL)
        return;
    pt=(TreeNode*)malloc(sizeof(TreeNode));
    if(pt==NULL)
        return; //memory allocation failed
    pt->Entry=*pe;
    pt->left=0;
    pt->right=0;
    if(ptree->root==0)
    {
        ptree->root=pt;
    }
    else
    {
        curr=ptree->root;
        while(curr)
        {
            prev=curr;
            if(pe->key<curr->Entry.key)
            {
                curr=curr->left;
            }
            else if(pe->key==curr->Entry.key)
            {
                free(pt); //key already exists
                return;
            }
            else
            {
                curr=curr->right;
            }
            

        }
                    /*this loop finishes with a pointer that points to the position of new node
            but it needs to be inserted wether left or right */
        if(pe->key<prev->Entry.key)
        {
            prev->left=pt;
        }
        else 
        {
            prev->right=pt;
        }


    }
    ptree->size++;
}


int findItemRec(TreeNode *ptree,TreeEntry *pe)
{
    
    if(ptree==NULL)
    {
        return 0;
    }
    else if(pe->key==ptree->Entry.key)
    {
        return 1;
    }
    else if(pe->key<ptree->Entry.key)
    {
        return findItemRec(ptree->left,pe);
    }
    else
    {
        return findItemRec(ptree->right,pe);
    }
}

int findItem(Tree *ptree,TreeEntry *pe)
{
    if(ptree==NULL||pe==NULL)
        return 0;
    return findItemRec(ptree->root,pe);
}

int findItemIter(Tree *ptree,TreeEntry *pe,TreeEntry *foundEntry)
{
    int found;
    TreeNode *curr=ptree->root;
    if(ptree==NULL||pe==NULL||foundEntry==NULL)
        return 0;
    while(curr&&!(found=(pe->key==curr->Entry.key)))
    {
        if(pe->key<curr->Entry.key)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
    if(found)
    {
         *foundEntry=curr->Entry;
    }
    return found;
}



void DeleteNodeTree(TreeNode **ptree)
{
        if (*ptree == NULL)
    return;
    TreeNode *q=*ptree;
    TreeNode *r;

    if((*ptree)->left==0) //Case 1: node to be deleted has no left child
    {
        *ptree=(*ptree)->right;
        free(q);  
    }
    else if((*ptree)->right==0) //Case 2: node to be deleted has no right child
    {
        *ptree=(*ptree)->left;
        free(q);
    }
    else //Case 3: node to be deleted has two children
    {
        q=(*ptree)->left;
        if(!q->right) //left child has no right child
        {
            (*ptree)->Entry=q->Entry;
            (*ptree)->left=q->left;
            free(q);
           
        }
        else
        {
            do
            {
                r=q;
                q=q->right;
            }while(q->right);
            (*ptree)->Entry=q->Entry;
            r->right=q->left;
            free(q);

        }
        
    }
}
int deleteItemIter(TreeNode** ptree,TreeEntry *pe,KeyType key)
{
   int found =0; TreeNode *q=*ptree, *r=NULL;
    if(!q) return 0; // Tree is empty, nothing to delete
   while(q&&!(found=key==q->Entry.key))
   {
       r=q;
       if(key<q->Entry.key)
       {
            q=q->left;
       }
       else
       {
            q=q->right; 
       }
   }
   if(found)
   {
        *pe=q->Entry;

     // Deletion logic goes here
     if(!r) //Case of deleting the root
     {
        DeleteNodeTree(ptree);
     }
     else if(key<r->Entry.key) //if the node to be deleted is in the left subtree
     {
        DeleteNodeTree(&r->left);
     }
     else
     {
        DeleteNodeTree(&r->right);//if the node to be deleted is in the right subtree
     }

 

   }
   

    return found;
}

int max(int a,int b)
{
    return a>b?a:b;
}
/*AVL TREE Functions */
int getbalance(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return treeDepthRec(node->left) - treeDepthRec(node->right);
}

void AVL_Left_Rotation(TreeNode ** ptree)
{
    //left rotation
        TreeNode *y=*ptree;
        TreeNode *x=y->right;
        TreeNode *T2=x->left;
        //perform rotation
        x->left=y;
        y->right=T2;
        //update heights    
        y->height=1+max(treeDepthRec(y->left),treeDepthRec(y->right));
        x->height=1+max(treeDepthRec(x->left),treeDepthRec(x->right));
        //update root
        *ptree=x;
}

void AVL_Right_Rotation(TreeNode ** ptree)
{
     // Right rotation
        TreeNode *y=*ptree;
        TreeNode *x=y->left;
        TreeNode *T2=x->right;

        // Perform rotation
        x->right=y;
        y->left=T2;

        // Update heights
        y->height=1+max(treeDepthRec(y->left),treeDepthRec(y->right));
        x->height=1+max(treeDepthRec(x->left),treeDepthRec(x->right));

        // Update root
        *ptree=x;
}
void AVL_LeftRight_Rotation(TreeNode ** ptree)
{
            //left-right rotation
        TreeNode *y=*ptree;
        TreeNode *x=y->left;
        TreeNode *z=x->right;
        TreeNode *T2=z->left;
        TreeNode *T3=z->right;
        //perform rotations
        z->left=x;
        z->right=y;
        x->right=T2;
        y->left=T3;
        //update heights
        x->height=1+max(treeDepthRec(x->left),treeDepthRec(x->right));
        y->height=1+max(treeDepthRec(y->left),treeDepthRec(y->right));
        z->height=1+max(treeDepthRec(z->left),treeDepthRec(z->right));
        //update root
        *ptree=z;
}
void AVL_RightLeft_Rotation(TreeNode **ptree)
{
            //right-left rotation
        TreeNode *y=*ptree;
        TreeNode *x=y->right;
        TreeNode *z=x->left;
        TreeNode *T2=z->left;
        TreeNode *T3=z->right;
        //perform rotations
        z->right=x;
        z->left=y;
        x->left=T3;
        y->right=T2;
        //update heights
        x->height=1+max(treeDepthRec(x->left),treeDepthRec(x->right));
        y->height=1+max(treeDepthRec(y->left),treeDepthRec(y->right));
        z->height=1+max(treeDepthRec(z->left),treeDepthRec(z->right));
        //update root
        *ptree=z;
}
int AVL_InsertAux(TreeNode **ptree,TreeEntry *pe)
{
    int returnval=1;
    //Perform normal BST insertion
    if(*ptree==NULL)
    {
        *ptree=malloc(sizeof(TreeNode));
        if(*ptree==NULL)
            return 0; //memory allocation failed
        (*ptree)->Entry=*pe;
        (*ptree)->left=NULL;
        (*ptree)->right=NULL;
        (*ptree)->height=1; //new node is initially added at leaf
        return 1;
    }
    if(pe->key<(*ptree)->Entry.key)
    {
       returnval= AVL_InsertAux(&((*ptree)->left),pe);
    }
    else if(pe->key>(*ptree)->Entry.key)
    {
       returnval= AVL_InsertAux(&((*ptree)->right),pe);
    }
    else
    {
        return -1; //duplicate keys are not allowed
    }
    if(returnval==1)
    {
    // Update heights and balance the tree
    (*ptree)->height=1+max(treeDepthRec((*ptree)->left),treeDepthRec((*ptree)->right));

    int balanceFactor=getbalance(*ptree);
    // Left Left Case
    if(balanceFactor>1&& pe->key<(*ptree)->left->Entry.key)
    {
        AVL_Right_Rotation(ptree);
    }
    else if(balanceFactor<-1&&pe->key>(*ptree)->right->Entry.key)
    {
        AVL_Left_Rotation(ptree);
    }
    else if(balanceFactor>1&&pe->key>(*ptree)->left->Entry.key)
    {
        AVL_LeftRight_Rotation(ptree);
    }
    else if(balanceFactor<-1&&pe->key<(*ptree)->right->Entry.key)
    {
       AVL_RightLeft_Rotation(ptree);
    }
    return 1;
}


}
void AVL_Insert(Tree *ptree,TreeEntry *pe)
{
    // AVL insertion logic would go here
    // This is a placeholder function
    AVL_InsertAux(&(ptree->root),pe);

}