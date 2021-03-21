#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
typedef int ElemType;

/**
 * 顺序队列结构体
 * ElemType data[MAXSIZE] 数据存储数组，大小为MAXSIZE
 * int top 队头索引
 * int rear 队尾索引
 * int flag 判断队列是否已满的标识符
 */
typedef struct ListQueue
{
    ElemType data[MAXSIZE];
    int top;
    int rear;
    int flag;
} Queue, *listQueue;

/**
 * 初始化顺序队列
 * Queue 函数返回值
 */
Queue initListQueue()
{
    Queue queue;
    queue.top = 0;
    queue.rear = 0;
    queue.flag = 0;
    return queue;
}

/**
 * 入队操作  无返回值
 * listQueue queue 传入要操作的队列
 * ElemType elem 要传入的元素
 */
void pushListQueue(listQueue queue, ElemType elem)
{
    if (queue->flag)
    {
        printf("队列已满，无法插入！！！\n");
        return;
    }
    if ((queue->rear + 1) % MAXSIZE == queue->top)
    {
        queue->flag = 1;
    }
    printf("push: %d\n", elem);
    queue->data[queue->rear] = elem;
    queue->rear = (++queue->rear) % MAXSIZE;
}

/**
 * 出队操作  函数返回出对元素
 * listQueue queue 要操作的队列
 */
ElemType popListQueue(listQueue queue)
{
    if (!queue->flag && queue->top == queue->rear)
    {
        printf("栈为空，无法执行弹出操作！！\n");
        return -1;
    }
    if (queue->flag)
    {
        queue->flag = 0;
    }
    ElemType res = queue->data[queue->top];
    queue->top = (++queue->top) % MAXSIZE;
    return res;
}

/**
 * 计算队列元素个数函数 返回函数个数
 * listQueue queue
 */
int listQueueSize(Queue queue)
{
    if (queue.flag)
    {
        return MAXSIZE;
    }
    return (queue.rear - queue.top + MAXSIZE) % MAXSIZE;
}

int main()
{
    Queue queue = initListQueue();
    for (int i = 1; i < 7; i++)
    {
        pushListQueue(&queue, i);
    }
    printf("当前队列的长度为：%d\n", listQueueSize(queue));
    for (int i = 1; i < 5; i++)
    {
        ElemType num = popListQueue(&queue);
        printf("pop: %d\n", num);
    }
    for (int i = 1; i < 7; i++)
    {
        pushListQueue(&queue, i * 10);
    }
    printf("当前队列的长度为：%d\n", listQueueSize(queue));

    system("pause");
    return 0;
}