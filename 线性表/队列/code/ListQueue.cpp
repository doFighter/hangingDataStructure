#include <iostream>

#define MAXSIZE 5
typedef int ElemType;
using namespace std;

class ListQueue
{
private:
    /**
     * 顺序队列结构体
     * ElemType data[MAXSIZE] 数据存储数组，大小为MAXSIZE
     * int top 队头索引
     * int rear 队尾索引
     * int flag 判断队列是否已满的标识符
     */
    typedef struct Queue
    {
        ElemType data[MAXSIZE];
        int top;
        int rear;
        int flag;
    } queue, *listQueue;

private:
    Queue list_queue;
    queue initListQueue();

public:
    ListQueue();
    ~ListQueue();
    void pushListQueue(ElemType elem);
    ElemType popListQueue();
    int listQueueSize();
};

ListQueue::ListQueue()
{
    list_queue = initListQueue();
}

ListQueue::~ListQueue()
{
}
/**
 * 初始化顺序队列
 * Queue 函数返回值
 */
ListQueue::queue ListQueue::initListQueue()
{
    Queue queue;
    queue.top = 0;
    queue.rear = 0;
    queue.flag = 0;
    return queue;
}

/**
 * 入队操作  无返回值
 * ElemType elem 要传入的元素
 */
void ListQueue::pushListQueue(ElemType elem)
{
    if (list_queue.flag)
    {
        cout << "队列已满，无法插入！！！" << endl;
        return;
    }
    if ((list_queue.rear + 1) % MAXSIZE == list_queue.top)
    {
        list_queue.flag = 1;
    }
    cout << "push: " << elem << endl;
    list_queue.data[list_queue.rear] = elem;
    list_queue.rear = (++list_queue.rear) % MAXSIZE;
}

/**
 * 出队操作  函数返回出对元素
 */
ElemType ListQueue::popListQueue()
{
    if (!list_queue.flag && list_queue.top == list_queue.rear)
    {
        cout << "栈为空，无法执行弹出操作！！" << endl;
        return -1;
    }
    if (list_queue.flag)
    {
        list_queue.flag = 0;
    }
    ElemType res = list_queue.data[list_queue.top];
    list_queue.top = (++list_queue.top) % MAXSIZE;
    return res;
}

/**
 * 计算队列元素个数函数 返回函数个数
 */
int ListQueue::listQueueSize()
{
    if (list_queue.flag)
    {
        return MAXSIZE;
    }
    return (list_queue.rear - list_queue.top + MAXSIZE) % MAXSIZE;
}

int main()
{
    ListQueue queue;
    for (int i = 1; i < 7; i++)
    {
        queue.pushListQueue(i);
    }
    cout << "当前队列的长度为：" << queue.listQueueSize() << endl;
    for (int i = 1; i < 5; i++)
    {
        cout << "pop: " << queue.popListQueue() << endl;
    }
    for (int i = 1; i < 7; i++)
    {
        queue.pushListQueue(i * 10);
    }
    cout << "当前队列的长度为：" << queue.listQueueSize() << endl;

    system("pause");
    return 0;
}