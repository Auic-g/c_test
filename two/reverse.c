#include "main.h"

void ReverseList(SqList *L){
    int i,j;
    ElemType temp;
    for (i = 0 , j = L->length - 1; i < j; i++, j--){
        temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
    }
}

