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
        
        insertTreeRec2(&myTree,&e1);
        e1.data=20; e1.key=3;
        insertTreeRec2(&myTree,&e1);
        e1.data=30; e1.key=7;
        insertTreeRec2(&myTree,&e1);
        e1.data=40; e1.key=2;
        insertTreeRec2(&myTree,&e1);
        e1.data=50; e1.key=4;
        insertTreeRec2(&myTree,&e1);

        deleteItemIter(&(myTree.root),&e1,3);
        inorder(&myTree,&display);

}