#include"MGraph.h"

/*图G的初始化*/
void InitGraph(MGraph* G,int MGraph_Size)
{
          G->MaxVertexNum = MGraph_Size;
          G->vexnum = 0;      //没有结点
          G->arcnum = 0;      //没有边
          G->Vex = (VertexType*)calloc( MGraph_Size,sizeof(VertexType) );       //初始化结点名称
          G->Edge = (EdgeType**)calloc(MGraph_Size, sizeof(EdgeType*));
          for (int i = 0; i < MGraph_Size; ++i)
          {
                    G->Edge[i] = (EdgeType*)calloc(MGraph_Size, sizeof(EdgeType));
          }
          /*初始化完毕*/
}

//在图G中插入结点x
int InsertVertex(MGraph* G, VertexType x)
{
          if (G->vexnum + 1 == G->MaxVertexNum)  //满了
          {
                    return FALSE;
          }
          else
          {
                    G->Vex[G->vexnum] = x;      //新增加一个结点
                    for (int i = 0; i < G->MaxVertexNum; ++i)
                    {
                              G->Edge[G->vexnum][i] = 0;    //行清空
                              G->Edge[i][G->vexnum] = 0;    //列清空
                    }
                    G->vexnum++;                  //结点数+1
                    return TRUE;
          }
}

//在图G中根据顶点集合批量插入顶点
void CreateBatchVertex(MGraph* G, VertexType* arr)
{
          for (VertexType* p = arr; *p != '\0'; ++p)
          {
                    if (!InsertVertex(G, *p))
                    {
                              printf("顶点%c --- 插入失败\n", *p);
                    }
          }
}

//在图G中删除结点x
int DeleteVertex(MGraph* G, VertexType x)
{
          int x_pos = 0;      //保存下标位置
          int flag = 0;
          for (x_pos; x_pos < G->MaxVertexNum; ++x_pos)
          {
                    if (G->Vex[x_pos] == x)           // 在Vex中找到该结点并保存下标
                    {
                              G->Vex[x_pos] = 0;           //代表该数据不存在
                              flag = 1;
                              break;
                    }
          }
          if (flag)
          {
                    for (int i = 0; i < G->MaxVertexNum; ++i)
                    {
                              G->Edge[x_pos][i] = 0; //行清空
                              G->Edge[i][x_pos] = 0;//列清空
                    }
                    G->vexnum--;        //结点数-1
                    return TRUE;
          }
          else
          {
                    return FALSE;
          }
}

//图G的销毁
void DestroyGraph(MGraph* G)
{
          free(G->Vex);
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    free(G->Edge[i]);
          }
          free(G->Edge);
}