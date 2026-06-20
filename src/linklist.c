#include "linklist.h"

//链表
//Base function
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


