#include"MGraph.h"
#include"DirectedEdge.h"                   //有向图
#include"UnDirectedEdge.h"              //无向图

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDEF" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //顶点列表批量添加

          Pair pair[] =
          {
                    {'A','B',15}, {'C','E',8}, {'F','A',27}, {'D','E',3}, {'E','F',9}
          };                  //带权边

          for (int i = 0; i < sizeof(pair)/sizeof(Pair); ++i)
          {
                    InsertDirectEdgeValue(&Graph, pair[i].VexOne, pair[i].VexTwo, pair[i].distance);
          }

          DisplayGraph(Graph);          //图的输出
          DestroyGraph(&Graph);         //图的销毁
          return 0;
}