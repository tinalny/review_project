#include"list.h"

void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));
	//memset�ĵ��ø�ʽ��memset(void *s, int c, unsigned long n);��ָ����� s ��ָ���ǰ n �ֽڵ��ڴ浥Ԫ��һ���������� c �滻
	//memset�����ã���һ���ڴ������ĳ��������ֵ��һ��ѡ��0��Ϊ���ֵ
	memset(&plist->_head->_data, 0, sizeof(LTDataType));//��������
	plist->_head->_next = plist->_head->_prev = plist->_head;//��һ������һ����û�У��ʶ�ָ���Լ�����Ϊ��ʼ��
}

//β�巨
void ListPushBack(List* plist, LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;
	//ͷ����ǰһ����㣨��δ�����½��ʱ������һ��ָ����ָ���²���Ľ��
	plist->_head->_prev->_next = cur;
	//��ͷ����ǰһ��ָ��ָ��Ľ�����²������ǰһ��ָ��ָ��Ľ��
	cur->_prev = plist->_head->_prev;
	//��ʱͷ����ǰһ��ָ��ָ��Ľ��Ϊ�²���Ľ��
	plist->_head->_prev = cur;
	//��ʱ�²���Ľ�����һ��ָ��ָ��ͷ���
	cur->_next = plist->_head;
}

//ͷ�巨
void ListPushFront(List* plist, LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;

	cur->_next = plist->_head->_next;//ͷ������һ��ָ��������²�����Ǹ��ڵ����һ��ָ���򣬴�ʱͷ�����֮ǰδ��������Ǹ�����Ѿ��Ͽ�
	plist->_head->_next = cur;//��ʱͷ������һ��ָ���ָ���²������������
	cur->_prev = plist->_head;//�²���Ľ���ǰһ��ָ���ָ����ͷ���
	if (plist->_head->_prev == plist->_head)//���ͷ����ǰһ��ָ������ͷ����Լ�����ôͷ��������Ǹ�������ͷ����ǰһ��ָ����
											//���ͷ����ǰһ��ָ������ͷ����Լ�����ô��ͷ�������㣬ͷ����ǰһ��ָ����Ҳ���ᷢ���仯
	{
		plist->_head->_prev = cur;
	}
}

//βɾ��
void ListPopBack(List* plist)
{
	ListNode *tmp = plist->_head->_prev;//��tmp����Ҫɾ���Ľ��

	if (plist->_head != tmp)
	{
		//Ҫ��tmp���˼ʹ�ϵ���ѣ����Ƚ�tmp��ǰһ�������tmp���ѣ�������tmp����һ����㽨����ϵ
		tmp->_prev->_next = plist->_head;
		//�ٽ�tmp����һ�������tmp��ǰһ����㽨����ϵ
		tmp->_next->_prev = tmp->_prev;
		free(tmp);//�ͷŵ�tmp
	}
}  

//ͷɾ����ɾ��head��������Ǹ���㣩
void ListPopFront(List* plist)
{
	ListNode *tmp = plist->_head->_next;//tmp��ΪҪɾ���Ľ��

	if (tmp != plist->_head)//������ֻ��һ��ͷ���ʱ�������д˲���
	{
		//����head�ĺ�һ��ָ��ָ�����tmp������tmpɾ���󣬼�ָ��tmp����һ�����
		tmp->_prev->_next = tmp->_next;
		//tmp����һ������ǰһ��ָ�뱾��ָ��tmp������tmpɾ���󣬼�ָ��tmp��ǰһ�����
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

void ListPrint(List* plist)
{
	ListNode *cur;
	cout << "head<-->";
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)//��ͷ˫��ѭ������ı����ṹ
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