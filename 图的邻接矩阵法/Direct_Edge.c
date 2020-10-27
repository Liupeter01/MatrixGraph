#include"Direct_Edge.h"

//���������ͼG����x���ڱ�<x,?>
void Neighbors_direct(MGraph G, VertexType x)
{
          int x_pos = LocateVertex(&G, x);
          for (int i = 0; i < G.MaxVertexNum; ++i)
          {
                    if (G.Edge[x_pos][i] != 0 && G.Edge[x_pos][i]!=MaxEdgeLength)
                    {
                              printf("����߳���<%c,%c>\n", x, G.Vex[i]);
                    }
                    if (G.Edge[i][x_pos] != 0 && G.Edge[i][x_pos] != MaxEdgeLength)
                    {
                              printf("��������<%c,%c>\n", x, G.Vex[i]);
                    }
          }
}

//�ж���ͼG���Ƿ���������<x,y>
int  Adjcent_direct(MGraph G, VertexType x, VertexType y)
{
          int x_pos = LocateVertex(&G, x);
          int y_pos = LocateVertex(&G, y);
          /*Ѱ�ҵ�һ������x�ڱ��λ��*/
          return  (G.Edge[x_pos][y_pos] != 0 && G.Edge[x_pos][y_pos] != MaxEdgeLength) ? 1 : 0;
}

//����ĳһ��������������
int CalculateEnterVertex(MGraph G, VertexType x)
{
          int counter = 0;
          for (int i = 0; i < G.vexnum; ++i)
          {
                    if (G.Edge[i][LocateVertex(&G, x)] != 0)      //����Ϊ��λ���б���
                    {
                              counter++;
                    }
          }
          return counter;
}

//����ĳһ������ĳ�������
int CalculateOutVertex(MGraph G, VertexType x)
{
          int counter = 0;
          for (int i = 0; i < G.vexnum; ++i)
          {
                    if (G.Edge[LocateVertex(&G, x)][i] != 0)//����Ϊ��λ���б���
                    {
                              counter++;
                    }
          }
          return counter;
}

//��ͼG����������<x,y>���ú�����֧���޸�Ȩֵ��ȨֵĬ��Ϊ1
int AddEdge_direct(MGraph* G, VertexType x, VertexType y)
{
          return AddEdgeDirectEdgeValue(G, x, y, 1);        //Ĭ�ϲ���Ϊ1
}

//������ͼG���һ�������(x, y)���ú���֧���޸�Ȩֵ
int AddEdgeDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value)
{
          int x_pos = LocateVertex(G, x); 
          int y_pos = LocateVertex(G, y);     //x��y��λ��

          int x_status = 0, y_status = 0;    //�ж��Ƿ������������
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    x_status = (G->Vex[i] == x) ? 1 : 0;
                    y_status = (G->Vex[i] == y) ? 1 : 0;
          }
          if (x_status && y_status)
          {
                    G->arcnum++;        //��������
                    G->Edge[x_pos][y_pos] = Edge_Value;
                    return TRUE;
          }
          else
          {
                    return FALSE;       //���㲻����
          }
}

//������ͼGɾ��һ�������<x, y>
int RemoveEdge_direct(MGraph* G, VertexType x, VertexType y)
{
          int x_pos = LocateVertex(G, x);
          int y_pos = LocateVertex(G, y);     //x��y��λ��

          int x_status = 0, y_status = 0;    //�ж��Ƿ������������
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    x_status = (G->Vex[i] == x) ? 1 : 0;
                    y_status = (G->Vex[i] == y) ? 1 : 0;
          }
          if (x_status && y_status)               //������ͬʱ�����ұ߱������
          {
                    G->arcnum--;        //�����Լ�
                    if (x_pos == y_pos)          //x_pos��y_pos���λ�ڶԽ�����
                    {
                              G->Edge[x_pos][y_pos] = 0;
                    }
                    G->Edge[x_pos][y_pos] = MaxEdgeLength;  //����ͨ״̬
                    return TRUE;
          }
          else
          {
                    return FALSE;       //���㲻����
          }
}