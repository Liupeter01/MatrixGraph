#include"No_Direct_Edge.h"

//�ж���ͼG���Ƿ���������(x,y)
int  Adjcent_nodirect(MGraph G, VertexType x, VertexType y)
{
          int x_pos = LocateVertex(&G, x);
          int y_pos = LocateVertex(&G, y);
          /*Ѱ�ҵ�һ������x�ڱ��λ��*/
          return (G.Edge[x_pos][y_pos] != 0 && G.Edge[y_pos][x_pos] != MaxEdgeLength) ? 1 : 0;
}

//���������ͼG����x���ڱ�(x,?)
void Neighbors_nodirect(MGraph G, VertexType x)
{
          int x_pos = LocateVertex(&G, x);
          for (int i = 0; i < G.MaxVertexNum; ++i)
          {
                    if (G.Edge[x_pos][i] != 0 && G.Edge[x_pos][i] != MaxEdgeLength)
                    {
                              printf("�����(%c,%c)\n", x, G.Vex[i]);
                    }
          }
}

//��ͼG����������(x,y)���ú�����֧���޸�Ȩֵ��ʹ��Ĭ��Ȩֵ1
int AddEdge_nodirect(MGraph* G, VertexType x, VertexType y)
{
          return AddEdgeNoDirectEdgeValue(G, x, y, 1);
}

//������ͼG���һ�������(x, y)���ú���֧���޸�Ȩֵ
int AddEdgeNoDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value)
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
                    G->Edge[x_pos][y_pos] = G->Edge[y_pos][x_pos] = Edge_Value;
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
                    G->Edge[y_pos][x_pos] = MaxEdgeLength;  //����ͨ״̬
                    return TRUE;
          }
          else
          {
                    return FALSE;       //���㲻����
          }
}