#include"MGraph.h"
#include"Direct_Edge.h"                 //����ͼ
#include"No_Direct_Edge.h"    //����ͼ

int main()
{
          int MGraph_Size = 0;          //ͼ�Ĵ�С
          printf("������ͼ�Ĵ�С��");
          scanf("%d", &MGraph_Size);

          MGraph Graph;
          InitGraph(&Graph, MGraph_Size);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDE" };
          CreateBatchVertex(&Graph, arr);//�����б��������

          AddEdge_nodirect(&Graph, 'A', 'B');  //����ͼ��AB
          AddEdge_nodirect(&Graph, 'B', 'C');  //����ͼ��BC
          AddEdge_nodirect(&Graph, 'C', 'D');  //����ͼ��CD
          AddEdge_nodirect(&Graph, 'C', 'E');  //����ͼ��CE

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}