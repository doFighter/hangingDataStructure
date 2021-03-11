#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/**
 *  链表节点的结构体
 * 
 *  - ElemType elem 数据域
 *  - struct Link *next 指针域，指向直接后继的节点
 */
typedef struct Link
{
    ElemType elem;
    struct Link *next;
} link;

/**
 *  初始化链表节点
 *  - link *    返回创建的节点的地址
 *  - ElemType elem 传入该节点所需要存放的值
 */
link *initLinkNode(ElemType elem)
{
    link *node = (link *)malloc(sizeof(link));
    node->elem = elem;
    node->next = NULL;
    return node;
}

/**
 * 初始化链表函数：可以直接初始化一堆数据
 * 
 *  - ElemType data[]  初始化数据所存储的数组
 *  - int length    数据量
 */
link *initLink(ElemType data[], int length)
{
    link *start, *end;
    start = initLinkNode(0); // 初始化单链表并携带头节点
    end = start;
    for (int i = 0; i < length; i++)
    {
        link *node = initLinkNode(data[i]);
        end->next = node;
        end = node;
    }
    return start;
}

/**
 *  插入函数
 *  - link *L   要插入的链表
 *  - ElemType elem 要插入的元素
 *  - int site  要插入的位置
 *  注意：链表带有一个空的头指针
 */
void insertLink(link *head, ElemType elem, int site)
{
    link *temp;
    temp = head;
    for (int i = 0; i < site - 1; i++)
    {
        if (temp == NULL)
        {
            printf("插入位置错误，请重新插入！\n");
            return;
        }
        temp = temp->next;
    }
    link *node = initLinkNode(elem);
    node->next = temp->next;
    temp->next = node;
}

/**
 *  删除函数
 *  - link *L   要操作的链表
 *  - int site  要删除的位置
 *  注意：链表带有一个空的头指针
 */
void deleteLink(link *head, int site)
{
    link *temp, *del;
    temp = head;
    for (int i = 0; i < site - 1; i++)
    {
        if (temp == NULL)
        {
            printf("删除位置错误，请重新输入！\n");
            return;
        }
        temp = temp->next;
    }
    del = temp->next;
    temp->next = temp->next->next;
    free(del);
}

/**
 *  查询函数
 *  - link *L   要操作的链表
 *  - ElemType elem 要查询的元素
 *  注意：链表带有一个空的头指针
 */
int selectLink(link *head, ElemType elem)
{
    link *temp;
    int i = 1;
    temp = head->next;
    while (temp)
    {
        if (temp->elem == elem)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}

/**
 *  修改函数
 *  - link *L   要操作的链表
 *  - ElemType elem 要修改的目标值
 *  - int site  要修改的位置
 *  注意：链表带有一个空的头指针
 */
void amendLink(link *head, ElemType newElem, int site)
{
    link *temp;
    temp = head;
    for (int i = 0; i < site; i++)
    {
        if (temp == NULL)
        {
            printf("输入的修改位置错误，请重新输入！\n");
            return;
        }
        temp = temp->next;
    }
    temp->elem = newElem;
}

/**
 *  输出函数：输出链表内的值
 * 
 *  - link *L  传入链表头节点
 */
void displayLink(link *L)
{
    link *temp = L;
    temp = L->next;
    while (temp)
    {
        printf("%d  ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    link *head;
    int data[] = {11, 22, 33, 44, 55, 66, 77};
    int length = 7;
    head = initLink(data, length);
    displayLink(head);
    insertLink(head, 100, 4);
    displayLink(head);
    deleteLink(head, 3);
    displayLink(head);
    amendLink(head, 101, 3);
    displayLink(head);
    int i = selectLink(head, 220);
    if (i < 0)
    {
        printf("未找到元素\n");
    }
    else
    {
        printf("元素101所在的位置为：%d\n", i);
    }
    system("pause");
    return 0;
}
