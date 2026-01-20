
#include "Stack2.h"
#include <stdlib.h>



__declspec(dllexport) void CreateStack(Stack * PStr_Stack)
{
    PStr_Stack->Top=NULL;
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
    StackNode *PN=(StackNode*) malloc(sizeof(StackNode));
    PN->entry=E;
    PN->nxt=PStr_Stack->Top;
    PStr_Stack->Top=PN;

  
}


__declspec(dllexport) void POP(StackEntry* PE,Stack * PStr_Stack)
{
           //stack is not empty
           *PE=PStr_Stack->Top->entry;
           StackNode *PN;
           PN=PStr_Stack->Top;
           PStr_Stack->Top=PStr_Stack->Top->nxt;
           free(PN); 
}


__declspec(dllexport) void TraverseStack(Stack *ps,void(*pf)(StackEntry e))
{
 

}

__declspec(dllexport) int StackEmpty(Stack * PS)
{

    return PS->Top==NULL;
   
}

__declspec(dllexport) int StackFull(Stack*PS)
{

}

 __declspec(dllexport)void StackTop(StackEntry *e,Stack *PS)
{
   
}

__declspec(dllexport) int StackSize(Stack *PS)
{
    
}

__declspec(dllexport) void clearStack(Stack*PS)
{
     
}
