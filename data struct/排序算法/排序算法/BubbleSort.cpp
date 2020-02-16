//冒泡排序
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> BubbleSort(vector<int> nums)
{
	for (int i = 0; i < nums.size(); i++)//需要n-1趟比较
	{
		for (int j = 0; j < nums.size() - i - 1; j++)//每趟需要n-i次比较
		{
			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
			}
		}
	}
	return nums;
}
int main()
{
	vector<int> nums{ 3,5,1,4,7 };
	vector<int> res = BubbleSort(nums);

	for (auto &e : res)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}