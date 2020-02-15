#include"slist.h"

//初始化链表
void SListInit(SList* plist)
{
	plist->_head = NULL;
}

//头插法
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));

	//将要插入结点的值赋给cur,此时cur指向原来链表的头结点
	//新的链表的头结点即为cur
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}

//头删法
void SListPopFront(SList* plist)
{
	assert(plist);

	//判断要删除的结点是否为头结点，若是则需要一个临时结点保存头结点
	SListNode * tmp;
	if (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = tmp->_next;//将原链表头结点的下一个结点设置为头结点
		free(tmp);
	}
}

//查找一个链表中的元素pos
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next)//单链表的遍历
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}

// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));

	cur->_data = x;//创建要插入元素的值
	//待插入元素的指向下一个元素就是pos指向的下一个元素
	//将待插入的元素与下一个元素建立关系
	cur->_next = pos->_next;
	//断开pos与原来下一个元素的关系，建立pos与待插入元素的关系
	pos->_next = cur;
}

//删除pos后的一个元素
void SListEraseAfter(SListNode* pos)
{
	SListNode * tmp = pos->_next;
	//建立一个临时结点来保存pos->next，由于链表的物理地址不是连续的，不保存将会无法找到pos指向的下一个元素
	pos->_next = tmp;
	//此时将pos与pos后的第二个元素（即tmp指向的元素）建立关系
	pos->_next = tmp->_next;
	//释放掉tmp，即删除pos后的元素
	free(tmp);
}

void SListDestory(SList* plist)
{
	assert(plist);

	SListNode *tmp;
	while (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

void SListPrint(SList* plist)
{
	assert(plist);

	SListNode *cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		cout << cur->_data << "->" << " ";
	}
	cout << "NULL" << endl;
}