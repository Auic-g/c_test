#include "main.h"

int main(){
    SqList L1, L2, L3;
    InitList(&L1);
    InitList(&L2);
    // InitList(&L3);
    int a[6];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a[5] = 6;

    //插入一些测试数据
    ListInsert(&L1,1,a[0]);
    ListInsert(&L1,2,a[1]);
    // ListInsert(&L1,3,8);
    // ListInsert(&L1,4,2);
    // ListInsert(&L1,5,9);
    // ListInsert(&L1,6,2);
    ListInsert(&L2,1,a[0]);
    ListInsert(&L2,2,a[2]);
    ListInsert(&L2,3,a[3]);
    ListInsert(&L2,4,a[4]);
    // ListInsert(&L2,5,6);
    // ListInsert(&L2,6,7);

    // PrintList(&L1);
    // PrintList(&L2);
    // Merge_two_list(&L1, &L2, &L3);
    // PrintList(&L3);

    for(int i = 0; i < 6; i++)
        printf("%d ", a[i]);
    Exchange_two_list(a, &L1, &L2);
    for(int i = 0; i < 6; i++)
        printf("%d ", a[i]);
}