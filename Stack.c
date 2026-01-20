
#include "Stack.h"

__declspec(dllexport) void CreateStack(Stack * PStr_Stack)
{
    PStr_Stack->Top=0;
}

/**
 *
 * @brief  Brief description of the function.
 *
 * @param  PStr_Stack reference of the stack.
 * @param  E Entry to be pushed in the stack.
 * @return Status of the entry whether it's pushed or not.
 *
 * @pre    Preconditions:
 *         - stack needs to be initialized and not full.
 *
 * @post   Postconditions:
 *         - N/A
 *
 * @note   N/A
 *
 * @warning value will not be pushed in the stack of the stack is full.
 */
__declspec(dllexport) void Push(Stack * PStr_Stack,StackEntry E)
{

        PStr_Stack->Entry[PStr_Stack->Top]=E;
        PStr_Stack->Top++;
}


__declspec(dllexport) void POP(StackEntry* PE,Stack * PStr_Stack)
{
           //stack is not empty
        *PE=PStr_Stack->Entry[PStr_Stack->Top-1];
        PStr_Stack->Top--;
}


__declspec(dllexport) void TraverseStack(Stack *ps,void(*pf)(StackEntry e))
{
    for(int i=ps->Top;i>0;i--)
    {
         (*pf)(ps->Entry[i-1]);

    }

}

__declspec(dllexport) int StackEmpty(Stack * PS)
{
    int returnVal=1;
    if(PS->Top>0)
    {
        returnVal=0;
    }
    return returnVal;
}

__declspec(dllexport) int StackFull(Stack*PS)
{
    int returnVal=0;
    if(PS->Top==STACK_MAX)
    {
        returnVal=1;
    }
    return returnVal;
}

 __declspec(dllexport)void StackTop(StackEntry *e,Stack *PS)
{
    *e=PS->Entry[PS->Top-1];
}

__declspec(dllexport) int StackSize(Stack *PS)
{
    return PS->Top-1;
}

__declspec(dllexport) void clearStack(Stack*PS)
{
    PS->Top=0;
}


