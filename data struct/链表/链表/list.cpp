#include"list.h"

void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));
	//memset的调用格式：memset(void *s, int c, unsigned long n);将指针变量 s 所指向的前 n 字节的内存单元用一个“整数” c 替换
	//memset的作用：在一段内存中填充某个给定的值，一般选择0作为填充值
	memset(&plist->_head->_data, 0, sizeof(LTDataType));//数据清零
	plist->_head->_next = plist->_head->_prev = plist->_head;//下一个和上一个都没有，故都指向自己，即为初始化
}

//尾插法
void ListPushBack(List* plist, LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;
	//头结点的前一个结点（在未插入新结点时）的下一个指针域指向新插入的结点
	plist->_head->_prev->_next = cur;
	//将头结点的前一个指针指向的结点变成新插入结点的前一个指针指向的结点
	cur->_prev = plist->_head->_prev;
	//此时头结点的前一个指针指向的结点为新插入的结点
	plist->_head->_prev = cur;
	//此时新插入的结点的下一个指针指向头结点
	cur->_next = plist->_head;
}

//头插法
void ListPushFront(List* plist, LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;

	cur->_next = plist->_head->_next;//头结点的下一个指针域就是新插进来那个节点的下一个指针域，此时头结点与之前未插入结点的那个结点已经断开
	plist->_head->_next = cur;//此时头结点的下一个指针就指向新插进来的这个结点
	cur->_prev = plist->_head;//新插入的结点的前一个指针就指向了头结点
	if (plist->_head->_prev == plist->_head)//如果头结点的前一个指针域是头结点自己，那么头插进来的那个结点就是头结点的前一个指针域，
											//如果头结点的前一个指针域不是头结点自己，那么再头插进来结点，头结点的前一个指针域也不会发生变化
	{
		plist->_head->_prev = cur;
	}
}

//尾删法
void ListPopBack(List* plist)
{
	ListNode *tmp = plist->_head->_prev;//用tmp保存要删除的结点

	if (plist->_head != tmp)
	{
		//要将tmp的人际关系断裂，首先将tmp的前一个结点与tmp断裂，并且与tmp的下一个结点建立关系
		tmp->_prev->_next = plist->_head;
		//再将tmp的下一个结点与tmp的前一个结点建立关系
		tmp->_next->_prev = tmp->_prev;
		free(tmp);//释放掉tmp
	}
}  

//头删法（删除head结点后面的那个结点）
void ListPopFront(List* plist)
{
	ListNode *tmp = plist->_head->_next;//tmp即为要删除的结点

	if (tmp != plist->_head)//链表中只有一个头结点时，不进行此操作
	{
		//本来head的后一个指针指向的是tmp，当把tmp删除后，即指向tmp的下一个结点
		tmp->_prev->_next = tmp->_next;
		//tmp的下一个结点的前一个指针本来指向tmp，当把tmp删除后，即指向tmp的前一个结点
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

void ListPrint(List* plist)
{
	ListNode *cur;
	cout << "head<-->";
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)//带头双向循环链表的遍历结构
	{
	cout<< cur->_data<<"<-->"<<" ";
	}
	cout << "head" << endl;
}

void ListDestory(List* plist)
{
	ListNode *tmp = plist->_head->_prev;
	while (tmp != plist->_head)
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
		tmp = plist->_head->_prev;
	}
	free(plist->_head);
	plist->_head = NULL;
}