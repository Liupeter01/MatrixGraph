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

//在图G中添加有向边<x,y>
int AddEdge_direct(MGraph* G, VertexType x, VertexType y);

//在有向图G删除一条有向边<x, y>
int RemoveEdge_direct(MGraph* G, VertexType x, VertexType y);