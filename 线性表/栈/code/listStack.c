#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100

typedef int ElemType;

/**
 *  栈的结构体
 *  - ElemType data[MAXSIZE]  元素数组
 *  - int top 标记栈顶
 */
typedef struct Stack
{
    ElemType data[MAXSIZE];
    int top;
} ListStack;

/**
 *  初始化顺序栈
 *  - ListStack *SqStack 栈的地址传递
 *  将栈顶设置为 -1
 */
void initListStack(ListStack *SqStack)
{
    SqStack->top = -1;
}

/**
 * 判空操作
 * 判断栈是否为空
 */
int isEmpty(ListStack SqStack)
{
    return SqStack.top == -1 ? 1 : 0;
}

/**
 * 入栈操作
 *  - ListStack *SqStack  栈的引用
 *  - ElemType elem  需要插入的元素
 */
void pushListStack(ListStack *SqStack, ElemType elem)
{
    if (SqStack->top > MAXSIZE - 1)
    {
        printf("栈已满，无法压入！");
        return;
    }
    SqStack->top++;
    SqStack->data[SqStack->top] = elem;
}

/**
 *  出栈操作：返回弹出的元素
 *  - ListStack *SqStack 传入栈的引用
 */
ElemType popListStack(ListStack *SqStack)
{
    if (isEmpty(*SqStack))
    {
        printf("栈已空，无法弹出！");
        return -1;
    }
    int num = SqStack->data[SqStack->top];
    SqStack->top--;
    return num;
}

int main()
{
    ListStack Stack;
    initListStack(&Stack);
    for (int i = 1; i < 10; i++)
    {
        pushListStack(&Stack, i);
    }
    while (!isEmpty(Stack))
    {
        printf("弹出：%d\n", popListStack(&Stack));
    }
    system("pause");
    return 0;
}
