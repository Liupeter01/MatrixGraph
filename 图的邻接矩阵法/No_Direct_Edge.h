/*
*�ļ�����No_Direct_Edge
*�ļ���;�����ڴ����Լ����������
*/

#pragma once
#include"MGraph.h"

//�ж���ͼG���Ƿ���������(x,y)
int  Adjcent_nodirect(MGraph G, VertexType x, VertexType y);

//���������ͼG����x���ڱ�(x,?)
void Neighbors_nodirect(MGraph G, VertexType x);

//��ͼG����������(x,y)���ú�����֧���޸�Ȩֵ��ʹ��Ĭ��Ȩֵ1
int AddEdge_nodirect(MGraph* G, VertexType x, VertexType y);

//������ͼG���һ�������(x, y)���ú���֧���޸�Ȩֵ
int AddEdgeNoDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value);

//������ͼGɾ��һ�������(x, y)
int RemoveEdge_nodirect(MGraph* G, VertexType x, VertexType y);