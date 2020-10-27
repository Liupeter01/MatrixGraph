#include"No_Direct_Edge.h"

//判断在图G中是否存在无向边(x,y)
int  Adjcent_nodirect(MGraph G, VertexType x, VertexType y)
{
          int x_pos = LocateVertex(&G, x);
          int y_pos = LocateVertex(&G, y);
          /*寻找第一个顶点x在表的位置*/
          return (G.Edge[x_pos][y_pos] != 0 && G.Edge[y_pos][x_pos] != MaxEdgeLength) ? 1 : 0;
}

//输出在无向图G与结点x相邻边(x,?)
void Neighbors_nodirect(MGraph G, VertexType x)
{
          int x_pos = LocateVertex(&G, x);
          for (int i = 0; i < G.MaxVertexNum; ++i)
          {
                    if (G.Edge[x_pos][i] != 0 && G.Edge[x_pos][i] != MaxEdgeLength)
                    {
                              printf("无向边(%c,%c)\n", x, G.Vex[i]);
                    }
          }
}

//在图G中添加无向边(x,y)，该函数不支持修改权值，使用默认权值1
int AddEdge_nodirect(MGraph* G, VertexType x, VertexType y)
{
          return AddEdgeNoDirectEdgeValue(G, x, y, 1);
}

//在无向图G添加一条无向边(x, y)，该函数支持修改权值
int AddEdgeNoDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value)
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
                    G->Edge[x_pos][y_pos] = G->Edge[y_pos][x_pos] = Edge_Value;
                    return TRUE;
          }
          else
          {
                    return FALSE;       //顶点不存在
          }
}

//在无向图G删除一条无向边(x, y)
int RemoveEdge_nodirect(MGraph* G, VertexType x, VertexType y)
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
                    G->Edge[y_pos][x_pos] = MaxEdgeLength;  //非连通状态
                    return TRUE;
          }
          else
          {
                    return FALSE;       //顶点不存在
          }
}