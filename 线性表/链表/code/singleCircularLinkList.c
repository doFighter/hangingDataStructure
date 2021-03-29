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
link *initSingleCircularLink(ElemType data[], int length)
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
    end->next = start;
    return start;
}

/**
 *  插入函数
 *  - link *L   要插入的链表
 *  - ElemType elem 要插入的元素
 *  - int site  要插入的位置
 *  注意：链表带有一个空的头指针
 */
void insertSingleCircularLink(link *head, ElemType elem, int site)
{
    link *temp;
    temp = head;
    for (int i = 0; i < site - 1; i++)
    {

        temp = temp->next;
        if (temp == head)
        {
            printf("插入位置错误，请重新插入！\n");
            return;
        }
    }
    link *node = initLinkNode(elem);
    node->next = temp->next;
    temp->next = node;
}

/**
 *  删除函数
 *  - link *L   要删除的链表
 *  - int site  要删除的位置
 *  注意：链表带有一个空的头指针
 */
void deleteSingleCircularLink(link *head, int site)
{
    link *temp;
    temp = head;
    for (int i = 0; i < site - 1; i++)
    {

        temp = temp->next;
        if (temp->next == head)
        {
            printf("删除位置错误，请重新输入！\n");
            return;
        }
    }
    link *del = temp->next;
    temp->next = temp->next->next;
    free(del);
}

/**
 *  输出函数：输出链表内的值
 * 
 *  - link *L  传入链表头节点
 */
void displayLink(link *L)
{
    link *temp;
    temp = L->next;
    while (temp != L)
    {
        printf("%d  ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6};
    link *sq = initSingleCircularLink(data, 6);
    displayLink(sq);
    insertSingleCircularLink(sq, 25, 1);
    displayLink(sq);
    deleteSingleCircularLink(sq, 3);
    displayLink(sq);
    system("pause");
}