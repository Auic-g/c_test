#include "linklist.h"

//链表
//Basic operations
//Initialization
bool InitList(LinkList *L) {
    //带头结点单链表初始化
    *L = (LinkList)malloc(sizeof(LNode));
    if (*L == NULL) {
        return false;
    }
    (*L)->next = NULL;
    return true;
}
bool InitList2(LinkList *L) {
    //不带头结点单链表初始化
    *L = NULL;
    return true;
}

//Length
int Length(LinkList L){
    //带头结点单链表长度(不计头结点)
    int len = 0;
    LNode *p = L;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}

//Search
LNode* GetElem(LinkList L, int i){
    //按序号查找(带头结点单链表)
    LNode *p = L;
    int j = 0;
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    return p;
}
LNode* LocateElem(LinkList L, LinkElemType e){
    //按值查找(带头结点单链表)
    LNode *p = L->next;
    while(p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}

//Insert
bool ListInsert(LinkList *L, int i, LinkElemType e){
    //按序号插入
    LNode *p = *L;
    int j = 0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
LinkList List_HeadInsert(LinkList *L){
    //头插法(逆向)
    LNode *s; int x;
    *L = (LNode*)malloc(sizeof(LNode));
    (*L)->next = NULL;
    scanf("%d", &x);
    while(x != 9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = (*L)->next;
        (*L)->next = s;
        scanf("%d", &x);
    }
    return *L;
}
LinkList List_TailInsert(LinkList *L){
    //尾插法(正向)
    int x;
    *L = (LNode*)malloc(sizeof(LNode));
    LNode *s, *r = *L;
    scanf("%d", &x);
    while(x != 9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return *L;
}

//Delete
bool ListDelete(LinkList *L, int i, LinkElemType *e){
    //按序号删除
    LNode *p = *L;
    int j = 0;
    while(p->next != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p->next == NULL || j > i-1){
        return false;
    }
    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;
}








//Problem
//1.删除所有值为x的节点（带头结点单链表）
bool Del_x(LinkList *L, LinkElemType x){
    LNode *p = *L, *q;
    while(p->next != NULL){
        if(p->next->data == x){
            q = p->next;
            p->next = q->next;
            free(q);
        }
        p = p->next;
    }
    return true;
}

//2.删除最小值节点(带头结点单链表)
bool Del_Min(LinkList *L){
    LNode *p = *L, *q = p->next, *min = p->next;
    while(p->next != NULL){
        if(p->next->data < min->data){
            min = p->next;
            q = p;
        }
        p = p->next;
    }
    q->next = min->next;
    free(min);
    return true;
}

//3.将带头结点的单链表逆置，空间复杂度O(1)
LinkList Reverse(LinkList *L){
    LNode *p = *L, *q = p->next, *r;
    p->next = NULL;
    while(q != NULL){
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    return *L;
}
//参考答案
LinkList Reverse2(LinkList *L){
    LNode *pre, *p = (*L)->next, *r = p->next;
    p->next = NULL;
    while(r != NULL){
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    (*L)->next = p;
    return *L;
}

//4.删除处于无序的带头结点单链表中的给定的两个值之间的元素
bool Del_x_y(LinkList *L, LinkElemType x, LinkElemType y){
    if(x >= y || (*L)->next == NULL) return false;
    LNode *p = *L, *q = p->next, *r;
    while(q != NULL){
        if(q->data >= x && q->data <= y){
            r = q;
            q = q->next;
            p->next = q;
            free(r);
        }
        else{
            p = q;
            q = q->next;
        }
    }
    return true;
}

//5.分析找出两个单链表公共节点的思想

//6.将一个单链表拆为两个，空间复杂度O(1)
LinkList Split(LinkList *L){
    LinkList A, B;
    InitList(&A);
    InitList(&B);
    LNode *p = *L, *a = A, *b = B, *q = p->next, *r;
    while(q != NULL){
        q = p->next;
        r = q->next;
        p->next = q->next;
        a->next = q;
        p->next = r->next;
        r->next = b->next;
        b->next = r;
        a = q;
    }
    return A;
    return B;
}

//7.删除递增有序单链表中的重复元素
LinkList Del_Repeted(LinkList *L){
    LNode *p = *L, *q = p->next, *r;
    while(q != NULL){
        if(q->data == p->data){
            r = q;
            q = q->next;
            p->next = q;
            free(r);
        }
        else{
            p = q;
            q = q->next;
        }
    }
    return *L;
}

//8.将两个递增有序的单链表中的公共元素产生一个单链表，不破坏原来两个单链表的元素
LinkList Find_Common_Elem(LinkList *A, LinkList *B){
    LinkList C;
    InitList(&C);
    LNode *p = *A, *q = *B, *r = C, *s;
    while(p != NULL && q != NULL){
        if(p->data == q->data){
            s = (LNode*)malloc(sizeof(LNode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
        else if(p->data < q->data){
            p = p->next;
        }
        else{
            q = q->next;
        }
        r->next = NULL;
    }
}

//9.将两个递增有序的单链表的交集放在第一个单链表中
LinkList Find_Intersection(LinkList *A, LinkList *B){
    LNode *p = *A, *q = *B, *r;
    while(p != NULL && q != NULL){
        if(p->data == q->data){
            p = p->next;
            q = q->next;
        }
        else if(p->data < q->data){
            r = p;
            p = p->next;
            free(r);
        }
        else{
            q = q->next;
            if(q == NULL){
                while(p != NULL){
                    r = p;
                    p = p->next;
                    free(r);
                }
            }
        }
    }
    return *A;
}

//10.判断一个单链表的整数序列是否是另一个的连续子序列
bool Is_SubList(LinkList *A, LinkList *B){
    LNode *p = *A, *q = *B;
    while(p != NULL && q != NULL){
        if(p->data == q->data){
            p = p->next;
            q = q->next;
        }
        else if(p->data < q->data){
            p = p->next;
        }
        else{
            return false;
        }
    }
    return true;
}

//11.判断带头结点的循环双链表是否对称
bool Is_Symmetry(DLinkList *L){
    DNode *p = (*L)->next, *q = (*L)->prior;
    while(p != q && p->next != q){
        if(p->data != q->data){
            return false;
        }
        p = p->next;
        q = q->prior;
    }
    return true;
}

//12.编写一个函数将一个循环单链表h2链接到另一个循环单链表h1后，要求链接后的链表仍保持循环单链表形式
void Link_List(LinkList *L1, LinkList *L2){ 
    LNode *h1 = *L1, *h2 = *L2, *p = h1, *q = h2;
    while(p->next != h1){
        p = p->next;
    }
    while(q->next != h2){
        q = q->next;
    }
    p->next = h2->next;
    q->next = h1;
    free(h2);
}

//13.按freq降序排列双链表节点
DNode2* Locate(DLinkList2 *L, int x){
    DNode2 *q = (*L)->next;
    while(q != NULL && q->data != x){
        q = q->next;
    }
    if(q == NULL) return NULL;
    q->freq++;
    DNode2 *preNode = q->pre;
    if(preNode == *L || q->pre < preNode->freq){
        return q;
    }
    preNode->next = q->next;
    if(q->next != NULL){
        q->next->pre = preNode;
    }
    DNode2 *r = preNode;
    while(r->pre != *L && r->freq <= q->freq){
        r = r->pre;
    }
    q->next = r->next;
    q->pre = r;
    if(r->next != NULL){
        r->next->pre = q;
    }
    r->next = q;
    return q;
}

//14.将不带头节点的单链表中的循环整数序列右移k个位置
void Move_Right(LinkList *L, int k, int n){ 
    LNode *p = *L;
    int a[n];
    for(int i = 0; i < n; i++){
        a[i] = p->data;
        p = p->next;
    }
    p = *L;
    for(int i = n - k; i < n; i++){
        p->data = a[i];
        p = p->next;
    }
}

//15.判断单链表是否有环
bool Has_Circle(LinkList *L){
    LNode *p = *L, *q = q->next;
    while(p != NULL && q != NULL && q->next != NULL){
        if(p == q){
            return true;
        }
        p = p->next;
        q = q->next->next;
    }
    return false; 
}

//16.求不带头节点单链表的最大孪生和，孪生节点未对称节点
int Max_Sum(LinkList *L, int n){ 
    LNode *q = *L;
    int a[n];
    for(int i = 0; i < n; i++){
        a[i] = q->data;
        q = q->next;
    }
    int max = a[0] + a[n - 1];
    for(int i = 1; i < n/2; i++){
        if(a[i] + a[n - i - 1] > max){
            max = a[i] + a[n - i - 1];
        }
    }
    return max;
}

//17.查找倒数第k个结点的值（2009）
int Find_Kth(LinkList *L, int k){ 
    LNode *list = *L, *p = list->next;
    int n = 0;
    while(p != NULL){
        n++;
        p = p->next;
    }
    if(k > n || k < 1){
        return 0;
    }
    p = list->next;
    for(int i = 1; i < n - k + 1; i++){
        p = p->next;
    }
    return p->data;
    return 1;
}

//18.找出两个带头节点单链表共同后缀的起始位置（2012）
int Find_Common_Suffix(LNode *str1, LNode *str2){
    int len1 = 0, len2 = 0; 
    LNode *p = str1->next, *q = str2->next;
    while(p != NULL){
        len1++;
        p = p->next;
    }
    while(q != NULL){
        len2++;
        q = q->next;
    }
    p = str1->next;
    q = str2->next;
    if(len1 > len2){ 
        for(int i = 0; i < len1 - len2; i++){
            p = p->next;
        }
    }
    else if(len1 < len2){ 
        for(int i = 0; i < len2 - len1; i++){
            q = q->next;
        }
    }
    while(p != NULL && q != NULL && p->data != q->data){
        p = p->next;
        q = q->next;
    }
    return p->data;
}

//19.删除绝对值相等的节点，只保留第一次出现的（2015）
void Delete_Equal(LinkList *L, int n){
    LNode *head = *L, *q = head->next, *r = head;
    int a[n + 1];
    for(int i = 0; i < n + 1; i++){
        a[i] = -1;
    } 
    while(q != NULL){
        if(a[abs(q->data)] == -1){
            a[abs(q->data)] = abs(q->data);
            r = q;
            q = q->next;
        }
        else{
            r->next = q->next;
            free(q);
            q = r->next;
        }
    }
}

//20.重新排序单链表中各个节点的顺序
void Reorder(LinkList *L, int n){
    LNode *p = *L, *fast = p->next, *slow = p->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    LNode *q, *r = NULL;
    while(fast != NULL){
        q = fast->next;
        fast->next = r;
        r = fast;
        fast = q;
    }
    fast = r;
    while(fast != NULL){
        p = p->next;
        r = fast->next;
        fast->next = p->next;
        p->next = fast;
        fast = r;
        p = p->next;
    }
}

