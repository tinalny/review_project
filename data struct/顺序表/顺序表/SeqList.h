#pragma once
#include<iostream>
#include<cassert>
using namespace std;
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array; // ָ��̬���ٵ�����
	size_t size; // ��Ч���ݸ���
	size_t capicity; // �����ռ�Ĵ�С
}SeqList;

void SeqListInit(SeqList* psl, size_t capacity);//��ʼ��
void SeqListDestory(SeqList* psl);//�����ͷ�
void CheckCapacity(SeqList* psl);//���洢Ԫ���Ƿ�ﵽ����
void SeqListPushBack(SeqList* psl, SLDataType x);//β�巨
void SeqListPopBack(SeqList* psl);//βɾ��
void SeqListPushFront(SeqList* psl, SLDataType x);//ͷ�巨
void SeqListPopFront(SeqList* psl);//ͷɾ��
int SeqListFind(SeqList* psl, SLDataType x);//����ĳԪ������λ��
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//��ĳ��λ�ò���һ��Ԫ��
void SeqListErase(SeqList* psl, size_t pos);//ɾ��ĳλ�õ�Ԫ��
void SeqListRemove(SeqList* psl, SLDataType x);//ɾ��ĳ��ֵ��Ԫ��
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//�޸�ĳ��λ��Ԫ�ص�ֵ
void SeqListPrint(SeqList* psl);//��ӡ˳����е�Ԫ��
void SeqListBubbleSort(SeqList* psl);//ð������
int SeqListBinaryFind(SeqList* psl, SLDataType x);//���ֲ���