#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define VertexType char
#define EdgeType int

typedef struct MGraph
{
          VertexType *Vex;           //�������
          EdgeType **Edge;        //��
          int vexnum;         //��������
          int arcnum;         //�ߵ�����
          int MaxVertexNum;   //���Ĵ�С
}MGraph;

/*ͼG�ĳ�ʼ��*/
void InitGraph(MGraph* G, int MGraph_Size);

//��ͼG�в�����x
int InsertVertex(MGraph* G, VertexType x);

//��ͼG�и��ݶ��㼯���������붥��
void CreateBatchVertex(MGraph* G, VertexType* arr);

//��ͼG��ɾ�����x
int DeleteVertex(MGraph* G, VertexType x);

//ͼG������
void DestroyGraph(MGraph* G);