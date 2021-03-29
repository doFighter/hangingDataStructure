#include <iostream>

typedef int ElemType;
using namespace std;

class SingleLinkList
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
    } link, *singleLinkList;

private:
    singleLinkList sLinkList;
    singleLinkList initLinkNode(ElemType elem);
    singleLinkList initLink(ElemType data[], int length);

public:
    SingleLinkList();
    SingleLinkList(ElemType data[], int length);
    ~SingleLinkList();
    void insertLink(ElemType elem, int site);
    void deleteLink(int site);
    int selectLink(ElemType elem);
    void amendLink(ElemType newElem, int site);
    void displayLink();
    void insertArrayToLink(ElemType data[], int length);
};

SingleLinkList::SingleLinkList()
{
    sLinkList = initLinkNode(0);
}
SingleLinkList::SingleLinkList(ElemType data[], int length)
{
    sLinkList = initLink(data, length);
}

SingleLinkList::~SingleLinkList()
{
}

/**
 *  初始化链表节点
 *  - ElemType elem 传入该节点所需要存放的值
 */
SingleLinkList::singleLinkList SingleLinkList::initLinkNode(ElemType elem)
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
SingleLinkList::singleLinkList SingleLinkList::initLink(ElemType data[], int length)
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
    return start;
}

/**
 *  插入函数
 *  - ElemType data[] 要插入元素组成的数组
 *  - int site  要插入的位置
 *  注意：链表带有一个空的头指针
 */
void SingleLinkList::insertArrayToLink(ElemType data[], int length)
{
    link *temp;
    temp = sLinkList;
    while (temp->next)
    {
        temp = temp->next;
    }
    for (int i = 0; i < length; i++)
    {
        link *node = initLinkNode(data[i]);
        temp->next = node;
        temp = node;
    }
}

/**
 *  插入函数
 *  - ElemType elem 要插入的元素
 *  - int site  要插入的位置
 *  注意：链表带有一个空的头指针
 */
void SingleLinkList::insertLink(ElemType elem, int site = -1)
{
    link *temp;
    temp = sLinkList;
    if (site == -1)
    {
        while (temp->next)
        {
            temp = temp->next;
        }
    }
    else
    {
        for (int i = 0; i < site - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "插入位置错误，请重新插入！" << endl;
                return;
            }
            temp = temp->next;
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
void SingleLinkList::deleteLink(int site)
{
    link *temp, *del;
    temp = sLinkList;
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
    temp->next = temp->next->next;
    delete del;
}

/**
 *  查询函数
 *  - ElemType elem 要查询的元素
 *  注意：链表带有一个空的头指针
 */
int SingleLinkList::selectLink(ElemType elem)
{
    link *temp;
    int i = 1;
    temp = sLinkList->next;
    while (temp)
    {
        if (temp->elem == elem)
        {
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
void SingleLinkList::amendLink(ElemType newElem, int site)
{
    link *temp;
    temp = sLinkList;
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
void SingleLinkList::displayLink()
{
    link *temp;
    temp = sLinkList->next;
    while (temp)
    {
        cout << temp->elem << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    SingleLinkList sgLinkList;
    int data[] = {11, 22, 33, 44, 55, 66, 77};
    int length = 7;
    sgLinkList.insertArrayToLink(data, length);
    sgLinkList.displayLink();
    sgLinkList.insertLink(100, 4);
    sgLinkList.displayLink();
    sgLinkList.deleteLink(3);
    sgLinkList.displayLink();
    sgLinkList.amendLink(101, 3);
    sgLinkList.displayLink();
    int i = sgLinkList.selectLink(220);
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
