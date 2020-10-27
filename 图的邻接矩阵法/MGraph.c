#include"MGraph.h"

//ͼG�����
void DisplayGraph(MGraph G)
{
          for (int i = 0; i < G.vexnum; ++i)
          {
                    for (int j = 0; j < G.vexnum; ++j)
                    {
                              printf("%d  ", G.Edge[i][j]);
                    }
                    printf("\n");
          }
}

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
                              G->Edge[G->vexnum][i] = MaxEdgeLength;    //������Ϊ����ͨ
                              G->Edge[i][G->vexnum] = MaxEdgeLength;    //���������Ϊ����ͨ
                    }
                    G->Edge[G->vexnum][G->vexnum] = 0;    //λ�ڶԽ����ϵ�Ԫ������Ϊ0
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

//��ͼG��ɾ�����x���ú����������������ߺ�����ߵĴ���
int DeleteVertex(MGraph* G, VertexType x)          
{
          int x_pos = 0;
          int flag = 0;
          G->Vex[x_pos] = 0;                      //ɾ��λ�ڶ��������иö���Ĵ���
          for (x_pos; x_pos < G->MaxVertexNum; ++x_pos)
          {
                    if (G->Vex[x_pos] == x)           // ��Vex���ҵ��ý�㲢�����±�
                    {
                              G->Vex[x_pos] = 0;           //ɾ��λ�ڶ��������иö���Ĵ���
                              flag = 1;
                              break;
                    }
          }
          if (flag)
          {
                    for (int i = 0; i < G->MaxVertexNum; ++i)   //���ö�������еı�ɾ��
                    {
                              G->Edge[x_pos][i] = MaxEdgeLength; //�����ɾ�����еĳ���
                              G->Edge[i][x_pos] = MaxEdgeLength;//�����ɾ�����е����                    
                    }
                    G->Edge[x_pos][x_pos] = 0;              //����λ�ڶԽ����ϵ�Ԫ��Ϊ0
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
          if (G->Edge[x_pos][y_pos] == 0 || G->Edge[x_pos][y_pos] == MaxEdgeLength)
          {
                    printf("�ñ߲�����\n");
          }
          else if(G->Edge[x_pos][y_pos] == 1)
          {
                    printf("�ñ�ʹ����Ȩͼ��Ĭ��Ȩֵ1\n");
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
          int x_pos = LocateVertex(&G, x);

          int flag = 0;       //�ж��Ƿ��ҵ�
          int TheFirst = 0;
          for (TheFirst = 0;  TheFirst < G.MaxVertexNum; ++TheFirst)
          {
                    if (G.Edge[x_pos][TheFirst] != 0 && G.Edge[x_pos][TheFirst] != MaxEdgeLength) //���������ұ�����ͨ
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
          int x_pos = LocateVertex(&G, x);     //���ڱ���x��λ��
          int y_pos = LocateVertex(&G, y);     //���ڱ���y��λ��
          int flag = 0;       //�ж��Ƿ��ҵ�
          int TheNext = 0;
          for (TheNext = y_pos + 1; TheNext < G.MaxVertexNum; ++TheNext)
          {
                    if (G.Edge[x_pos][TheNext] != 0 && G.Edge[x_pos][TheNext] != MaxEdgeLength) //���������ұ�����ͨ
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