#ifndef STACK_H_
#define STACK_H_
#define STACK_MAX 100


typedef char StackEntry;
typedef struct stacknode
{
    StackEntry entry;
    struct stacknode * nxt;
}StackNode;
typedef struct stack
{
    StackNode * Top;
}Stack;




__declspec(dllexport) void CreateStack(Stack * PStr_Stack);
__declspec(dllexport) void Push(Stack * PStr_Stack,StackEntry E);
__declspec(dllexport) void POP(StackEntry* PE,Stack * PStr_Stack);
__declspec(dllexport) void TraverseStack(Stack *ps,void(*pf)(StackEntry e));
__declspec(dllexport) int StackEmpty(Stack * PS);
__declspec(dllexport) int StackFull(Stack*PS);
__declspec(dllexport) void StackTop(StackEntry *e,Stack *PS);
__declspec(dllexport) int StackSize(Stack *PS);
__declspec(dllexport) void clearStack(Stack*PS);


#endif