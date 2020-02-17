//归并排序
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dealMergeSort(vector<int> nums, int * tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	dealMergeSort(nums, tmp, start, mid);//分治思想，先分，该过程为“分”的前一部分
	dealMergeSort(nums, tmp, mid + 1, end);//“分”的后部分
										  //分治思想中的“合”
	int a = start;//指向前半部分元素的指针
	int b = mid + 1;//指向后半部分元素的指针
	int c = start;//指向临时数组的指针
				  //三个指针分别指向三个数组的起始位置，a和b两个指针指向的元素进行比较，较小的元素存在临时数组中
	while (a <= mid && b <= end)
	{
		if (nums[a] < nums[b])//谁小把谁存在临时数组中，且指向它的指针加1
		{
			tmp[c] = nums[a];
			a++;
		}
		else
		{
			tmp[c] = nums[b];
			b++;
		}
		c++;//无论把为存在c数组中，指针都要加1
	}
	for (; a <= mid; a++, c++)//当b数组为空时，把a数组中剩下的元素都存在临时数组c中
	{
		tmp[c] = nums[a];
	}
	for (; b <= end; b++, c++)//当a数组为空时，把b数组中剩下的元素都存在临时数组c中
	{
		tmp[c] = nums[b];
	}

	for (int i = start; i <= end; i++)//把临时数组的元素在赋回到原来的数组中
	{
		nums[i] = tmp[i];
	}
}

//归并排序
vector<int> MergeSort(vector<int> nums)//给外界的接口，不是真正是排序函数
{
	int n = nums.size();
	int * tmp = (int *)malloc(n * sizeof(int));//申请临时空间
	dealMergeSort(nums, tmp, 0, n - 1);
	free(tmp);//释放临时空间
	return nums;
}

int main()
{
	vector<int> nums{ 3,2,5,7,6,9 };
	vector<int> res = MergeSort(nums);

	for (auto &e : res)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}