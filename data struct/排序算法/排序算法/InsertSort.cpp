//ֱ�Ӳ�������
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> InsertSort(vector<int> nums)
{
	int i, j;
	for (i = 1; i < nums.size(); i++)
	{
		int tmp = nums[i];//���浱ǰԪ�أ�Ȼ���ǰһ��Ԫ�ؽ��бȽϣ����tmp��ǰһ��Ԫ��С���򽻻�λ�ã�������ǰ���Ԫ�رȽϣ�С��Ԫ����ǰ��
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