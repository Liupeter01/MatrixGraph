#include"MGraph.h"

/*ͼG�ĳ�ʼ��*/
void InitGraph(MGraph* G,int MGraph_Size)
{
          G->MaxVertexNum = MGraph_Size;
          G->vexnum = 0;      //û�н��
          G->arcnum = 0;      //û�б�
          G->Vex = (VertexType*)calloc( MGraph_Size,sizeof(VertexType) );       //��ʼ���������
          G->Edge = (EdgeType**)calloc(MGraph_Size, sizeof(EdgeType*));
          for (int i = 0; i < MGraph_Size; ++i)
          {
                    G->Edge[i] = (EdgeType*)calloc(MGraph_Size, sizeof(EdgeType));
          }
          /*��ʼ�����*/
}

//��ͼG�в�����x
int InsertVertex(MGraph* G, VertexType x)
{
          if (G->vexnum + 1 == G->MaxVertexNum)  //����
          {
                    return FALSE;
          }
          else
          {
                    G->Vex[G->vexnum] = x;      //������һ�����
                    for (int i = 0; i < G->MaxVertexNum; ++i)
                    {
                              G->Edge[G->vexnum][i] = 0;    //�����
                              G->Edge[i][G->vexnum] = 0;    //�����
                    }
                    G->vexnum++;                  //�����+1
                    return TRUE;
          }
}

//��ͼG�и��ݶ��㼯���������붥��
void CreateBatchVertex(MGraph* G, VertexType* arr)
{
          for (VertexType* p = arr; *p != '\0'; ++p)
          {
                    if (!InsertVertex(G, *p))
                    {
                              printf("����%c --- ����ʧ��\n", *p);
                    }
          }
}

//��ͼG��ɾ�����x
int DeleteVertex(MGraph* G, VertexType x)
{
          int x_pos = 0;      //�����±�λ��
          int flag = 0;
          for (x_pos; x_pos < G->MaxVertexNum; ++x_pos)
          {
                    if (G->Vex[x_pos] == x)           // ��Vex���ҵ��ý�㲢�����±�
                    {
                              G->Vex[x_pos] = 0;           //��������ݲ�����
                              flag = 1;
                              break;
                    }
          }
          if (flag)
          {
                    for (int i = 0; i < G->MaxVertexNum; ++i)
                    {
                              G->Edge[x_pos][i] = 0; //�����
                              G->Edge[i][x_pos] = 0;//�����
                    }
                    G->vexnum--;        //�����-1
                    return TRUE;
          }
          else
          {
                    return FALSE;
          }
}

//���ͼ��ĳ���ߵ�Ȩֵ
void ShowEdgeValue(MGraph* G, VertexType x, VertexType y)
{
          int x_pos = 0, y_pos = 0;
          /*Ѱ�ҵ�һ������x�ڱ��λ��*/
          for (x_pos; x_pos < G->MaxVertexNum; ++x_pos)
          {
                    if (G->Vex[x_pos] == x)
                    {
                              break;
                    }
          }
          /*Ѱ�ҵڶ�������y�ڱ��λ��*/
          for (y_pos; y_pos < G->MaxVertexNum; ++y_pos)
          {
                    if (G->Vex[y_pos] == x)
                    {
                              break;
                    }
          }
          if (G->Edge[x_pos][y_pos] == 0)
          {
                    printf("�ñ߲�����\n");
          }
          else if(G->Edge[x_pos][y_pos] == 1)
          {
                    printf("�ñ�ֻ��Ĭ��Ȩֵ1\n");
          }
          else
          {
                    printf("��%c%c��ȨֵΪ��%d\n", x, y, G->Edge[x_pos][y_pos]);
          }
}

/*
��ͼ��Ѱ��ĳһ��������ڽӵ�
*/
//��ͼG�ж���X�ĵ�һ���ڽӵ㣬�����򷵻ض���ţ���û���򷵻�-1
int FirstNeighbor(MGraph G, VertexType x)
{
          int x_pos = 0;
          /*Ѱ�ҵ�һ������x�ڱ��λ��*/
          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
          {
                    if (G.Vex[x_pos] == x)
                    {
                              break;
                    }
          }
          int flag = 0;       //�ж��Ƿ��ҵ�
          int TheFirst = 0;
          for (TheFirst = 0;  TheFirst < G.MaxVertexNum; ++TheFirst)
          {
                    if (G.Edge[x_pos][TheFirst] == 1)
                    {
                              flag = 1;
                              break;
                    }
          }
          if (!flag)
          {
                    return -1;          //û���ҵ�
          }
          else
          {
                    return TheFirst;    //���ر��
          }
}

//��ͼG�ж���X��һ���ڽӵ㣬���س��˶���y�������һ�������
//��y��x�����һ���ٽ�㣬�򷵻�-1
int NextNeighbor(MGraph G, VertexType x, VertexType y)
{
          int x_pos = 0, y_pos = 0;     //���ڱ���x��y��λ��
          for (int i = 0 ; i < G.MaxVertexNum; ++i)
          {
                    if (G.Vex[i] == x)
                    {
                              x_pos = i;
                    }
                    if (G.Vex[i] == y)
                    {
                              y_pos = i;
                    }
          }
          int flag = 0;       //�ж��Ƿ��ҵ�
          int TheNext = 0;
          for (TheNext = y_pos+1; TheNext < G.MaxVertexNum; ++TheNext)
          {
                    if (G.Edge[x_pos][TheNext] == 1)
                    {
                              flag = 1;
                              break;
                    }
          }
          if (!flag)
          {
                    return -1;          //û���ҵ�
          }
          else
          {
                    return TheNext;    //���ر��
          }
}

//��ͼG���ҵ������±�
int LocateVertex(MGraph* G, VertexType x)
{
          int x_pos = 0;
          for (x_pos; x_pos < G->MaxVertexNum; ++x_pos)
          {
                    if (G->Vex[x_pos] == x)
                    {
                              break;
                    }
          }
          return x_pos;
}

//ͼG������
void DestroyGraph(MGraph* G)
{
          free(G->Vex);
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    free(G->Edge[i]);
          }
          free(G->Edge);
}