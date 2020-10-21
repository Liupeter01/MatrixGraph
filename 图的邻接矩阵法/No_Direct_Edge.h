/*
*文件名：No_Direct_Edge
*文件用途：用于处理以及操作无向边
*/

#pragma once
#include"MGraph.h"

//判断在图G中是否存在无向边(x,y)
int  Adjcent_nodirect(MGraph G, VertexType x, VertexType y);

//输出在无向图G与结点x相邻边(x,?)
void Neighbors_nodirect(MGraph G, VertexType x);

//在图G中添加无向边(x,y)，该函数不支持修改权值，使用默认权值1
int AddEdge_nodirect(MGraph* G, VertexType x, VertexType y);

//在无向图G添加一条无向边(x, y)，该函数支持修改权值
int AddEdgeNoDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value);

//在无向图G删除一条无向边(x, y)
int RemoveEdge_nodirect(MGraph* G, VertexType x, VertexType y);