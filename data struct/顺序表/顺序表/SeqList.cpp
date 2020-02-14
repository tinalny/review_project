#include"SeqList.h"

//��ʼ��
void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);//�п�

	psl->capicity = capacity;
	psl->array = (SLDataType *)malloc(capacity * sizeof(SLDataType));//���ٶ�̬�ռ�

	psl->size = 0;
}

void SeqListDestory(SeqList* psl)
{
	assert(psl);

	if (psl->array)
	{
		free(psl->array);//��һ������free����Ҫ�����ÿգ�NULL��
		psl->array = NULL;
		psl->capicity = 0;//�����俪�ٵĿռ����Ϊ0
		psl->size = 0;
	}
}

//����Ƿ񵽴�����
void CheckCapacity(SeqList* psl)
{
	assert(psl);

	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capicity * sizeof(SLDataType));
	}
}

//β�巨
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);

	//����һ��Ԫ����Ҫ����Ƿ���Ҫ�������ݣ�
	//��psl->size == psl->capacity,����Ҫ����
	CheckCapacity(psl);

	//β�巨����Ҫ�������Ԫ��ֱ�Ӳ嵽˳����ĩ�ˣ��ٽ�˳���Ĵ�С��һ
	psl->array[psl->size] = x;
	psl->size++;
}

//βɾ��
void SeqListPopBack(SeqList* psl)
{
	assert(psl || psl->size);

	//ֱ�ӽ�˳�������ЧԪ�صĸ�����һ������ɾ���������һ��Ԫ��
	psl->size--;
}

//ͷ�巨
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);

	//ͷ�巨�ǽ�ÿ��Ԫ������ƶ�һλ������������Ǹ�Ԫ�ظ���
	//�ٽ�Ҫ�����Ԫ�ظ�ֵ�����еĵ�һ��Ԫ�أ���ĳ��ȼ�һ
	for (int i = psl->size - 1; i >= 0; i++)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}

//ͷɾ��
void SeqListPopFront(SeqList* psl)
{
	assert(psl || psl->size);

	psl->size--;//�Ƚ���ĳ��ȼ�һ
	//ͷɾ���ǽ������һ��Ԫ����ǰ�ƶ����������Ԫ�ؽ�ǰ���Ԫ�ظ���
	for (int i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}

}

//���Ҹ�Ԫ���Ƿ���˳����д���
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)//�ж�˳�����Ԫ�ص�ֵ���ֵ��ȣ�����˳����е�λ��
		{
			return i;
		}
	}
}

//��pos�����һ��Ԫ��
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);

	CheckCapacity(psl);
	//��ͷ�巨˼��һ��
	for (int i = psl->size -1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

//ɾ��ָ��λ�õ�Ԫ��
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);

	psl->size--;
	for(int i =pos; i< psl->size;i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}

//ɾ������ֵ��Ԫ��
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);

	int pos = SeqListFind(psl, x);//����find�����ҵ���Ԫ�ص�λ��
	if (pos >= 0)
	{
		SeqListErase(psl, pos);//����ɾ������ɾ����λ�õ�ֵ����
	}
}

//�޸�һ��ָ��λ��Ԫ�ص�ֵ
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || (pos < psl->size));

	psl->array[pos - 1] = x;
}

//��ӡ����
void SeqListPrint(SeqList* psl)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		cout << psl->array[i] << " ";
	}
	cout << endl; 
}

//ð������
void SeqListBubbleSort(SeqList* psl)
{	
	assert(psl);
	SLDataType tmp;

	for (int i = 0; i < psl->size - 1; i++)
	{
		for (int j = 0; j < psl->size - 1 - i; j++)
		{
			if (psl->array[j] > psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}

//���ַ�����
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int left = 0;
	int right = psl->size - 1;
	int mid;

	while (left <= right)//��Ҫ�ڴ�����ڲ��������
	{
		mid = (left + right) / 2;
		if (psl->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->array[mid]>x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
}

