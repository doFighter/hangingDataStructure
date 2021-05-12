#include <iostream>

using namespace std;

// 邻接表中表对应的链表的顶点
typedef struct ENode
{
    int ivex;        // 该边所指向的顶点的位置
    int weight;      // 该边的权
    ENode *nextEdge; // 指向下一条弧的指针
    ENode(int v,int w):ivex(v),weight(w),nextEdge(NULL){}
} * Enode;

// 边的结构体
typedef struct EData
{
    char start; // 边的起点
    char end;   // 边的终点
    int weight; // 边的权重
};

// 邻接表中表的顶点
typedef struct VNode
{
    char data;        // 顶点信息
    ENode *firstEdge; // 指向第一条依附该顶点的弧
} * Vnode;

class Dijkstra
{
private:
    void LinkLast(Enode list, Enode node);
    int GetPosition(char ch);
    int GetWeight(int start, int end);

public:
    int mEdgNum; // 边的数量
    int VertexNum;//顶点数目
    VNode *mVexs; // 顶点数组

public:
    Dijkstra();
    Dijkstra(char vexs[], EData edges[], int vlen, int elen);
    void PrintNTable();
    ~Dijkstra();
    void CalcDijkstra(int vs, int prev[], int dist[]);
};

Dijkstra ::Dijkstra()
{
}

Dijkstra ::~Dijkstra()
{
}

/*
* 创建图
*   其实质就是构建了一个邻接表
* 参数说明：
*     vexs  -- 顶点数组
*     edges -- 边
*/
Dijkstra ::Dijkstra(char vexs[], EData edges[], int vlen, int elen)
{

    // 初始化"顶点"
    VertexNum = vlen;
    // 初始化"边"
    mEdgNum = elen;
    mVexs = new VNode[vlen];
    for (int i = 0; i < vlen; i++)
    {
        mVexs[i].data = vexs[i];
        mVexs[i].firstEdge = NULL;
    }

    for (int i = 0; i < elen; i++)
    {
        // 读取边的起始顶点和结束顶点
        char c1 = edges[i].start;
        char c2 = edges[i].end;
        int weight = edges[i].weight;

        // 读取边的起始顶点和结束顶点,返回的是边在顶点数组中的位置
        int p1 = GetPosition(c1);
        int p2 = GetPosition(c2);
        // 初始化node1
        Enode node1 = new ENode(p2,weight);
        // 将node1链接到"p1所在链表的末尾"
        if (mVexs[p1].firstEdge == NULL)
            mVexs[p1].firstEdge = node1;
        else
            LinkLast(mVexs[p1].firstEdge, node1);
        // 初始化node2
         Enode node2 = new ENode(p1,weight);
        // 将node2链接到"p2所在链表的末尾"
        if (mVexs[p2].firstEdge == NULL)
            mVexs[p2].firstEdge = node2;
        else
            LinkLast(mVexs[p2].firstEdge, node2);
    }
}

/*
* 将node节点链接到list的最后
*/
void Dijkstra ::LinkLast(Enode list, Enode node)
{
    Enode p = list;

    while (p->nextEdge != NULL)
        p = p->nextEdge;
    p->nextEdge = node;
}

/*
* 将node节点链接到list的最后
*/
void Dijkstra ::PrintNTable()
{
    for(int i = 0;i < VertexNum;i++){
        cout<<mVexs[i].data<<":";
        Enode node = mVexs[i].firstEdge;
        while(node){
            cout<<"->("<<node->ivex<<","<<node->weight<<")";
            node = node->nextEdge;
        }
        cout<<endl;
    }
}


/*
* 返回ch位置
*/
int Dijkstra ::GetPosition(char ch)
{
    for (int i = 0; i < VertexNum; i++)
        if (mVexs[i].data == ch)
            return i;
    return -1;
}

/*
* 获取边<start, end>的权值；若start和end不是连通的，则返回无穷大。
*/
int Dijkstra ::GetWeight(int start, int end)
{
    if (start == end)
        return 0;

    Enode node = mVexs[start].firstEdge;
    while (node != NULL)
    {
        if (end == node->ivex)
            return node->weight;
        node = node->nextEdge;
    }

    return INT32_MAX;
}

/*
* Dijkstra最短路径。
* 即，统计图中"起点D"到其它各个顶点的最短路径。
*
* 参数说明：
*       vs -- 起始顶点(start vertex)。
*     prev -- 前驱顶点数组。即，prev[i]的值是"起点D"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
*     dist -- 长度数组。即，dist[i]是"起点D"到"顶点i"的最短路径的长度。
*/
void Dijkstra ::CalcDijkstra(int vs, int prev[], int dist[])
{
    // flag[i]=true表示"起点D"到"顶点i"的最短路径已成功获取。
    bool flag[VertexNum];

    // 初始化
    for (int i = 0; i < VertexNum; i++)
    {
        flag[i] = false;            // 顶点i的最短路径还没获取到。
        prev[i] = 0;                // 顶点i的前驱顶点为0。
        dist[i] = GetWeight(vs, i); // 顶点i的最短路径为"起点D"到"顶点i"的权。此时为初始化，只是查看是否有直接的边相连接
    }

    // 对"起点D"自身进行初始化
    flag[vs] = true;
    dist[vs] = 0;

    // 遍历mVexs.Length-1次；每次找出一个顶点的最短路径。
    int k = 0;
    for (int i = 1; i < VertexNum; i++)
    {
        // 寻找当前最小的路径
        // 即，在未获取最短路径的顶点中，找到离起点D最近的顶点(k)。
        int min = INT32_MAX;
        for (int j = 0; j < VertexNum; j++)
        {
            if (flag[j] == false && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = true;

        // 更新当前最短路径和前驱顶点
        // 即，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (int j = 0; j < VertexNum; j++)
        {
            int tmp = GetWeight(k, j);
            tmp = (tmp == INT32_MAX ? INT32_MAX : (min + tmp)); // 防止溢出
            if (flag[j] == false && (tmp < dist[j]))
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    cout << "dijkstra(" << mVexs[vs].data << "):" << endl;
    for (int i = 0; i < VertexNum; i++)
    {
        cout << "shortest(" << mVexs[vs].data << ", " << mVexs[i].data << ")=" << dist[i] << endl;
    }
}

int main()
{
    int length = 7;
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    EData edges[] = {
            // 起点 终点 权重
            {'A', 'B', 12},
            {'A', 'F', 16},
            {'A', 'G', 14},
            {'B', 'C', 10},
            {'B', 'F', 7},
            {'C', 'D', 3},
            {'C', 'E', 5},
            {'C', 'F', 6},
            {'D', 'E', 4},
            {'E', 'F', 2},
            {'E', 'G', 8},
            {'F', 'G', 9},
    };
    int vlen = sizeof(vexs) / sizeof(char);
    int elen = sizeof(edges) / sizeof(EData);
    Dijkstra pG = Dijkstra(vexs, edges, vlen, elen);
    pG.PrintNTable();
    // dijkstra算法获取"起点D"到其它各个顶点的最短距离
    int prev[length];
    int dist[length];
    pG.CalcDijkstra(3, prev, dist);
    system("pause");
}