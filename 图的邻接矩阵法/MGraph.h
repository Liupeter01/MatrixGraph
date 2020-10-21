#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define VertexType char
#define EdgeType int

typedef struct MGraph
{
          VertexType *Vex;           //结点名称
          EdgeType **Edge;        //边
          int vexnum;         //结点的数量
          int arcnum;         //边的数量
          int MaxVertexNum;   //最大的大小
}MGraph;

/*图G的初始化*/
void InitGraph(MGraph* G, int MGraph_Size);

//在图G中插入结点x
int InsertVertex(MGraph* G, VertexType x);

//在图G中根据顶点集合批量插入顶点
void CreateBatchVertex(MGraph* G, VertexType* arr);

//在图G中删除结点x
int DeleteVertex(MGraph* G, VertexType x);

//图G的销毁
void DestroyGraph(MGraph* G);