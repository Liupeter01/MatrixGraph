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

//��ͼG����������(x,y)
int AddEdge_nodirect(MGraph* G, VertexType x, VertexType y);

//������ͼGɾ��һ�������(x, y)
int RemoveEdge_nodirect(MGraph* G, VertexType x, VertexType y);