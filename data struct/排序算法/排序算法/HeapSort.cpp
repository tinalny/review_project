//������ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
//���µ����㷨
static void AdjustDown(vector<int> nums, int m)
//static���κ��������ƺ�����������ֻ���ڱ��ļ�ʹ��
{
	int cur = m;
	int n;//�±�
	while (cur * 2 + 1 < nums.size())//û��Ҷ�ӽ�������
	{
		if (cur * 2 + 2 >= nums.size())//û���Һ��ӵ������������������û�����ӣ������Һ��ӵ����
		{
			n = cur * 2 + 1;//û���Һ��ӣ��������ӱȽ�
		}
		else
		{
			//�˴�Ϊ���
			if (nums[cur * 2 + 1] > nums[cur * 2 + 2])//���Һ��Ӷ����ڵ����
			{
				n = cur * 2 + 1;//������Ӵ����Һ��ӣ��������ӱȽϣ�������Һ��ӱȽ�
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (nums[cur] < nums[n])//��λ�ñ�ȷ��nΪ�±�ĺ���С������Ҫ����������ֱ������
		{
			swap(nums[cur], nums[n]);
			cur = n;
		}
		else
		{
			break;
		}
	}
}
void SwapHeap(vector<int> nums)
{
	int size = nums.size();
	if (nums.size() == 0)//�жϸö����Ƿ���Ԫ�أ����п�
	{
		return;
	}
	size--;
	//д�ɽ����ķ�ʽ����Ϊ�˶�����
	int tmp = nums[0];
	nums[0] = nums[size];//�������Ϊ�˶��ŷ��㣬ֻ��Ҫ��һ����伴��
	nums[size] = tmp;
	AdjustDown(nums, 0);
}
//��һ����������ɶѣ������ѵĹ���
vector<int> HeapSort(vector<int> nums)
{
	int i;
	int n = nums.size();
	for (i = n / 2 - 1; i >= 0; i--)//�����һ����Ҷ�ӽ�㿪ʼ��ǰ����ִ�����µ����㷨
	{
		AdjustDown(nums, i);
	}
	for (; n > 1; n--)
	{
		SwapHeap(nums);
	}
	return nums;
}

#endif

//���µ����㷨
static void AdjustDown(int *src, int size, int m)
//static���κ��������ƺ�����������ֻ���ڱ��ļ�ʹ��
{
	int cur = m;
	int n;//�±�
	while (cur * 2 + 1 < size)//û��Ҷ�ӽ�������(��һ��Ҷ�ӽ�㣺n/2+1)
	{
		if (cur * 2 + 2 >= size)//(�Һ��ӵ��±꣺2*n+2)û���Һ��ӵ������������������û�����ӣ������Һ��ӵ����
		{
			n = cur * 2 + 1;//û���Һ��ӣ��������ӱȽ�
		}
		else
		{
			//�˴�Ϊ���
			if (src[cur * 2 + 1] > src[cur * 2 + 2])//���Һ��Ӷ����ڵ����
			{
				n = cur * 2 + 1;//������Ӵ����Һ��ӣ��������ӱȽϣ�������Һ��ӱȽ�
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (src[cur] < src[n])//��λ�ñ�ȷ��nΪ�±�ĺ���С������Ҫ����������ֱ������
		{
			int tmp = src[cur];
			src[cur] = src[n];
			src[n] = tmp;
			cur = n;
		}
		else
		{
			break;
		}
	}
}
int SwapHeap(int *src, int size)
{
	if (size == 0)//�жϸö����Ƿ���Ԫ�أ����п�
	{
		return NULL;
	}
	size--;
	//д�ɽ����ķ�ʽ����Ϊ�˶�����
	int tmp = src[0];
	src[0] = src[size];//�������Ϊ�˶��ŷ��㣬ֻ��Ҫ��һ����伴��
	src[size] = tmp;
	AdjustDown(src, size, 0);
}
//��һ����������ɶѣ������ѵĹ���
int* HeapSort(int* src, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)//�����һ����Ҷ�ӽ�㿪ʼ��ǰ����ִ�����µ����㷨
	{
		AdjustDown(src, n, i);
	}
	for (; n > 1; n--)
	{
		SwapHeap(src, n);
	}
	return src;
}
int main4()
{
	int src[] = { 1,3,6,2,9,6 };
	int* res = HeapSort(src,6);

	for (int i = 0; i<6; i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}