//简单选择排序
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> SelectSort(vector<int> nums)
{
	for (int i = 0; i < nums.size()-1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[j] < nums[min_index])//找出数组中最小的元素
			{
				swap(nums[j], nums[min_index]);
			}
		}
	}
	return nums;
}
int main3()
{
	vector<int> nums = { 1,3,6,2,9,6 };
	vector<int> res = SelectSort(nums);

	for (auto &e : res)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}