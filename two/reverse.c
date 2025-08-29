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

//数组中两个线性表位置互换
void Exchange_two_list(int a[], SqList *L1, SqList *L2){
    
}
