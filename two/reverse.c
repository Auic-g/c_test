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

//在长度为n顺序排列的线性表中以最短时间找到x，并将其与后继元素逆置
void Reverse_List_x_after(SqList *L, int x, int n){
    int i, j;
    i = 0, j = n - 1;
    while(i <= j){
        if(x < L->data[j]){
            j = (j + i) / 2;
        }
        i++;
    }
    for(j; j < j + i - 1;j++){
        if(x == L->data[j]){
            break;
        }
    }
    ElemType temp = L->data[j + 1];
    L->data[j + 1] = L->data[j];
    L->data[j] = temp;
}

void Reverse_Array_P(int a[], int n, int p){
    ReverseArray(a, n);
    Reverse_s_t(a, 0, n - p - 1);
    Reverse_s_t(a, n - p - 1, n - 1);
}
