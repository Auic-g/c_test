#ifndef LINKLIST_H_
#define LINKLIST_H_

#include "common.h"

typedef int LinkElemType;

//单链表结点结构体
typedef struct LNode {
    LinkElemType data;
    struct LNode *next;
} LNode, *LinkList;
//双链表结点结构体
typedef struct DNode {
    LinkElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
//静态链表
#define MaxSize 50
typedef struct {
    LinkElemType data;
    int length;
} SLinkList[MaxSize];



bool InitList(LinkList *L);
bool InitList2(LinkList *L);

#endif
