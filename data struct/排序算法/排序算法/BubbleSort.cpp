//ð������
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> BubbleSort(vector<int> nums)
{
	for (int i = 0; i < nums.size(); i++)//��Ҫn-1�˱Ƚ�
	{
		for (int j = 0; j < nums.size() - i - 1; j++)//ÿ����Ҫn-i�αȽ�
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