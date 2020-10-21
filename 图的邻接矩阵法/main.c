#include"MGraph.h"
#include"Direct_Edge.h"                 //有向图
#include"No_Direct_Edge.h"    //无向图

int main()
{
          int MGraph_Size = 0;          //图的大小
          printf("请输入图的大小：");
          scanf("%d", &MGraph_Size);

          MGraph Graph;
          InitGraph(&Graph, MGraph_Size);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDE" };
          CreateBatchVertex(&Graph, arr);//顶点列表批量添加

          AddEdge_nodirect(&Graph, 'A', 'B');  //无向图边AB
          AddEdge_nodirect(&Graph, 'B', 'C');  //无向图边BC
          AddEdge_nodirect(&Graph, 'C', 'D');  //无向图边CD
          AddEdge_nodirect(&Graph, 'C', 'E');  //无向图边CE

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}