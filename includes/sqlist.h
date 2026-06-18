#ifndef SQLIST_H
#define SQLIST_H

#include "common.h"

#define SqList_MaxSize 100

typedef int SqElemType;
typedef struct {
    SqElemType data[SqList_MaxSize];
    int length;
} SqList;

void InitList(SqList *L);
void ReverseList(SqList *L);
bool ListInsert(SqList *L,int i,SqElemType e);
void PrintList(SqList *L);
bool Del_Min(SqList *L);
void Del_X(SqList *L, SqElemType x);
bool ListDelete(SqList *L, int i, SqElemType *e);
bool Del_s_t(SqList *L,SqElemType s,SqElemType t);
void Del_Repeated(SqList *L);
void Merge_two_list(SqList *L1, SqList *L2, SqList *L3);
void FreeList(SqList *L);
void Reverse_s_t(int a[], int s, int t);


#endif
