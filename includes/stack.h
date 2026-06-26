#ifndef STACK_H
#define STACK_H

#include "common.h"


typedef int StackElemType;
// 栈
#define StackSize 50
typedef struct {
    StackElemType data[StackSize];
    int top;
} SqStack;
//链栈
typedef struct LinkNode { 
    StackElemType data;
    struct LinkNode *next;
} LiStack;

#endif
