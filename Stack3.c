#include "Stack3.h"
#include <stdlib.h>

__declspec(dllexport) void CreateStack(Stack* PS)
{
    PS->Top = NULL;
}

__declspec(dllexport) int StackEmpty(Stack* PS)
{
    return PS->Top == NULL;
}

__declspec(dllexport) void Push(Stack* PS, StackEntry E)
{
    StackNode* PN = (StackNode*)malloc(sizeof(StackNode));
    if (!PN) return;   // allocation failed

    PN->entry = E;
    PN->nxt   = PS->Top;
    PS->Top   = PN;
}

__declspec(dllexport) int Pop(Stack* PS, StackEntry* PE)
{
    if (StackEmpty(PS))
        return 0;   // failure

    StackNode* PN = PS->Top;
    *PE = PN->entry;
    PS->Top = PN->nxt;
    free(PN);

    return 1;       // success
}

__declspec(dllexport) void StackTop(Stack* PS, StackEntry* PE)
{
    if (!StackEmpty(PS))
        *PE = PS->Top->entry;
}

__declspec(dllexport) int StackSize(Stack* PS)
{
    int size = 0;
    StackNode* PN = PS->Top;

    while (PN) {
        size++;
        PN = PN->nxt;
    }
    return size;
}

__declspec(dllexport) void ClearStack(Stack* PS)
{
    StackEntry dummy;
    while (!StackEmpty(PS)) {
        Pop(PS, &dummy);
    }
}

__declspec(dllexport) void TraverseStack(Stack* PS, void (*pf)(StackEntry))
{
    StackNode* PN = PS->Top;
    while (PN) {
        pf(PN->entry);
        PN = PN->nxt;
    }
}
