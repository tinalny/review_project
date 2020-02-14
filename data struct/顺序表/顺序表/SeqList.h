#pragma once
#include<iostream>
#include<cassert>
using namespace std;
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array; // 指向动态开辟的数组
	size_t size; // 有效数据个数
	size_t capicity; // 容量空间的大小
}SeqList;

void SeqListInit(SeqList* psl, size_t capacity);//初始化
void SeqListDestory(SeqList* psl);//销毁释放
void CheckCapacity(SeqList* psl);//检查存储元素是否达到上限
void SeqListPushBack(SeqList* psl, SLDataType x);//尾插法
void SeqListPopBack(SeqList* psl);//尾删法
void SeqListPushFront(SeqList* psl, SLDataType x);//头插法
void SeqListPopFront(SeqList* psl);//头删法
int SeqListFind(SeqList* psl, SLDataType x);//查找某元素所在位置
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//在某个位置插入一个元素
void SeqListErase(SeqList* psl, size_t pos);//删除某位置的元素
void SeqListRemove(SeqList* psl, SLDataType x);//删除某个值的元素
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//修个某个位置元素的值
void SeqListPrint(SeqList* psl);//打印顺序表中的元素
void SeqListBubbleSort(SeqList* psl);//冒泡排序
int SeqListBinaryFind(SeqList* psl, SLDataType x);//二分查找