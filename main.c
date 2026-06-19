#include "common.h"
#include "sqlist.h"

int main(){
    SqList L1, L2, L3;
    InitList(&L1);
    InitList(&L2);
    InitList(&L3);
    int a[6];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a[5] = 6;

    //插入一些测试数据
    ListInsert(&L1,1,1);
    ListInsert(&L1,2,3);
    ListInsert(&L1,3,5);
    ListInsert(&L1,4,7);
    ListInsert(&L1,5,9);
    ListInsert(&L1,6,11);
    ListInsert(&L2,1,2);
    ListInsert(&L2,2,4);
    ListInsert(&L2,3,6);
    ListInsert(&L2,4,8);
    ListInsert(&L2,5,10);
    ListInsert(&L2,6,12);

    // Find_main_element(a, 6);
    // Find_min_number_2(a, 6);
    // PrintList(&L1);
    // PrintList(&L2);
    // Merge_two_list(&L1, &L2, &L3);
    // PrintList(&L3);
    // Find_middle_number(&L1, &L2, 6);

    // for(int i = 0; i < 6; i++)
    //     printf("%d ", a[i]);
    // Reverse_s_t(a, 1, 4);
    // for(int i = 0; i < 6; i++)
    //     printf("%d ", a[i]);
}
