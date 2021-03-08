#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

/**
 *  链表节点的结构体
 * 
 *  - ElemType elem 数据域
 *  - struct Link *next 指针域，指向直接后的节点
 */
typedef struct Link
{
    ElemType elem;
    struct Link *next;
} link;