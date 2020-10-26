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

//输出图中某条边的权值
void ShowEdgeValue(MGraph* G, VertexType x, VertexType y);

//在图G中找到顶点下标
int LocateVertex(MGraph* G, VertexType x);

/*在图中寻找某一个顶点的邻接点*/
//在图G中顶点X的第一个邻接点，若有则返回顶点号，若没有则返回-1
int FirstNeighbor(MGraph G, VertexType x);

//在图G中顶点X的第一个邻接点，返回除了顶点y以外的下一个顶点号
//若y是x的最后一个临界点，则返回-1
int NextNeighbor(MGraph G, VertexType x, VertexType y);

//图G的销毁
void DestroyGraph(MGraph* G);