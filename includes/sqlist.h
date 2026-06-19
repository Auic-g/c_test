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
void ClearList(SqList *L);
void ReverseArray_s_t(int a[], int s, int t);
void Reverse_List_x_after(SqList *L, int x);
void Reverse_Array_P(int a[], int n, int p);
void Find_Same_Elem(SqList *L1, SqList *L2, SqList *L3);
void Find_middle_number(SqList *L1, SqList *L2, int n);
int Find_main_element(int a[], int n);
int Find_min_number(int a[], int n);
int Find_min_number_2(int a[], int n);
void QuickSort(int a[], int low, int high);
int Abs(int a);
void Find_three_elements(int a[], int b[], int c[], int n, int m, int p);
void Find_three_elements_2(int a[], int b[], int c[], int n, int m, int p);

#endif
