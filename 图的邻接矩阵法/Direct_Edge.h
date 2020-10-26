/*
*文件名：Direct_Edge
*文件用途：用于处理以及操作有向边
*/

#pragma once
#include"MGraph.h"

//判断在图G中是否存在有向边<x,y>
int  Adjcent_direct(MGraph G, VertexType x, VertexType y);

//输出在有向图G与结点x相邻边<x,?>
void Neighbors_direct(MGraph G, VertexType x);

//计算某一个顶点的入度数量
int CalculateEnterVertex(MGraph G, VertexType x);

//计算某一个顶点的出度数量
int CalculateOutVertex(MGraph G, VertexType x);

//在图G中添加有向边<x,y>，该函数不支持修改权值，权值默认为1
int AddEdge_direct(MGraph* G, VertexType x, VertexType y);
      
//在有向图G添加一条无向边(x, y)，该函数支持修改权值
int AddEdgeDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value);

//在有向图G删除一条有向边<x, y>
int RemoveEdge_direct(MGraph* G, VertexType x, VertexType y);