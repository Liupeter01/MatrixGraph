#include"MGraph.h"
//#include"DirectedEdge.h"                   //有向图
//#include"UnDirectedEdge.h"              //无向图

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDEEFGHIQM" };
          CreateBatchVertex(&Graph, arr);//顶点列表批量添加

          //AddEdge_nodirect(&Graph, 'A', 'B');  //无向图边AB
          //AddEdge_nodirect(&Graph, 'B', 'C');  //无向图边BC
          //AddEdge_nodirect(&Graph, 'C', 'D');  //无向图边CD
          //AddEdge_nodirect(&Graph, 'C', 'E');  //无向图边CE
          DisplayGraph(Graph);

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}