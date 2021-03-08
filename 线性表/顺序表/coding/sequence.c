#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

/*
 * 定义顺序表结构体
 *  -  *head  动态数组
 *  -   length  顺序表长度
 *  -   size    顺序表容量
 */
typedef struct SqList
{
    ElemType *head;
    int length;
    int size;
} sqlist;

/**
 *  顺序表初始化函数
 *  - sqlist *sq   传入一个sqlist类型的值的地址
 */
void initSqList(sqlist *sq)
{
    sq->head = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if (!sq->head)
    {
        printf("初始化失败");
        exit(0);
    }
    sq->length = 0;
    sq->size = MAXSIZE;
}

/**
 *  插入函数：向顺序表指定位置插入元素
 *  -   sqlist *sq  插入的顺序表
 *  -   int index   插入的位置（不是下标，下标从0开始，这是从1开始）
 *  -   ElemType num 插入的元素
 */
void insertSqList(sqlist *sq, int index, ElemType num)
{
    if (index > sq->length || index < 1)
    {
        printf("索引错误，请输入合法索引！");
        return;
    }
    for (int i = sq->length; i >= index; i--)
    {
        sq->head[i] = sq->head[i - 1];
    }
    sq->head[index - 1] = num;
    sq->length++;
}

/**
 *  删除函数：在顺序表指定位置删除元素
 *  - sqlist *sq    传入顺序表的地址
 *  -   int index   传入要删除的位置
 */
void deleteSqList(sqlist *sq, int index)
{
    if (index > sq->length || index < 1)
    {
        printf("索引错误，请输入合法索引！");
        return;
    }
    for (int i = index; i < sq->length; i++)
    {
        sq->head[i - 1] = sq->head[i];
    }
    sq->length--;
}

/**
 *  查找元素：从顺序表查找指定元素，并返回下标
 *  -   ElemType elem  需要查找的元素
 *  查到返回元素所在的位置，否则返回 -1
 */
int selectSqList(sqlist sq, ElemType elem)
{
    for (int i = 0; i < sq.length; i++)
    {
        if (elem == sq.head[i])
        {
            return i + 1;
        }
    }
    return -1;
}

/**
 *  修改函数：修改顺序表中指定的元素
 *  - ElemType begindata 需要修改的元素
 *  - ElemType amenddata 修改的结果
 */
void amendSqList(sqlist *sq, ElemType begindata, ElemType amenddata)
{
    for (int i = 0; i < sq->length; i++)
    {
        if (sq->head[i] == begindata)
        {
            sq->head[i] = amenddata;
        }
    }
}

/**
 *  顺序表输出函数
 *  按顺序输出顺序表中的值
 *  sqlist sq   传入一个顺序表
 */
void displaySqList(sqlist sq)
{
    int i;
    for (i = 0; i < sq.length; i++)
    {
        printf("%d ", sq.head[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    sqlist sq;
    initSqList(&sq);
    //向顺序表中添加元素
    for (i = 1; i <= 5; i++)
    {
        sq.head[i - 1] = i;
        sq.length++;
    }
    printf("顺序表中存储的元素分别是：\n");
    displaySqList(sq);
    insertSqList(&sq, 4, 10);
    printf("顺序表中存储的元素分别是：\n");
    displaySqList(sq);
    deleteSqList(&sq, 2);
    printf("顺序表中存储的元素分别是：\n");
    displaySqList(sq);
    int index = selectSqList(sq, 10);
    printf("10所在的位置为：%d \n", index);
    amendSqList(&sq, 1, 11);
    printf("顺序表中存储的元素分别是：\n");
    displaySqList(sq);
    system("pause");
    return 0;
}