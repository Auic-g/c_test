#include "main.h"

void InitList(SqList *L){
    L->length = 0;
}

bool ListInsert(SqList *L,int i,ElemType e){
    if(i<1 || i>L->length+1)
        return false;
    if(L->length==MaxSize)
        return false;
    for(int j=L->length;j>=i;j--)
        L->data[j]=L->data[j-1];
    L->data[i-1]=e;
    L->length++;
    return true;
}

void PrintList(SqList *L){
    for(int i=0;i<L->length;i++)
        printf("%d ",L->data[i]);
    printf("\n");
}

bool ListDelete(SqList *L, int i, ElemType *e) {
    if (i < 0 || i > L->length) return false;
    *e = L->data[i];
    for (int j = i; j < L->length; j++) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return true;
}

void Del_X(SqList *L, ElemType x) {
    int i = 1;
    while (i <= L->length) {
        if (L->data[i] == x) {
            ElemType e;
            ListDelete(L, i, &e);
        } else {
            i++;
        }
    }
}

bool Del_Min(SqList *L){
    if(L->length==0){
        printf("顺序表为空，无法删除元素！\n");
        exit(1);  //退出运行
    }
    ElemType min_value = L->data[0];
    int pos = 0;
    for(int i = 1;i<L->length;i++)
        if(L->data[i] < min_value){
            min_value = L->data[i];
            pos = i;
        }
    ElemType value = min_value;
    L->data[pos]=L->data[L->length-1];
    L->length--;
    return true;
}

bool Del_s_t(SqList *L,ElemType s,ElemType t){
    if(s >= t)
        return false;
    for(int i = 0; i < L->length; ){
        if(L->data[i] >= s && L->data[i] <= t){
            ElemType e;
            ListDelete(L,i,&e);
        }else{
            i++;
        }
    }
    return true;
}

void Del_Repeated(SqList *L){
    for(int i = 0; i < L->length; i++){
        for(int j = i + 1; j < L->length; j++){
            if(L->data[i] == L->data[j]){
                ElemType e;
                ListDelete(L,j,&e);
                j--;
            }
        }
    }
}

