#include <iostream>
#define MAXSIZE 100
typedef int ElemType;
using namespace std;

class Sequence
{
private:
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
    } sqlist, *sqList;

private:
    sqList list;
    void initSqList();

public:
    Sequence();
    ~Sequence();
    void insertSqList(int index, ElemType num);
    void deleteSqList(int index);
    int selectSqList(ElemType elem);
    void amendSqList(ElemType begindata, ElemType amenddata);
    void displaySqList();
};

Sequence::Sequence()
{
    initSqList();
}

Sequence::~Sequence()
{
}

/**
 *  顺序表初始化函数
 */
void Sequence::initSqList()
{
    list->head = new ElemType[MAXSIZE];
    if (!list->head)
    {
        cout << "初始化失败" << endl;
        exit(0);
    }
    list->length = 0;
    list->size = MAXSIZE;
}

/**
 *  插入函数：向顺序表指定位置插入元素
 *  -   int index   插入的位置（不是下标，下标从0开始，这是从1开始）
 *  -   ElemType num 插入的元素
 */
void Sequence::insertSqList(ElemType num, int index = -1)
{
    if (index > list->length || index < -1)
    {
        cout << "索引错误，请输入合法索引！" << endl;
        return;
    }
    if (index == -1)
    {
        list->head[list->length] = num;
        list->length++;
    }
    else
    {
        for (int i = list->length; i >= index; i--)
        {
            list->head[i] = list->head[i - 1];
        }
        list->head[index - 1] = num;
        list->length++;
    }
}

/**
 *  删除函数：在顺序表指定位置删除元素
 *  -   int index   传入要删除的位置
 */
void Sequence::deleteSqList(int index)
{
    if (index > list->length || index < 1)
    {
        printf("索引错误，请输入合法索引！");
        return;
    }
    for (int i = index; i < list->length; i++)
    {
        list->head[i - 1] = list->head[i];
    }
    list->length--;
}

/**
 *  查找元素：从顺序表查找指定元素，并返回下标
 *  -   ElemType elem  需要查找的元素
 *  查到返回元素所在的位置，否则返回 -1
 */
int Sequence::selectSqList(ElemType elem)
{
    for (int i = 0; i < list->length; i++)
    {
        if (elem == list->head[i])
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
void Sequence::amendSqList(ElemType begindata, ElemType amenddata)
{
    for (int i = 0; i < list->length; i++)
    {
        if (list->head[i] == begindata)
        {
            list->head[i] = amenddata;
        }
    }
}

/**
 *  顺序表输出函数
 *  按顺序输出顺序表中的值
 *  sqlist sq   传入一个顺序表
 */
void Sequence::displaySqList()
{
    int i;
    for (i = 0; i < list->length; i++)
    {
        cout << list->head[i] << " ";
    }
    cout << endl;
}

int main()
{
    int i;
    Sequence sqList;
    //向顺序表中添加元素
    for (i = 1; i <= 5; i++)
    {
        sqList.insertSqList(i);
    }
    cout << "顺序表中存储的元素分别是：" << endl;
    sqList.displaySqList();
    sqList.insertSqList(10, 4);
    cout << "顺序表中存储的元素分别是：" << endl;
    sqList.displaySqList();
    sqList.deleteSqList(2);
    cout << "顺序表中存储的元素分别是：" << endl;
    sqList.displaySqList();
    cout << "10所在的位置为：" << sqList.selectSqList(10) << endl;
    sqList.amendSqList(1, 11);
    cout << "顺序表中存储的元素分别是：" << endl;
    sqList.displaySqList();
    system("pause");
    return 0;
}