#include "main.h"

void Merge_two_list(SqList *L1, SqList *L2, SqList *L3){
    InitList(L3);
    for(int i = 0; i < L1->length; i++){
        ListInsert(L3, L3->length + 1, L1->data[i]);
    }
    for(int j = 0; j < L2->length; j++){
        ListInsert(L3, L3->length + 1, L2->data[j]);
    }
}
