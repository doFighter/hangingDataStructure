#include <iostream>

typedef int ElemType;
using namespace std;

class DoubleLinkList
{
private:
    /**
     *  链表节点的结构体
     * 
     *  - ElemType elem 数据域
     *  - struct Link *next 指针域，指向直接后继的节点
     *  - struct Link *prior 指针域，指向直接前驱的节点
     */
    typedef struct Link
    {
        ElemType elem;
        struct Link *prior;
        struct Link *next;
    } link, *DbLinkList;

private:
    DbLinkList dbLinkList;
    DbLinkList initLinkNode(ElemType elem);
    DbLinkList initLink(ElemType data[], int length);

public:
    DoubleLinkList();
    ~DoubleLinkList();
    DoubleLinkList(ElemType data[], int length);
    void insertLink(ElemType elem, int site);
    void insertArrayToLink(ElemType data[], int length, int site);
    void deleteLink(int site);
    int selectLink(ElemType elem);
    void amendLink(ElemType newElem, int site);
    void displayLink();
};

DoubleLinkList::DoubleLinkList()
{
    dbLinkList = initLinkNode(0);
}

DoubleLinkList::DoubleLinkList(ElemType data[], int length)
{
    dbLinkList = initLink(data, length);
}

DoubleLinkList::~DoubleLinkList()
{
}

/**
 *  初始化链表节点
 *  - ElemType elem 传入该节点所需要存放的值
 */
DoubleLinkList::DbLinkList DoubleLinkList::initLinkNode(ElemType elem)
{
    DbLinkList node = (link *)malloc(sizeof(link));
    node->elem = elem;
    node->next = NULL;
    node->prior = NULL;
    return node;
}

/**
 * 初始化链表函数：可以直接初始化一堆数据
 * 
 *  - ElemType data[]  初始化数据所存储的数组
 *  - int length    数据量
 */
DoubleLinkList::DbLinkList DoubleLinkList::initLink(ElemType data[], int length)
{
    DbLinkList start, end;
    start = initLinkNode(0); // 创建带有空头结点的双链表
    end = start;
    for (int i = 0; i < length; i++)
    {
        link *node = initLinkNode(data[i]);
        end->next = node;
        node->prior = end;
        end = node;
    }
    return start;
}

/**
 *  插入函数
 *  - ElemType elem 要插入的元素
 *  - int site  要插入的位置
 *  注意：链表带有一个空的头指针
 */
void DoubleLinkList::insertLink(ElemType elem, int site)
{
    link *temp;
    temp = dbLinkList;
    for (int i = 0; i < site - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "插入位置错误，请重新插入！" << endl;
            return;
        }
        temp = temp->next;
    }
    link *node = initLinkNode(elem);
    if (temp->next == NULL)
    {
        temp->next = node;
        node->prior = temp;
    }
    else
    {
        node->next = temp->next;
        temp->next->prior = node;
        node->prior = temp;
        temp->next = node;
    }
}

/**
 *  插入函数:这个函数是为了方便一下插入大量数据，所以可以接受数组插入
 *  - ElemType data[] 要插入元素组成的数组
 *  - int length    数组的长度
 *  - int site  要插入的位置
 *  注意：链表带有一个空的头指针
 */
void DoubleLinkList::insertArrayToLink(ElemType data[], int length, int site)
{
    link *temp;
    temp = dbLinkList;
    for (int i = 0; i < site - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "插入位置错误，请重新插入！" << endl;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        for (int i = 0; i < length; i++)
        {
            link *node = initLinkNode(data[i]);
            temp->next = node;
            node->prior = temp;
            temp = node;
        }
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            link *node = initLinkNode(data[i]);
            node->next = temp->next;
            temp->next->prior = node;
            node->prior = temp;
            temp->next = node;
            temp = node;
        }
    }
}

/**
 *  删除函数
 *  - int site  要删除的位置
 *  注意：链表带有一个空的头指针
 */
void DoubleLinkList::deleteLink(int site)
{
    link *temp, *del;
    temp = dbLinkList;
    for (int i = 0; i < site - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "删除位置错误，请重新输入！" << endl;
            return;
        }
        temp = temp->next;
    }
    del = temp->next;
    if (del->next == NULL)
    {
        temp->next = temp->next->next;
    }
    else
    {
        temp->next = temp->next->next;
        temp->next->prior = temp;
    }
    delete del;
}

/**
 *  查询函数
 *  - ElemType elem 要查询的元素
 *  注意：链表带有一个空的头指针
 */
int DoubleLinkList::selectLink(ElemType elem)
{
    link *temp;
    int i = 1;
    temp = dbLinkList->next;
    while (temp)
    {
        if (temp->elem == elem)
        {
            cout << elem << " 元素的位置为 " << i << ",他的是直接前驱元素为：" << temp->prior->elem << ",位置为 " << i - 1 << endl;
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}

/**
 *  修改函数
 *  - ElemType elem 要修改的目标值
 *  - int site  要修改的位置
 *  注意：链表带有一个空的头指针
 */
void DoubleLinkList::amendLink(ElemType newElem, int site)
{
    link *temp;
    temp = dbLinkList;
    for (int i = 0; i < site; i++)
    {
        if (temp == NULL)
        {
            cout << "输入的修改位置错误，请重新输入！" << endl;
            return;
        }
        temp = temp->next;
    }
    temp->elem = newElem;
}

/**
 *  输出函数：输出链表内的值
 * 
 */
void DoubleLinkList::displayLink()
{
    link *temp;
    temp = dbLinkList->next;
    while (temp)
    {
        cout << temp->elem << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    DoubleLinkList DbLinkList;
    int data[] = {11, 22, 33, 44, 55, 66, 77};
    int length = 7;
    DbLinkList.insertArrayToLink(data, length, 1);
    DbLinkList.displayLink();
    DbLinkList.insertLink(100, 4);
    DbLinkList.displayLink();
    DbLinkList.deleteLink(3);
    DbLinkList.displayLink();
    int data2[] = {10, 20, 30};
    DbLinkList.insertArrayToLink(data2, 3, 8);
    DbLinkList.displayLink();
    DbLinkList.amendLink(101, 3);
    DbLinkList.displayLink();
    int i = DbLinkList.selectLink(101);
    if (i < 0)
    {
        printf("未找到元素\n");
    }
    else
    {
        printf("元素101所在的位置为：%d\n", i);
    }
    system("pause");
    return 0;
}