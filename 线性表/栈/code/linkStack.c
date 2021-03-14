#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/**
 * 组成栈的结构体
 * 其实与单链表一致
 * 
 */
typedef struct SNode
{
    ElemType elem;
    struct SNode *next;
} * stack;
typedef struct SNode snode;
/**
 * 初始化节点
 * - ElemType elem 传入的元素
 * - stack 返回类型 
 */
stack initSNode(ElemType elem)
{
    stack node = (stack)malloc(sizeof(snode));
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
stack initStack(ElemType data[], int length)
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
 *  - stack Stack 传入的栈
 */
int isEmpty(stack Stack)
{
    return Stack->next == NULL ? 1 : 0;
}

/**
 *  入栈函数
 *  - stack Stack 传入栈
 *  - ElemType elem 压入的元素
 */
void pushStack(stack Stack, ElemType elem)
{
    stack node = initSNode(elem);
    if (Stack->next == NULL)
    {
        Stack->next = node;
    }
    else
    {
        node->next = Stack->next;
        Stack->next = node;
    }
}

/**
 *  弹出元素操作
 *  - stack Stack 传入栈
 *  - ElemType 返回值类型
 */
ElemType popStack(stack Stack)
{
    if (isEmpty(Stack))
    {
        printf("栈已空，无法执行弹出操作！！");
        return 0;
    }
    stack del = Stack->next;
    int num = del->elem;
    Stack->next = del->next;
    free(del);
    return num;
}

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    stack head = initStack(data, 7);
    pushStack(head, 11);
    for (int i = 0; i < 3; i++)
    {
        printf("弹出：%d\n", popStack(head));
    }
    pushStack(head, 30);
    while (!isEmpty(head))
    {
        printf("弹出：%d\n", popStack(head));
    }
    system("pause");
    return 0;
}