#include "main.h"

void Print_Same_Elem(SqList *L1, SqList *L2, SqList *L3){
    int i = 0, j = 0, k = 0;
    while(i < L1->length && j < L2->length && k < L3->length){
        if(L1->data[i] == L2->data[j] && L2->data[j] == L3->data[k]){
            printf("%d ", L1->data[i]);
            i++;
            j++;
            k++;
        }
        else if(L1->data[i] < L2->data[j]){
            i++;
        }
        else if(L2->data[j] < L3->data[k]){
            j++;
        }
        else{
            k++;
        }
    }
}

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
    int median = (L1->data[left1] < L2->data[left2]) ? L2->data[left2] : L1->data[left1];
    printf("中位数为：%d\n", median);
}

void Find_main_element(int a[], int n){
    
}
