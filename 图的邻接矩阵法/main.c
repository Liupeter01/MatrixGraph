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

          VertexType arr1[] = "ACFDE";
          VertexType arr2[] = "BEAEF";

          for (int i = 0; i < 5; ++i)
          {
                    InsertUnDirectEdgeValue(&Graph, *(arr1+i), *(arr2 + i), rand() % 30);
          }

          DisplayGraph(Graph);          //ͼ�����
          DestroyGraph(&Graph);         //ͼ������
          return 0;
}