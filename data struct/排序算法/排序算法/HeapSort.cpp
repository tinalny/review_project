//堆排序 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
//向下调整算法
static void AdjustDown(vector<int> nums, int m)
//static修饰函数是限制函数的作用域，只能在本文件使用
{
	int cur = m;
	int n;//下标
	while (cur * 2 + 1 < nums.size())//没有叶子结点就跳出
	{
		if (cur * 2 + 2 >= nums.size())//没有右孩子的情况，二叉树不存在没有左孩子，但有右孩子的情况
		{
			n = cur * 2 + 1;//没有右孩子，即和左孩子比较
		}
		else
		{
			//此处为大堆
			if (nums[cur * 2 + 1] > nums[cur * 2 + 2])//左右孩子都存在的情况
			{
				n = cur * 2 + 1;//如果左孩子大于右孩子，即和左孩子比较，否则和右孩子比较
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (nums[cur] < nums[n])//该位置比确定n为下标的孩子小，则需要交换，否则直接跳出
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
	if (nums.size() == 0)//判断该堆中是否有元素，即判空
	{
		return;
	}
	size--;
	//写成交换的方式，是为了堆排序
	int tmp = nums[0];
	nums[0] = nums[size];//如果不是为了堆排方便，只需要这一条语句即可
	nums[size] = tmp;
	AdjustDown(nums, 0);
}
//将一个数组调整成堆，即建堆的过程
vector<int> HeapSort(vector<int> nums)
{
	int i;
	int n = nums.size();
	for (i = n / 2 - 1; i >= 0; i--)//从最后一个非叶子结点开始向前遍历执行向下调整算法
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

//向下调整算法
static void AdjustDown(int *src, int size, int m)
//static修饰函数是限制函数的作用域，只能在本文件使用
{
	int cur = m;
	int n;//下标
	while (cur * 2 + 1 < size)//没有叶子结点就跳出(第一个叶子结点：n/2+1)
	{
		if (cur * 2 + 2 >= size)//(右孩子的下标：2*n+2)没有右孩子的情况，二叉树不存在没有左孩子，但有右孩子的情况
		{
			n = cur * 2 + 1;//没有右孩子，即和左孩子比较
		}
		else
		{
			//此处为大堆
			if (src[cur * 2 + 1] > src[cur * 2 + 2])//左右孩子都存在的情况
			{
				n = cur * 2 + 1;//如果左孩子大于右孩子，即和左孩子比较，否则和右孩子比较
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (src[cur] < src[n])//该位置比确定n为下标的孩子小，则需要交换，否则直接跳出
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
	if (size == 0)//判断该堆中是否有元素，即判空
	{
		return NULL;
	}
	size--;
	//写成交换的方式，是为了堆排序
	int tmp = src[0];
	src[0] = src[size];//如果不是为了堆排方便，只需要这一条语句即可
	src[size] = tmp;
	AdjustDown(src, size, 0);
}
//将一个数组调整成堆，即建堆的过程
int* HeapSort(int* src, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)//从最后一个非叶子结点开始向前遍历执行向下调整算法
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