#include "stack.h"

//Basic Operations
//Initialition
void InitStack(SqStack *S){
    S->top = -1;
}

//Empty
bool StackEmpty(SqStack S){
    if(S.top == -1)
        return true;
    else
        return false;
}

//Push
bool Push(SqStack *S, StackElemType e){
    if(S->top == StackSize - 1)
        return false;
    else{
        S->data[++S->top] = e;
        return true;
    }
}

//Pop
bool Pop(SqStack *S, StackElemType *e){
    if(S->top == -1)
        return false;
    else{
        *e = S->data[S->top--];
        return true;
    }
}

//GetTop
bool GetTop(SqStack *S, StackElemType *e){ 
    if(S->top == -1)
        return false;
    else{
        *e = S->data[S->top];
        return true;
    }
}

