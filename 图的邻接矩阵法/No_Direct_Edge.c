#include"No_Direct_Edge.h"

//�ж���ͼG���Ƿ���������(x,y)
int  Adjcent_nodirect(MGraph G, VertexType x, VertexType y)
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
          return (G.Edge[x_pos][y_pos] && G.Edge[y_pos][x_pos]);
}

//���������ͼG����x���ڱ�(x,?)
void Neighbors_nodirect(MGraph G, VertexType x)
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
                              printf("�����(%c,%c)\n", x, G.Vex[i]);
                    }
          }
}

//��ͼG����������(x,y)
int AddEdge_nodirect(MGraph* G, VertexType x, VertexType y)
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
                    G->Edge[x_pos][y_pos] = G->Edge[y_pos][x_pos] = 1;
                    return TRUE;
          }
          else
          {
                    return FALSE;       //���㲻����
          }
}

//������ͼGɾ��һ�������(x, y)
int RemoveEdge_nodirect(MGraph* G, VertexType x, VertexType y)
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
                    G->Edge[x_pos][y_pos] = G->Edge[y_pos][x_pos] = 0;
                    return TRUE;
          }
          else
          {
                    return FALSE;       //���㲻����
          }
}