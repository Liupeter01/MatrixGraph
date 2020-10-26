#include"Direct_Edge.h"

//输出在有向图G与结点x相邻边<x,?>
void Neighbors_direct(MGraph G, VertexType x)
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
                              printf("有向边出边<%c,%c>\n", x, G.Vex[i]);
                    }
                    if (G.Edge[i][x_pos] != 0)
                    {
                              printf("有向边入边<%c,%c>\n", x, G.Vex[i]);
                    }
          }
}

//判断在图G中是否存在有向边<x,y>
int  Adjcent_direct(MGraph G, VertexType x, VertexType y)
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
          return (G.Edge[x_pos][y_pos]);
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
                    G->Edge[x_pos][y_pos] = 0;
                    return TRUE;
          }
          else
          {
                    return FALSE;       //顶点不存在
          }
}