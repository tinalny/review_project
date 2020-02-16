//ϣ������
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ShellSort(vector<int> nums)
{
	int j;
	for (int gap = nums.size() / 2; gap; gap /= 2)//�Ƚ��з���
	{
		for (int k = 0; k < gap; k++)
		{
			for (int i = gap + k; i < nums.size(); i += gap)
			{
				int tmp = nums[i];
				for (j = i; j > 0 && nums[j - gap] > tmp; j -= gap)//ֱ�Ӳ�������
				{
					nums[j] = nums[j - gap];
				}
				nums[j] = tmp;
			}
		}
	}
	return nums;
}
int main2()
{
	vector<int> nums = { 5,3,6,2,9,6 };
	vector<int> res = ShellSort(nums);

	for (auto &e : res)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}