#include <iostream>

typedef int ElemType;
using namespace std;

class LinkStack
{
private:
    /**
     * 组成栈的结构体
    * 其实与单链表一致
    * 
    */
    typedef struct SNode
    {
        ElemType elem;
        struct SNode *next;
    } snode, *stack;

private:
    stack linkStack;
    stack initSNode(ElemType elem);
    stack initStack(ElemType data[], int length);

public:
    LinkStack();
    LinkStack(ElemType data[], int length);
    ~LinkStack();
    int isEmpty();
    void pushStack(ElemType elem);
    ElemType popStack();
};

LinkStack::LinkStack()
{
    linkStack = initSNode(0);
}

LinkStack::LinkStack(ElemType data[], int length)
{
    linkStack = initStack(data, length);
}

LinkStack::~LinkStack()
{
}

/**
 * 初始化节点
 * - ElemType elem 传入的元素
 * - stack 返回类型 
 */
LinkStack::stack LinkStack::initSNode(ElemType elem)
{
    stack node = new snode;
    if (node == NULL)
    {
        exit(0);
    }
    node->elem = elem;
    node->next = NULL;
    return node;
}

/**
 *  初始化栈:该栈带有一个头指针
 * - ElemType data[] 进行一组数据的初始化入栈
 * - int length  数据个数
 * - stack 返回数据类型
 */
LinkStack::stack LinkStack::initStack(ElemType data[], int length)
{
    stack head = initSNode(0); // 栈的头指针
    for (int i = 0; i < length; i++)
    {
        stack node = initSNode(data[i]);
        node->next = head->next;
        head->next = node;
    }
    return head;
}

/**
 *  判断是否栈空
 */
int LinkStack::isEmpty()
{
    return linkStack->next == NULL ? 1 : 0;
}

/**
 *  入栈函数
 *  - ElemType elem 压入的元素
 */
void LinkStack::pushStack(ElemType elem)
{
    stack node = initSNode(elem);
    if (linkStack->next == NULL)
    {
        linkStack->next = node;
    }
    else
    {
        node->next = linkStack->next;
        linkStack->next = node;
    }
}

/**
 *  弹出元素操作
 *  - ElemType 返回值类型
 */
ElemType LinkStack::popStack()
{
    if (isEmpty())
    {
        cout << "栈已空，无法执行弹出操作！！" << endl;
        return 0;
    }
    stack del = linkStack->next;
    int num = del->elem;
    linkStack->next = del->next;
    delete del;
    return num;
}

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    int length = 7;
    LinkStack stack{data, length};
    stack.pushStack(11);
    for (int i = 0; i < 3; i++)
    {
        cout << "弹出：" << stack.popStack() << endl;
    }
    stack.pushStack(30);
    while (!stack.isEmpty())
    {
        cout << "弹出：" << stack.popStack() << endl;
    }
    system("pause");
    return 0;
}