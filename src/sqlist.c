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
//标准答案
void Del_x_standard(SqList *L, SqElemType x){
//本算法实现删除顺序表L中所有值为x的数据元素
    int k = 0, i;                            //记录值不等于x的元素个数
    for(i = 0; i < L->length; i++){
        if(L->data[i] != x){
            L->data[k] = L->data[i];
            k++;                             //不等于x的元素加1
        }
    }
    L->length = k;                           //顺序表L的长度等于k
}
void Del_x_standard_2(SqList *L, SqElemType x){
    int k = 0, i = 0;                        //k记录值为x的元素个数
    while(i < L->length){
        if(L->data[i] == x)
            k++;
        else
            L->data[i - k] = L->data[i];     //当前元素前移k个位置
        i++;
    }
    L->length = L->length - k;               //顺序表L的长度递减
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
//标准答案
bool Del_Min_standard(SqList *L, SqElemType *min_value){
    //删除顺序表L中最小值元素结点，并通过引用型参数min_value返回其值
    //若删除成功，则返回true；否则返回false
    if(L->length == 0){
        return false;         //表空，中止操作返回
    }
    *min_value = L->data[0];
    int pos = 0;              //假定0号元素的值最小
    for(int i = 1; i < L->length; i++){          //循环，寻找具有最小值的元素
        if(L->data[i] < *min_value){             //让min_value记忆当前具有最小值的元素
            *min_value = L->data[i];
            pos = i;
        }
    }
    L->data[pos] = L->data[L->length - 1];     //用最后一个元素覆盖pos位置的元素
    L->length--;
    return true;                               //此时，min_value为最小值
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
bool Del_s_t_standard(SqList *L, SqElemType s, SqElemType t){
    //删除顺序表L中值在s和t之间的元素
    int i, k = 0;
    if(L->length == 0 || s > t)
        return false;
    for(i = 0; i < L->length; i++){
        if(L->data[i] >= s &&L->data[i] <= t)
            k++;
        else
            L->data[i - k] = L->data[i];
    }
    L->length -= k;
    return true;
    
}

void Del_Repeated(SqList *L){
    if(L->length < 1) return;
    
    int k = 1;
    for(int i = 1; i < L->length; i++){
        if(L->data[i] != L->data[i-1]){
            L->data[k++] = L->data[i];
        }
    }
    L->length = k;
}
//标准答案
bool Del_Same(SqList *L){
    if(L->length == 0)
        return false;
    int i,j;                                  //i存储第一个不相同的元素，j为工作指针
    for(i = 0, j = 1; j < L->length; j++)
        if(L->data[i] != L->data[j])          //查找上一个与下一个元素不同的元素
            L->data[++i] = L->data[j];        //找到后，将元素前移
    L->length = i + 1;
    return true;
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
//标准答案
bool Merge(SqList A, SqList B, SqList *C){
    //将有序顺序表A和B合并为一个新的有序顺序表C
    if(A.length + B.length > SqList_MaxSize)
        return false;
    int i = 0, j = 0, k = 0;
    while(i < A.length && j < B.length){
        if(A.data[i] <= B.data[j])
            C->data[k++] = A.data[i++];
        else
            C->data[k++] = B.data[j++];
    }
    while(i < A.length)
        C->data[k++] = A.data[i++];
    while(j < B.length)
        C->data[k++] = B.data[j++];
    C->length = k;
    return true;
}

//Reverse
void ReverseList(SqList *L){
    int i,j;
    SqElemType temp;                                //辅助变量
    for (i = 0 , j = L->length - 1; i < j; i++, j--){
        temp = L->data[i];                          //交换L->data[i]和L->data[j]
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
//标准答案
void SearchExchangeInsert(int a[], int n, int x){
    int low = 0, high = n - 1, mid, t;                        //low和high指向顺序表下界和上界的下标
    while(low <= high){
        mid = (low + high) / 2;                               //找到中间位置
        if(a[mid] == x) break;                                //找到x，退出while循环
        else if(a[mid] < x) low = mid + 1;                    //到中点x的右半部去查
        else high = mid - 1;                                  //到中点x的左半部去查
    }    //下面两个if语句只会执行一个
    if(a[mid] == x && mid != n - 1){                          //若最后一个元素与x相等，则不存在与其后继交换的操作
        t = a[mid];
        a[mid] = a[mid + 1];
        a[mid + 1] = t;
    }
    if(low > high){                                           //查找失败，插入数据元素x
        for(int j = n - 1; j >= low; j--) a[j + 1] = a[j];    //后移元素
        a[low] = x;                                           //插入x
    }                                                         //结束插入
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
        if(count > n / 2){
            printf("主元素为：%d\n", main_element);
            return main_element;
        }
        count = 1;
    }
    printf("无主元素\n");
    return -1; // No main element found
}

//求最小正整数（标准答案）
int Find_min_number(int a[], int n){
    if(n <= 0) return -1;
    int b[n + 2];
    for(int i = 0; i < n + 2; i++){
        b[i] = 0;
    }
    for(int i = 0; i < n; i++){
        if(a[i] > 0 && a[i] < n + 2){
            b[a[i]] = 1;
        }
    }
    for(int i = 1; i < n + 2; i++){
        if(b[i] == 0){
            printf("最小正整数为：%d\n", i);
            return i;
        }
    }
    return -1;
}
//快速排序(辅助算法)
void QuickSort(int a[], int low, int high){
    if(low >= high) return;
    int pivot = a[low];
    int i = low, j = high;
    while(i < j){
        while(i < j && a[j] >= pivot) j--;
        if(i < j) a[i++] = a[j];
        while(i < j && a[i] <= pivot) i++;
        if(i < j) a[j--] = a[i];
        a[i] = pivot;
    }
    QuickSort(a, low, i - 1);
    QuickSort(a, i + 1, high);
}
//求最小正整数（考场答案）
int Find_min_number_2(int a[], int n){
    if(n <= 0) return -1;
    QuickSort(a, 0, n - 1);
    int min_val = 1;
    for(int i = 0; i < n; i++){
        if(a[i] == min_val){
            min_val++;
        }
    }
    printf("最小正整数为：%d\n", min_val);
    return min_val;
}

//辅助函数：求绝对值
int Abs(int a){
    return a > 0 ? a : -a;
}
//最优解三元组
void Find_three_elements(int a[], int b[], int c[], int n, int m, int p){
    int i = 0, j = 0, k = 0;
    int D = Abs(a[0] - b[0]) + Abs(a[0] - c[0]) + Abs(b[0] - c[0]);
    int x, y, z;
    while(i < n && j < m && k < p){
        int current_D = Abs(a[i] - b[j]) + Abs(a[i] - c[k]) + Abs(b[j] - c[k]);
        if(current_D < D){
            D = current_D;
            x = a[i];
            y = b[j];
            z = c[k];
        }
        if(a[i] <= b[j] && a[i] <= c[k]){
            i++;
        }
        else if(b[j] <= a[i] && b[j] <= c[k]){
            j++;
        }
        else{
            k++;
        }
    }
    printf("最小距离的三个元素为：%d, %d, %d\n", x, y, z);
    printf("最小距离为：%d\n", D);
}
//暴力解三元组
void Find_three_elements_2(int a[], int b[], int c[], int n, int m, int p){
    int D = Abs(a[0] - b[0]) + Abs(a[0] - c[0]) + Abs(b[0] - c[0]);
    int x, y, z;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < p; k++){
                int current_D = Abs(a[i] - b[j]) + Abs(a[i] - c[k]) + Abs(b[j] - c[k]);
                if(current_D < D){
                    D = current_D;
                    x = a[i];
                    y = b[j];
                    z = c[k];
                }
            }
        }
    }
    printf("最小距离的三个元素为：%d, %d, %d\n", x, y, z);
    printf("最小距离为：%d\n", D);
}


