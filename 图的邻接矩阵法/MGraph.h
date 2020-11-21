#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

/*���������趨*/
#define VertexType char
#define EdgeType int

/*����ͨ�趨*/
#define INFINITYSIZE INT_MAX    //����ͨ

/*�ߵ�Ĭ�ϴ�С�趨*/
#define Default_Vertices_Size 10        //Ĭ�ϵĴ�С

/*�ڽӾ������ݽṹ*/
typedef struct MGraph                      //�ڽӾ������ݽṹ
{
          VertexType *Vex;                    //�������
          EdgeType **Edge;                  //��
          int vexnum;                             //��ǰ��������
          int arcnum;                              //��ǰ�ߵ�����
          int MaxVertexNum;                //���Ķ�������
}MGraph;

//////////////////////////////////////////////////////////ͼ�Ļ�����������/////////////////////////////////////////////////////////////////////
void InitGraph(MGraph* G);                 //ͼG�ĳ�ʼ��
void DestroyGraph(MGraph* G);          //ͼG������
void DisplayGraph(MGraph G);            //ͼG�����
BOOL ExtendGraphSize(MGraph* G, VertexType* arr);         //ͼG�Ŀռ�����Լ�Ĭ�Ͽռ����ݺ���
int LocateVertex(MGraph G, VertexType x);                  //��ͼG���ҵ������±�
void ShowEdgeValue(MGraph G, VertexType x, VertexType y);            //���ͼ��ĳ���ߵ�Ȩֵ

//////////////////////////////////////////////////////////ͼ�Ľ���������/////////////////////////////////////////////////////////////////////
BOOL InsertVertex(MGraph* G, VertexType x);        //��ͼG�в�����x
void CreateBatchVertex(MGraph* G, VertexType* arr);                   //��ͼG���������붥��
BOOL DeleteVertex(MGraph* G, VertexType x);                  //��ͼG��ɾ�����x

//////////////////////////////////////////////////////////ͼ���ڽӶ����������/////////////////////////////////////////////////////////////////////
/*��ͼG�ж���X�ĵ�һ���ڽӵ㣬�����򷵻ض���ţ���û���򷵻�-1*/
int FindFirstNeighbor(MGraph G, VertexType x);              //��ͼ��Ѱ��ĳһ������x�ĵ�һ���ڽӶ���y

/*��ͼG�ж���X�ĵ�һ���ڽӵ㣬���س��˶���y�������һ������ţ���y��x�����һ���ڽӵ㣬�򷵻�-1*/
int FindNextNeighbor(MGraph G, VertexType x, VertexType y);           //��ͼ��Ѱ��ĳһ������x�ĳ��˶���y����ģ��ڶ����ڽӶ���