#include "main.h"

void FreeList(SqList *L){
    L->length = 0;
}

void ReverseList(SqList *L){
    int i,j;
    ElemType temp;
    for (i = 0 , j = L->length - 1; i < j; i++, j--){
        temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
    }
}

void ReverseArray(int a[], int n){
    int i, j, temp;
    for(i = 0, j = n - 1; i < j; i++, j--){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void Reverse_s_t(int a[], int s, int t){
    if(s > t) return;
    int i, j, temp;
    for(i = s, j = t; i < j; i++, j--){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

