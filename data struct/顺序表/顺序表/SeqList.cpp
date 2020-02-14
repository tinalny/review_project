#include"SeqList.h"

//初始化
void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);//判空

	psl->capicity = capacity;
	psl->array = (SLDataType *)malloc(capacity * sizeof(SLDataType));//开辟动态空间

	psl->size = 0;
}

void SeqListDestory(SeqList* psl)
{
	assert(psl);

	if (psl->array)
	{
		free(psl->array);//将一个数组free后，需要将其置空（NULL）
		psl->array = NULL;
		psl->capicity = 0;//并将其开辟的空间均置为0
		psl->size = 0;
	}
}

//检查是否到达上限
void CheckCapacity(SeqList* psl)
{
	assert(psl);

	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capicity * sizeof(SLDataType));
	}
}

//尾插法
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);

	//插入一个元素需要检查是否需要进行扩容，
	//若psl->size == psl->capacity,则需要扩容
	CheckCapacity(psl);

	//尾插法即将要插入放入元素直接插到顺序表的末端，再将顺序表的大小加一
	psl->array[psl->size] = x;
	psl->size++;
}

//尾删法
void SeqListPopBack(SeqList* psl)
{
	assert(psl || psl->size);

	//直接将顺序表中有效元素的个数减一，即可删掉表中最后一个元素
	psl->size--;
}

//头插法
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);

	//头插法是将每个元素向后移动一位，即将后面的那个元素覆盖
	//再将要插入的元素赋值给表中的第一个元素，表的长度加一
	for (int i = psl->size - 1; i >= 0; i++)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}

//头删法
void SeqListPopFront(SeqList* psl)
{
	assert(psl || psl->size);

	psl->size--;//先将表的长度减一
	//头删法是将后面的一个元素向前移动，即后面的元素将前面的元素覆盖
	for (int i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}

}

//查找该元素是否在顺序表中存在
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)//判断顺序表中元素的值与该值相等，返回顺序表中的位置
		{
			return i;
		}
	}
}

//在pos后插入一个元素
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);

	CheckCapacity(psl);
	//与头插法思想一致
	for (int i = psl->size -1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

//删除指定位置的元素
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);

	psl->size--;
	for(int i =pos; i< psl->size;i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}

//删除给定值的元素
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);

	int pos = SeqListFind(psl, x);//利用find函数找到该元素的位置
	if (pos >= 0)
	{
		SeqListErase(psl, pos);//利用删除函数删掉该位置的值即可
	}
}

//修改一个指定位置元素的值
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || (pos < psl->size));

	psl->array[pos - 1] = x;
}

//打印函数
void SeqListPrint(SeqList* psl)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		cout << psl->array[i] << " ";
	}
	cout << endl; 
}

//冒泡排序
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

//二分法查找
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int left = 0;
	int right = psl->size - 1;
	int mid;

	while (left <= right)//不要在代码块内部定义变量
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

