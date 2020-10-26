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

//���ͼ��ĳ���ߵ�Ȩֵ
void ShowEdgeValue(MGraph* G, VertexType x, VertexType y);

//��ͼG���ҵ������±�
int LocateVertex(MGraph* G, VertexType x);

/*��ͼ��Ѱ��ĳһ��������ڽӵ�*/
//��ͼG�ж���X�ĵ�һ���ڽӵ㣬�����򷵻ض���ţ���û���򷵻�-1
int FirstNeighbor(MGraph G, VertexType x);

//��ͼG�ж���X�ĵ�һ���ڽӵ㣬���س��˶���y�������һ�������
//��y��x�����һ���ٽ�㣬�򷵻�-1
int NextNeighbor(MGraph G, VertexType x, VertexType y);

//ͼG������
void DestroyGraph(MGraph* G);