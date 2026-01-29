#include "Stack3.h"
#include <stdlib.h>

 void CreateStack(Stack* PS)
{
    PS->Top = NULL;
}

 int StackEmpty(Stack* PS)
{
    return PS->Top == NULL;
}

 void Push(Stack* PS, StackEntry E)
{
    StackNode* PN = (StackNode*)malloc(sizeof(StackNode));
    if (!PN) return;   // allocation failed

    PN->entry = E;
    PN->nxt   = PS->Top;
    PS->Top   = PN;
}

 int Pop(Stack* PS, StackEntry* PE)
{
    if (StackEmpty(PS))
        return 0;   // failure

    StackNode* PN = PS->Top;
    *PE = PN->entry;
    PS->Top = PN->nxt;
    free(PN);

    return 1;       // success
}

 void StackTop(Stack* PS, StackEntry* PE)
{
    if (!StackEmpty(PS))
        *PE = PS->Top->entry;
}

 int StackSize(Stack* PS)
{
    int size = 0;
    StackNode* PN = PS->Top;

    while (PN) {
        size++;
        PN = PN->nxt;
    }
    return size;
}

 void ClearStack(Stack* PS)
{
    StackEntry dummy;
    while (!StackEmpty(PS)) {
        Pop(PS, &dummy);
    }
}

 void TraverseStack(Stack* PS, void (*pf)(StackEntry))
{
    StackNode* PN = PS->Top;
    while (PN) {
        pf(PN->entry);
        PN = PN->nxt;
    }
}
