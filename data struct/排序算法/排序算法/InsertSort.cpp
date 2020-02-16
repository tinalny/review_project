//直接插入排序
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> InsertSort(vector<int> nums)
{
	int i, j;
	for (i = 1; i < nums.size(); i++)
	{
		int tmp = nums[i];//保存当前元素，然后和前一个元素进行比较，如果tmp比前一个元素小，则交换位置，继续和前面的元素比较，小的元素向前移
		for (j = i; j > 0 && nums[j-1] > tmp; j--)
		{
			nums[j] = nums[j - 1];
		}
		nums[j] = tmp;
	}
	return nums;
}

int main1()
{
	vector<int> nums{ 5,3,6,2,9 };

	vector<int> res = InsertSort(nums);

	for (auto &e : res)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}