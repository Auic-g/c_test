#ifndef MAIN_H
#define MAIN_H

#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>

#define MaxSize 100

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

void InitList(SqList *L);
void ReverseList(SqList *L);
bool ListInsert(SqList *L,int i,ElemType e);
void PrintList(SqList *L);
bool Del_Min(SqList *L);
void Del_X(SqList *L, ElemType x);
bool ListDelete(SqList *L, int i, ElemType *e);
bool Del_s_t(SqList *L,ElemType s,ElemType t);
void Del_Repeated(SqList *L);
void Merge_two_list(SqList *L1, SqList *L2, SqList *L3);
void FreeList(SqList *L);
void Exchange_two_list(int a[], SqList *L1, SqList *L2);


#endif
