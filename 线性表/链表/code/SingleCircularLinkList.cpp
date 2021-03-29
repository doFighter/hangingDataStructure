#include <iostream>

typedef int ElemType;
using namespace std;

class SingleCircularLinkList
{
private:
    /**
     *  链表节点的结构体
    * 
    *  - ElemType elem 数据域
    *  - struct Link *next 指针域，指向直接后继的节点
    */
    typedef struct Link
    {
        ElemType elem;
        struct Link *next;
    } link, *singleCircularLinkList;

private:
    singleCircularLinkList scLinkList;
    singleCircularLinkList initLinkNode(ElemType elem);
    singleCircularLinkList initSingleCircularLink(ElemType data[], int length);

public:
    SingleCircularLinkList();
    SingleCircularLinkList(ElemType data[], int length);
    ~SingleCircularLinkList();
    void insertSingleCircularLink(ElemType elem, int site);
    void deleteSingleCircularLink(int site);
    void displayLink();
};

SingleCircularLinkList::SingleCircularLinkList()
{
    scLinkList = initLinkNode(0);
}

SingleCircularLinkList::SingleCircularLinkList(ElemType data[], int length)
{
    scLinkList = initSingleCircularLink(data, length);
}

SingleCircularLinkList::~SingleCircularLinkList()
{
}

/**
 *  初始化链表节点
 *  - link *    返回创建的节点的地址
 *  - ElemType elem 传入该节点所需要存放的值
 */
SingleCircularLinkList::singleCircularLinkList SingleCircularLinkList::initLinkNode(ElemType elem)
{
    link *node = (link *)malloc(sizeof(link));
    node->elem = elem;
    node->next = NULL;
    return node;
}

/**
 * 初始化链表函数：可以直接初始化一堆数据
 * 
 *  - ElemType data[]  初始化数据所存储的数组
 *  - int length    数据量
 */
SingleCircularLinkList::singleCircularLinkList SingleCircularLinkList::initSingleCircularLink(ElemType data[], int length)
{
    link *start, *end;
    start = initLinkNode(0); // 初始化单链表并携带头节点
    end = start;
    for (int i = 0; i < length; i++)
    {
        link *node = initLinkNode(data[i]);
        end->next = node;
        end = node;
    }
    end->next = start;
    return start;
}

/**
 *  插入函数
 *  - ElemType elem 要插入的元素
 *  - int site  要插入的位置
 *  注意：链表带有一个空的头指针
 */
void SingleCircularLinkList::insertSingleCircularLink(ElemType elem, int site)
{
    link *temp;
    temp = scLinkList;
    for (int i = 0; i < site - 1; i++)
    {

        temp = temp->next;
        if (temp == scLinkList)
        {
            cout << "插入位置错误，请重新插入！" << endl;
            return;
        }
    }
    link *node = initLinkNode(elem);
    node->next = temp->next;
    temp->next = node;
}

/**
 *  删除函数
 *  - int site  要删除的位置
 *  注意：链表带有一个空的头指针
 */
void SingleCircularLinkList::deleteSingleCircularLink(int site)
{
    link *temp;
    temp = scLinkList;
    for (int i = 0; i < site - 1; i++)
    {

        temp = temp->next;
        if (temp->next == scLinkList)
        {
            cout << " 删除位置错误，请重新输入！" << endl;
            return;
        }
    }
    link *del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

/**
 *  输出函数：输出链表内的值
 * 
 */
void SingleCircularLinkList::displayLink()
{
    link *temp;
    temp = scLinkList->next;
    while (temp != scLinkList)
    {
        cout << temp->elem << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6};
    int length = 6;
    SingleCircularLinkList scLinkList{data, length}; // 初始化循环单链表
    scLinkList.displayLink();
    scLinkList.insertSingleCircularLink(25, 1);
    scLinkList.displayLink();
    scLinkList.deleteSingleCircularLink(5);
    scLinkList.displayLink();
    system("pause");
}