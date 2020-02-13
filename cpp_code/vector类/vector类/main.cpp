#include<iostream>
#include<vector>
using namespace std;

void printvector(vector<int> v)
{
#if 0
	//����һ����auto����iterator
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
#elif 0
	//��������const����ʹ��const���������б�����ӡ
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
#endif
	//��������������������ӡ
	vector<int>::reverse_iterator it = v.rbegin();
	while (it != v.rend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
int main1()
{
	vector<int> v = { 3,4,2,5,6,8,9 };

	printvector(v);
#if 0
	vector<int> v1;//�޲ι���
	vector<int> v2(5, 3);//���첢��ʼ��5��3
	vector<int> v3(v2);//��������v2
	vector<int> v4(v3.begin(), v3.end());//����������v3

	for (auto&e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
#endif
	system("pause");
	return 0;
}