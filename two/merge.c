#include "main.h"

void Merge_two_list(SqList *L1, SqList *L2, SqList *L3){
    InitList(L3);
    int i = 0, j = 0;
    if(i < L1->length && j < L2->length){
        if(L1->data[i] <= L2->data[j]){
            ListInsert(&L3, &L3->length + 1, L1->data[i]);
            i++;
        }else{
            ListInsert(&L3, &L3->length + 1, L2->data[j]);
            j++;
        }
    }
    while(i < L1->length){
        ListInsert(&L3, &L3->length + 1, L1->data[i]);
        i++;
    }
    while(j < L2->length){
        ListInsert(&L3, &L3->length + 1, L2->data[j]);
        j++;
    }
}
