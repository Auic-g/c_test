#include "sqlist.h"

//Base
void InitList(SqList *L){
    L->length = 0;
}

void ClearList(SqList *L){
    L->length = 0;
}

bool ListInsert(SqList *L,int i,SqElemType e){
    if(i<1 || i>L->length+1)
        return false;
    if(L->length==SqList_MaxSize)
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

bool ListDelete(SqList *L, int i, SqElemType *e) {
    if (i < 1 || i > L->length) return false;
    *e = L->data[i-1];
    for (int j = i; j < L->length; j++) {
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return true;
}

//Delete
void Del_X(SqList *L, SqElemType x) {
    int i = 1;
    while (i <= L->length) {
        if (L->data[i-1] == x) {
            SqElemType e;
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
    SqElemType min_value = L->data[0];
    int pos = 0;
    for(int i = 1;i<L->length;i++)
        if(L->data[i] < min_value){
            min_value = L->data[i];
            pos = i;
        }
    SqElemType value = min_value;
    L->data[pos]=L->data[L->length-1];
    L->length--;
    return true;
}

bool Del_s_t(SqList *L,SqElemType s,SqElemType t){
    if(s >= t || L->length == 0)
        return false;
    int k = 0;
    for(int i = 0; i < L->length; i++){
        if(L->data[i] < s || L->data[i] > t){
            L->data[k++] = L->data[i];
        }
    }
    L->length = k;
    return true;
}

void Del_Repeated(SqList *L){
    if(L->length <= 1) return;
    
    int k = 1;
    for(int i = 1; i < L->length; i++){
        if(L->data[i] != L->data[i-1]){
            L->data[k++] = L->data[i];
        }
    }
    L->length = k;
}

//Merge
void Merge_two_list(SqList *L1, SqList *L2, SqList *L3){
    InitList(L3);
    int i;
    for(i = 0; i < L1->length; i++){
        L3->data[i] = L1->data[i];
    }
    for(int j = 0; j < L2->length; j++){
        L3->data[i + j] = L2->data[j];
    }
    L3->length = L1->length + L2->length;
}

//Reverse
void ReverseList(SqList *L){
    int i,j;
    SqElemType temp;
    for (i = 0 , j = L->length - 1; i < j; i++, j--){
        temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
    }
}

void ReverseArray_s_t(int a[], int s, int t){
    if(s > t) return;
    int i, j, temp;
    for(i = s, j = t; i < j; i++, j--){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

//在有序顺序表中查找x，若找到则与其后继交换，找不到就插入表中，使表保持有序
void Reverse_List_x_after(SqList *L, int x){
    int left = 0, right = L->length - 1;
    int mid;
    
    while(left <= right){
        mid = (left + right) / 2;
        if(L->data[mid] == x){
            if(mid < L->length - 1){
                SqElemType temp = L->data[mid];
                L->data[mid] = L->data[mid + 1];
                L->data[mid + 1] = temp;
            }
            return;
        }
        else if(L->data[mid] < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    if(left > right){
        ListInsert(L, left + 1, x);
    }
}

void Reverse_Array_P(int a[], int n, int p){
    ReverseArray_s_t(a, 0, p - 1);
    ReverseArray_s_t(a, p, n - 1);
    ReverseArray_s_t(a, 0, n - 1);
}

//Find
//求两个等长的升序序列的中位数
void Find_middle_number(SqList *L1, SqList *L2, int n){
    int left1 = 0, right1 = n - 1; //L1查找区间
    int left2 = 0, right2 = n - 1; //L2查找区间
    int mid1, mid2; //中间位置
    //二分查找
    while(left1 < right1){
        mid1 = (left1 + right1) / 2; //L1中间位置
        mid2 = (left2 + right2) / 2; //L2中间位置
        //判断中位数
        if(L1->data[mid1] == L2->data[mid2]){
            printf("中位数为：%d\n", L1->data[mid1]);
            return;
        }
        else if(L1->data[mid1] < L2->data[mid2]){
            //缩小L1查找区间
            if((left1 + right1) % 2 == 0){
                left1 = mid1;
                right2 = mid2;
            }
            else{
                left1 = mid1 + 1;
                right2 = mid2;
            }
        } else {
            //缩小L2查找区间
            if((left2 + right2) % 2 == 0){
                left2 = mid2;
                right1 = mid1;
            }
            else{
                left2 = mid2 + 1;
                right1 = mid1;
            }
        }
    }
    //最终判断
    int median = (L1->data[left1] < L2->data[left2]) ? L1->data[left1] : L2->data[left2];
    printf("中位数为：%d\n", median);
}

//求三个有序序列的相同元素
void Find_Same_Elem(SqList *L1, SqList *L2, SqList *L3){
    int i = 0, j = 0, k = 0;
    while(i < L1->length && j < L2->length && k < L3->length){
        if(L1->data[i] == L2->data[j] && L2->data[j] == L3->data[k]){
            printf("%d ", L1->data[i]);
            i++;
            j++;
            k++;
        }
        else{
            int min_val = L1->data[i];
            if(L2->data[j] < min_val) min_val = L2->data[j];
            if(L3->data[k] < min_val) min_val = L3->data[k];
            
            if(L1->data[i] == min_val) i++;
            if(L2->data[j] == min_val) j++;
            if(L3->data[k] == min_val) k++;
        }
    }
    printf("\n");
}

//求主元素
int Find_main_element(int a[], int n){
    int count = 1;
    for(int i = 0; i < n; i++){
        int main_element = a[i];
        for(int j = i + 1; j < n; j++){
            if(a[j] == main_element) count++;
        }
        if(count > n / 2) return main_element;
        count = 1;
    }
    return -1; // No main element found
}
