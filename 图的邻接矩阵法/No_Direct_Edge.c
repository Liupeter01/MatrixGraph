#include"No_Direct_Edge.h"

//判断在图G中是否存在无向边(x,y)
int  Adjcent_nodirect(MGraph G, VertexType x, VertexType y)
{
          int x_pos = 0, y_pos = 0;
          /*寻找第一个顶点x在表的位置*/
          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
          {
                    if (G.Vex[x_pos] == x)
                    {
                              break;
                    }
          }
          /*寻找第二个顶点y在表的位置*/
          for (y_pos; y_pos < G.MaxVertexNum; ++y_pos)
          {
                    if (G.Vex[y_pos] == x)
                    {
                              break;
                    }
          }
          return (G.Edge[x_pos][y_pos] && G.Edge[y_pos][x_pos]);
}

//输出在无向图G与结点x相邻边(x,?)
void Neighbors_nodirect(MGraph G, VertexType x)
{
          int x_pos = 0;
          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
          {
                    if (G.Vex[x_pos] == x)
                    {
                              break;
                    }
          }
          for (int i = 0; i < G.MaxVertexNum; ++i)
          {
                    if (G.Edge[x_pos][i] != 0)
                    {
                              printf("无向边(%c,%c)\n", x, G.Vex[i]);
                    }
          }
}

//在图G中添加无向边(x,y)
int AddEdge_nodirect(MGraph* G, VertexType x, VertexType y)
{
          int x_pos = 0, y_pos = 0;     //x和y的位置
          int x_status = 0, y_status = 0;    //判断是否存在两个顶点
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    if (G->Vex[i] == x)
                    {
                              x_status = 1;                 //顶点x存在
                              x_pos = i;                    //保存x的位置
                    }
                    if (G->Vex[i] == y)
                    {
                              y_status = 1;                   //顶点y存在
                              y_pos = i;                    //保存y的位置
                    }
          }
          if (x_status && y_status)
          {
                    G->arcnum++;        //边数自增
                    G->Edge[x_pos][y_pos] = G->Edge[y_pos][x_pos] = 1;
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
          int x_pos = 0, y_pos = 0;     //x和y的位置
          int x_status = 0, y_status = 0;    //判断是否存在两个顶点
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    if (G->Vex[i] == x)
                    {
                              x_status = 1;                 //顶点x存在
                              x_pos = i;                    //保存x的位置
                    }
                    if (G->Vex[i] == y)
                    {
                              y_status = 1;                   //顶点y存在
                              y_pos = i;                    //保存y的位置
                    }
          }
          if (x_status && y_status)
          {
                    G->arcnum--;        //边数自减
                    G->Edge[x_pos][y_pos] = G->Edge[y_pos][x_pos] = 0;
                    return TRUE;
          }
          else
          {
                    return FALSE;       //顶点不存在
          }
}