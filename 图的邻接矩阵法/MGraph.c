#include"MGraph.h"

//图G的输出
void DisplayGraph(MGraph G)
{
          for (int i = 0; i < G.vexnum; ++i)
          {
                    for (int j = 0; j < G.vexnum; ++j)
                    {
                              printf("%d  ", G.Edge[i][j]);
                    }
                    printf("\n");
          }
}

/*图G的初始化*/
void InitGraph(MGraph* G,int MGraph_Size)
{
          G->MaxVertexNum = MGraph_Size;
          G->vexnum = 0;      //没有结点
          G->arcnum = 0;      //没有边
          G->Vex = (VertexType*)calloc( MGraph_Size,sizeof(VertexType) );       //初始化结点名称
          G->Edge = (EdgeType**)calloc(MGraph_Size, sizeof(EdgeType*));
          for (int i = 0; i < MGraph_Size; ++i)
          {
                    G->Edge[i] = (EdgeType*)calloc(MGraph_Size, sizeof(EdgeType));
          }
          /*初始化完毕*/
}

//在图G中插入结点x
int InsertVertex(MGraph* G, VertexType x)
{
          if (G->vexnum + 1 == G->MaxVertexNum)  //满了
          {
                    return FALSE;
          }
          else
          {
                    G->Vex[G->vexnum] = x;      //新增加一个结点
                    for (int i = 0; i < G->MaxVertexNum; ++i)
                    {
                              G->Edge[G->vexnum][i] = MaxEdgeLength;    //行设置为不连通
                              G->Edge[i][G->vexnum] = MaxEdgeLength;    //列清空设置为不连通
                    }
                    G->Edge[G->vexnum][G->vexnum] = 0;    //位于对角线上的元素设置为0
                    G->vexnum++;                  //结点数+1
                    return TRUE;
          }
}

//在图G中根据顶点集合批量插入顶点
void CreateBatchVertex(MGraph* G, VertexType* arr)
{
          for (VertexType* p = arr; *p != '\0'; ++p)
          {
                    if (!InsertVertex(G, *p))
                    {
                              printf("顶点%c --- 插入失败\n", *p);
                    }
          }
}

//在图G中删除结点x，该函数包含顶点的有向边和无向边的处理
int DeleteVertex(MGraph* G, VertexType x)          
{
          int x_pos = 0;
          int flag = 0;
          G->Vex[x_pos] = 0;                      //删除位于顶点数组中该顶点的存在
          for (x_pos; x_pos < G->MaxVertexNum; ++x_pos)
          {
                    if (G->Vex[x_pos] == x)           // 在Vex中找到该结点并保存下标
                    {
                              G->Vex[x_pos] = 0;           //删除位于顶点数组中该顶点的存在
                              flag = 1;
                              break;
                    }
          }
          if (flag)
          {
                    for (int i = 0; i < G->MaxVertexNum; ++i)   //将该顶点的所有的边删除
                    {
                              G->Edge[x_pos][i] = MaxEdgeLength; //行清空删除所有的出边
                              G->Edge[i][x_pos] = MaxEdgeLength;//列清空删除所有的入边                    
                    }
                    G->Edge[x_pos][x_pos] = 0;              //重置位于对角线上的元素为0
                    G->vexnum--;        //结点数-1
                    return TRUE;
          }
          else
          {
                    return FALSE;
          }
}

//输出图中某条边的权值
void ShowEdgeValue(MGraph* G, VertexType x, VertexType y)
{
          int x_pos = 0, y_pos = 0;
          /*寻找第一个顶点x在表的位置*/
          for (x_pos; x_pos < G->MaxVertexNum; ++x_pos)
          {
                    if (G->Vex[x_pos] == x)
                    {
                              break;
                    }
          }
          /*寻找第二个顶点y在表的位置*/
          for (y_pos; y_pos < G->MaxVertexNum; ++y_pos)
          {
                    if (G->Vex[y_pos] == x)
                    {
                              break;
                    }
          }
          if (G->Edge[x_pos][y_pos] == 0 || G->Edge[x_pos][y_pos] == MaxEdgeLength)
          {
                    printf("该边不存在\n");
          }
          else if(G->Edge[x_pos][y_pos] == 1)
          {
                    printf("该边使用无权图的默认权值1\n");
          }
          else
          {
                    printf("边%c%c的权值为：%d\n", x, y, G->Edge[x_pos][y_pos]);
          }
}

/*
在图中寻找某一个顶点的邻接点
*/
//在图G中顶点X的第一个邻接点，若有则返回顶点号，若没有则返回-1
int FirstNeighbor(MGraph G, VertexType x)
{
          int x_pos = LocateVertex(&G, x);

          int flag = 0;       //判断是否找到
          int TheFirst = 0;
          for (TheFirst = 0;  TheFirst < G.MaxVertexNum; ++TheFirst)
          {
                    if (G.Edge[x_pos][TheFirst] != 0 && G.Edge[x_pos][TheFirst] != MaxEdgeLength) //不是自身且必须连通
                    {
                              flag = 1;
                              break;
                    }
          }
          if (!flag)
          {
                    return -1;          //没有找到
          }
          else
          {
                    return TheFirst;    //返回编号
          }
}

//在图G中顶点X的一个邻接点，返回除了顶点y以外的下一个顶点号
//若y是x的最后一个临界点，则返回-1
int NextNeighbor(MGraph G, VertexType x, VertexType y)
{
          int x_pos = LocateVertex(&G, x);     //用于保存x的位置
          int y_pos = LocateVertex(&G, y);     //用于保存y的位置
          int flag = 0;       //判断是否找到
          int TheNext = 0;
          for (TheNext = y_pos + 1; TheNext < G.MaxVertexNum; ++TheNext)
          {
                    if (G.Edge[x_pos][TheNext] != 0 && G.Edge[x_pos][TheNext] != MaxEdgeLength) //不是自身且必须连通
                    {
                              flag = 1;
                              break;
                    }
          }
          if (!flag)
          {
                    return -1;          //没有找到
          }
          else
          {
                    return TheNext;    //返回编号
          }
}

//在图G中找到顶点下标
int LocateVertex(MGraph* G, VertexType x)
{
          int x_pos = 0;
          for (x_pos; x_pos < G->MaxVertexNum; ++x_pos)
          {
                    if (G->Vex[x_pos] == x)
                    {
                              break;
                    }
          }
          return x_pos;
}

//图G的销毁
void DestroyGraph(MGraph* G)
{
          free(G->Vex);
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    free(G->Edge[i]);
          }
          free(G->Edge);
}