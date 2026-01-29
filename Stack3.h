#ifndef STACK3_H
#define STACK3_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void* StackEntry;

typedef struct StackNode {
    StackEntry entry;
    struct StackNode* nxt;
} StackNode;

typedef struct {
    StackNode* Top;
} Stack;

/* API */
 void CreateStack(Stack* PS);
 int  StackEmpty(Stack* PS);
 void Push(Stack* PS, StackEntry E);
 int  Pop(Stack* PS, StackEntry* PE);
 void StackTop(Stack* PS, StackEntry* PE);
 int  StackSize(Stack* PS);
 void ClearStack(Stack* PS);
 void TraverseStack(Stack* PS, void (*pf)(StackEntry));

#ifdef __cplusplus
}
#endif

#endif
