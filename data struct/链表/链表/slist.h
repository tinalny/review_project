#pragma once
#include<iostream>
#include<cassert>
#include<cstring>
using namespace std;

// 1����ͷ�����ѭ��������ɾ���ʵ��
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);//��ʼ������
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);
void SListDestory(SList* plist);
void SListPrint(SList* plist);
