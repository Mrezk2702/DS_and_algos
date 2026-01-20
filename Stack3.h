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
__declspec(dllexport) void CreateStack(Stack* PS);
__declspec(dllexport) int  StackEmpty(Stack* PS);
__declspec(dllexport) void Push(Stack* PS, StackEntry E);
__declspec(dllexport) int  Pop(Stack* PS, StackEntry* PE);
__declspec(dllexport) void StackTop(Stack* PS, StackEntry* PE);
__declspec(dllexport) int  StackSize(Stack* PS);
__declspec(dllexport) void ClearStack(Stack* PS);
__declspec(dllexport) void TraverseStack(Stack* PS, void (*pf)(StackEntry));

#ifdef __cplusplus
}
#endif

#endif
