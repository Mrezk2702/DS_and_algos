#include <stdio.h>
#include "Tree.h"

void display(TreeEntry e)
{
    printf("%d ",e.data);
}
void main(void)
{
      Tree myTree;
      CreateTree(&myTree);
        TreeEntry e1={10,5};
        e1.data=10; e1.key=10;
        AVL_Insert(&myTree,&e1);
        e1.data=20; e1.key=20;
        AVL_Insert(&myTree,&e1);
        e1.data=30; e1.key=30;
        AVL_Insert(&myTree,&e1);

               e1.data=40; e1.key=40;
        AVL_Insert(&myTree,&e1);
                e1.data=50; e1.key=50;
        AVL_Insert(&myTree,&e1);
               inorder(&myTree,&display);
      printf("\n root is%d",(myTree.root->right->Entry.data));

      
}