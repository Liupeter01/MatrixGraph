#include"Direct_Edge.h"

//���������ͼG����x���ڱ�<x,?>
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
                              printf("����߳���<%c,%c>\n", x, G.Vex[i]);
                    }
                    if (G.Edge[i][x_pos] != 0)
                    {
                              printf("��������<%c,%c>\n", x, G.Vex[i]);
                    }
          }
}

//�ж���ͼG���Ƿ���������<x,y>
int  Adjcent_direct(MGraph G, VertexType x, VertexType y)
{
          int x_pos = 0, y_pos = 0;
          /*Ѱ�ҵ�һ������x�ڱ��λ��*/
          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
          {
                    if (G.Vex[x_pos] == x)
                    {
                              break;
                    }
          }
          /*Ѱ�ҵڶ�������y�ڱ��λ��*/
          for (y_pos; y_pos < G.MaxVertexNum; ++y_pos)
          {
                    if (G.Vex[y_pos] == x)
                    {
                              break;
                    }
          }
          return (G.Edge[x_pos][y_pos]);
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
          int x_pos = 0, y_pos = 0;     //x��y��λ��
          int x_status = 0, y_status = 0;    //�ж��Ƿ������������
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    if (G->Vex[i] == x)
                    {
                              x_status = 1;                 //����x����
                              x_pos = i;                    //����x��λ��
                    }
                    if (G->Vex[i] == y)
                    {
                              y_status = 1;                   //����y����
                              y_pos = i;                    //����y��λ��
                    }
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
          int x_pos = 0, y_pos = 0;     //x��y��λ��
          int x_status = 0, y_status = 0;    //�ж��Ƿ������������
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    if (G->Vex[i] == x)
                    {
                              x_status = 1;                 //����x����
                              x_pos = i;                    //����x��λ��
                    }
                    if (G->Vex[i] == y)
                    {
                              y_status = 1;                   //����y����
                              y_pos = i;                    //����y��λ��
                    }
          }
          if (x_status && y_status)
          {
                    G->arcnum--;        //�����Լ�
                    G->Edge[x_pos][y_pos] = 0;
                    return TRUE;
          }
          else
          {
                    return FALSE;       //���㲻����
          }
}