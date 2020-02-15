#include"slist.h"

//��ʼ������
void SListInit(SList* plist)
{
	plist->_head = NULL;
}

//ͷ�巨
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));

	//��Ҫ�������ֵ����cur,��ʱcurָ��ԭ�������ͷ���
	//�µ������ͷ��㼴Ϊcur
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}

//ͷɾ��
void SListPopFront(SList* plist)
{
	assert(plist);

	//�ж�Ҫɾ���Ľ���Ƿ�Ϊͷ��㣬��������Ҫһ����ʱ��㱣��ͷ���
	SListNode * tmp;
	if (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = tmp->_next;//��ԭ����ͷ������һ���������Ϊͷ���
		free(tmp);
	}
}

//����һ�������е�Ԫ��pos
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next)//������ı���
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}

// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));

	cur->_data = x;//����Ҫ����Ԫ�ص�ֵ
	//������Ԫ�ص�ָ����һ��Ԫ�ؾ���posָ�����һ��Ԫ��
	//���������Ԫ������һ��Ԫ�ؽ�����ϵ
	cur->_next = pos->_next;
	//�Ͽ�pos��ԭ����һ��Ԫ�صĹ�ϵ������pos�������Ԫ�صĹ�ϵ
	pos->_next = cur;
}

//ɾ��pos���һ��Ԫ��
void SListEraseAfter(SListNode* pos)
{
	SListNode * tmp = pos->_next;
	//����һ����ʱ���������pos->next����������������ַ���������ģ������潫���޷��ҵ�posָ�����һ��Ԫ��
	pos->_next = tmp;
	//��ʱ��pos��pos��ĵڶ���Ԫ�أ���tmpָ���Ԫ�أ�������ϵ
	pos->_next = tmp->_next;
	//�ͷŵ�tmp����ɾ��pos���Ԫ��
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