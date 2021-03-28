#include <iostream>
using namespace std;

typedef int ElemType;

class LinkQueue
{
private:
    typedef struct QueueNode
    {
        ElemType elem;
        struct QueueNode *next;
    } Node, *linkQueue;

private:
    linkQueue queue;

public:
    ~LinkQueue();
    LinkQueue();
    LinkQueue(ElemType ele);
    linkQueue initQueueNode(ElemType elem);
    void pushLinkQueue(ElemType elem);
    ElemType popLinkQueue();
    int linkQueueSize();
};

LinkQueue::LinkQueue()
{
    queue = NULL;
}
LinkQueue::LinkQueue(ElemType ele)
{
    queue = initQueueNode(ele);
}
LinkQueue::~LinkQueue()
{
}
/**
 * 初始化节点函数 返回值为 linkQueue
 * ElemType elem 存储的元素
 */
LinkQueue::linkQueue LinkQueue::initQueueNode(ElemType elem)
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
void LinkQueue::pushLinkQueue(ElemType elem)
{
    linkQueue node = initQueueNode(elem);
    if (!queue)
    {
        queue = node;
    }
    else
    {
        linkQueue temp = queue;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    cout << "入队：" << elem << endl;
}

/**
 * 出队函数 返回值为存储的元素类型
 * linkQueue queue 执行出队操作的队列
 */
ElemType LinkQueue::popLinkQueue()
{
    if (!queue)
    {
        cout << "队列已空，无法出队！！" << endl;
        return -1;
    }
    linkQueue node = queue;

    ElemType res = node->elem;
    queue = node->next;
    delete node;
    return res;
}

/**
 * 队列元素数量函数 返回队列存储元素的个数
 * linkQueue queue 查询的队列
 */
int LinkQueue::linkQueueSize()
{
    int size = 0;
    linkQueue temp = queue;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

int main()
{
    LinkQueue queue;
    for (int i = 1; i < 6; i++)
    {
        queue.pushLinkQueue(i);
    }
    cout << "链队列的长度为：" << queue.linkQueueSize() << endl;
    for (int i = 1; i < 8; i++)
    {
        cout << "出队：" << queue.popLinkQueue() << endl;
    }
    system("pause");
    return 0;
}