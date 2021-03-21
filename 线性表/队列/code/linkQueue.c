#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/**
 * 队列节点
 * ElemType elem 节点存储的元素
 * struct QueueNode *next 下一节点
 */
typedef struct QueueNode
{
    ElemType elem;
    struct QueueNode *next;
} Node, *linkQueue;

/**
 * 初始化节点函数 返回值为 linkQueue
 * ElemType elem 存储的元素
 */
linkQueue initQueueNode(ElemType elem)
{
    linkQueue node = (linkQueue)malloc(sizeof(Node));
    node->elem = elem;
    node->next = NULL;
    return node;
}

/**
 * 入队函数 无返回值
 * linkQueue queue  入对的队列
 * ElemType elem  入队的元素
 */
void pushLinkQueue(linkQueue queue, ElemType elem)
{
    linkQueue node = initQueueNode(elem);
    linkQueue temp = queue;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = node;
    printf("入队：%d\n", elem);
}

/**
 * 出队函数 返回值为存储的元素类型
 * linkQueue queue 执行出队操作的队列
 */
ElemType popLinkQueue(linkQueue queue)
{
    if (!queue->next)
    {
        printf("队列已空，无法出队！！\n");
        return -1;
    }
    linkQueue node = queue->next;

    ElemType res = node->elem;
    queue->next = node->next;
    free(node);
    return res;
}

/**
 * 队列元素数量函数 返回队列存储元素的个数
 * linkQueue queue 查询的队列
 */
int linkQueueSize(linkQueue queue)
{
    int size = 0;
    linkQueue temp = queue->next;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

int main()
{
    linkQueue queue = initQueueNode(0);
    for (int i = 1; i < 6; i++)
    {
        pushLinkQueue(queue, i);
    }
    printf("链队列的长度为：%d\n", linkQueueSize(queue));
    for (int i = 1; i < 8; i++)
    {
        ElemType num = popLinkQueue(queue);
        printf("出队：%d\n", num);
    }
    system("pause");
    return 0;
}