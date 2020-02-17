//�鲢����
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
	dealMergeSort(nums, tmp, start, mid);//����˼�룬�ȷ֣��ù���Ϊ���֡���ǰһ����
	dealMergeSort(nums, tmp, mid + 1, end);//���֡��ĺ󲿷�
										  //����˼���еġ��ϡ�
	int a = start;//ָ��ǰ�벿��Ԫ�ص�ָ��
	int b = mid + 1;//ָ���벿��Ԫ�ص�ָ��
	int c = start;//ָ����ʱ�����ָ��
				  //����ָ��ֱ�ָ�������������ʼλ�ã�a��b����ָ��ָ���Ԫ�ؽ��бȽϣ���С��Ԫ�ش�����ʱ������
	while (a <= mid && b <= end)
	{
		if (nums[a] < nums[b])//˭С��˭������ʱ�����У���ָ������ָ���1
		{
			tmp[c] = nums[a];
			a++;
		}
		else
		{
			tmp[c] = nums[b];
			b++;
		}
		c++;//���۰�Ϊ����c�����У�ָ�붼Ҫ��1
	}
	for (; a <= mid; a++, c++)//��b����Ϊ��ʱ����a������ʣ�µ�Ԫ�ض�������ʱ����c��
	{
		tmp[c] = nums[a];
	}
	for (; b <= end; b++, c++)//��a����Ϊ��ʱ����b������ʣ�µ�Ԫ�ض�������ʱ����c��
	{
		tmp[c] = nums[b];
	}

	for (int i = start; i <= end; i++)//����ʱ�����Ԫ���ڸ��ص�ԭ����������
	{
		nums[i] = tmp[i];
	}
}

//�鲢����
vector<int> MergeSort(vector<int> nums)//�����Ľӿڣ�����������������
{
	int n = nums.size();
	int * tmp = (int *)malloc(n * sizeof(int));//������ʱ�ռ�
	dealMergeSort(nums, tmp, 0, n - 1);
	free(tmp);//�ͷ���ʱ�ռ�
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