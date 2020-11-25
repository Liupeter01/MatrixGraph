#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDEF" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //�����б��������

          Pair pair[] =
          {
                    {'A','B',15}, {'C','E',8}, {'F','A',27}, {'D','E',3}, {'E','F',9}
          };                  //��Ȩ��

          for (int i = 0; i < sizeof(pair)/sizeof(Pair); ++i)
          {
                    InsertDirectEdgeValue(&Graph, pair[i].VexOne, pair[i].VexTwo, pair[i].distance);
          }

          DisplayGraph(Graph);          //ͼ�����
          DestroyGraph(&Graph);         //ͼ������
          return 0;
}