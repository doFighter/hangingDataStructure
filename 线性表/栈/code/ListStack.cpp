#include <iostream>
#define MAXSIZE 100

typedef int ElemType;
using namespace std;

class ListStack
{
private:
    /**
     *  栈的结构体
    *  - ElemType data[MAXSIZE]  元素数组
    *  - int top 标记栈顶
    */
    typedef struct Stack
    {
        ElemType data[MAXSIZE];
        int top;
    } listStack, *stack;

private:
    listStack liststack;
    void initListStack();

public:
    ListStack();
    ~ListStack();
    int isEmpty();
    void pushListStack(ElemType elem);
    ElemType popListStack();
};

ListStack::ListStack()
{
    initListStack();
}

ListStack::~ListStack()
{
}

/**
 *  初始化顺序栈
 *  将栈顶设置为 -1
 */
void ListStack::initListStack()
{
    liststack.top = -1;
}

/**
 * 判空操作
 * 判断栈是否为空
 */
int ListStack::isEmpty()
{
    return liststack.top == -1 ? 1 : 0;
}

/**
 * 入栈操作
 *  - ElemType elem  需要插入的元素
 */
void ListStack::pushListStack(ElemType elem)
{
    if (liststack.top > MAXSIZE - 1)
    {
        cout << "栈已满，无法压入！" << endl;
        return;
    }
    liststack.top++;
    liststack.data[liststack.top] = elem;
}

/**
 *  出栈操作：返回弹出的元素
 */
ElemType ListStack::popListStack()
{
    if (isEmpty())
    {
        cout << "栈已空，无法弹出！" << endl;
        return -1;
    }
    int num = liststack.data[liststack.top];
    liststack.top--;
    return num;
}

int main()
{
    ListStack Stack;
    for (int i = 1; i < 10; i++)
    {
        Stack.pushListStack(i);
    }
    while (!Stack.isEmpty())
    {
        cout << "弹出：" << Stack.popListStack() << endl;
    }
    system("pause");
    return 0;
}
