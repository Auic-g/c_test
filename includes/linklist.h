#ifndef LINKLIST_H_
#define LINKLIST_H_

#include "common.h"

typedef int LinkElemType;

typedef struct LNode {
    LinkElemType data;
    struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList *L);
void InitList2(LinkList *L);

#endif
