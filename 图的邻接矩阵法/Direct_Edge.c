#include"Direct_Edge.h"

//输出在有向图G与结点x相邻边<x,?>
void Neighbors_direct(MGraph G, VertexType x)
{
          int x_pos = LocateVertex(&G, x);
          for (int i = 0; i < G.MaxVertexNum; ++i)
          {
                    if (G.Edge[x_pos][i] != 0 && G.Edge[x_pos][i]!=MaxEdgeLength)
                    {
                              printf("有向边出边<%c,%c>\n", x, G.Vex[i]);
                    }
                    if (G.Edge[i][x_pos] != 0 && G.Edge[i][x_pos] != MaxEdgeLength)
                    {
                              printf("有向边入边<%c,%c>\n", x, G.Vex[i]);
                    }
          }
}

//判断在图G中是否存在有向边<x,y>
int  Adjcent_direct(MGraph G, VertexType x, VertexType y)
{
          int x_pos = LocateVertex(&G, x);
          int y_pos = LocateVertex(&G, y);
          /*寻找第一个顶点x在表的位置*/
          return  (G.Edge[x_pos][y_pos] != 0 && G.Edge[x_pos][y_pos] != MaxEdgeLength) ? 1 : 0;
}

//计算某一个顶点的入度数量
int CalculateEnterVertex(MGraph G, VertexType x)
{
          int counter = 0;
          for (int i = 0; i < G.vexnum; ++i)
          {
                    if (G.Edge[i][LocateVertex(&G, x)] != 0)      //以列为单位进行遍历
                    {
                              counter++;
                    }
          }
          return counter;
}

//计算某一个顶点的出度数量
int CalculateOutVertex(MGraph G, VertexType x)
{
          int counter = 0;
          for (int i = 0; i < G.vexnum; ++i)
          {
                    if (G.Edge[LocateVertex(&G, x)][i] != 0)//以行为单位进行遍历
                    {
                              counter++;
                    }
          }
          return counter;
}

//在图G中添加有向边<x,y>，该函数不支持修改权值，权值默认为1
int AddEdge_direct(MGraph* G, VertexType x, VertexType y)
{
          return AddEdgeDirectEdgeValue(G, x, y, 1);        //默认参数为1
}

//在有向图G添加一条无向边(x, y)，该函数支持修改权值
int AddEdgeDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value)
{
          int x_pos = LocateVertex(G, x); 
          int y_pos = LocateVertex(G, y);     //x和y的位置

          int x_status = 0, y_status = 0;    //判断是否存在两个顶点
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    x_status = (G->Vex[i] == x) ? 1 : 0;
                    y_status = (G->Vex[i] == y) ? 1 : 0;
          }
          if (x_status && y_status)
          {
                    G->arcnum++;        //边数自增
                    G->Edge[x_pos][y_pos] = Edge_Value;
                    return TRUE;
          }
          else
          {
                    return FALSE;       //顶点不存在
          }
}

//在有向图G删除一条有向边<x, y>
int RemoveEdge_direct(MGraph* G, VertexType x, VertexType y)
{
          int x_pos = LocateVertex(G, x);
          int y_pos = LocateVertex(G, y);     //x和y的位置

          int x_status = 0, y_status = 0;    //判断是否存在两个顶点
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    x_status = (G->Vex[i] == x) ? 1 : 0;
                    y_status = (G->Vex[i] == y) ? 1 : 0;
          }
          if (x_status && y_status)               //两个点同时存在且边必须存在
          {
                    G->arcnum--;        //边数自减
                    if (x_pos == y_pos)          //x_pos和y_pos相等位于对角线上
                    {
                              G->Edge[x_pos][y_pos] = 0;
                    }
                    G->Edge[x_pos][y_pos] = MaxEdgeLength;  //非连通状态
                    return TRUE;
          }
          else
          {
                    return FALSE;       //顶点不存在
          }
}