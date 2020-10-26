/*
*�ļ�����Direct_Edge
*�ļ���;�����ڴ����Լ����������
*/

#pragma once
#include"MGraph.h"

//�ж���ͼG���Ƿ���������<x,y>
int  Adjcent_direct(MGraph G, VertexType x, VertexType y);

//���������ͼG����x���ڱ�<x,?>
void Neighbors_direct(MGraph G, VertexType x);

//����ĳһ��������������
int CalculateEnterVertex(MGraph G, VertexType x);

//����ĳһ������ĳ�������
int CalculateOutVertex(MGraph G, VertexType x);

//��ͼG����������<x,y>���ú�����֧���޸�Ȩֵ��ȨֵĬ��Ϊ1
int AddEdge_direct(MGraph* G, VertexType x, VertexType y);
      
//������ͼG���һ�������(x, y)���ú���֧���޸�Ȩֵ
int AddEdgeDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value);

//������ͼGɾ��һ�������<x, y>
int RemoveEdge_direct(MGraph* G, VertexType x, VertexType y);