#include "main.h"

int main(){
    SqList L;
    InitList(&L);
    
    //插入一些测试数据
    ListInsert(&L,1,5);
    ListInsert(&L,2,2);
    ListInsert(&L,3,8);
    ListInsert(&L,4,2);
    ListInsert(&L,5,9);
    ListInsert(&L,6,2);
    
    // printf("删除前的顺序表：");
    PrintList(&L);
    // ElemType min_value;
    // Del_Min(&L,&min_value);
    // printf("删除的最小元素：%d\n",min_value);
    // printf("删除后的顺序表：");
    // PrintList(&L);
    // ReverseList(&L);
    // printf("反转后的顺序表：");
    // PrintList(&L);
    // return 0;
    //Del_X(&L,2); // 删除所有值为2的元素
    // Del_s_t(&L,1,5);
    Del_Repeated(&L);
    PrintList(&L);
}