//��ѡ������
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
			if (nums[j] < nums[min_index])//�ҳ���������С��Ԫ��
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