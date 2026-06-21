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

