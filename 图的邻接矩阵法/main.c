#include"MGraph.h"
//#include"DirectedEdge.h"                   //����ͼ
//#include"UnDirectedEdge.h"              //����ͼ

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDEEFGHIQM" };
          CreateBatchVertex(&Graph, arr);//�����б��������

          //AddEdge_nodirect(&Graph, 'A', 'B');  //����ͼ��AB
          //AddEdge_nodirect(&Graph, 'B', 'C');  //����ͼ��BC
          //AddEdge_nodirect(&Graph, 'C', 'D');  //����ͼ��CD
          //AddEdge_nodirect(&Graph, 'C', 'E');  //����ͼ��CE
          DisplayGraph(Graph);

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}