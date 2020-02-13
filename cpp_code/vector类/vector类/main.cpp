#include<iostream>
#include<vector>
using namespace std;

void printvector(vector<int> v)
{
#if 0
	//方法一：用auto代替iterator
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
#elif 0
	//方法二：const对象使用const迭代器进行遍历打印
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
#endif
	//反向迭代器，反向遍历打印
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
	vector<int> v1;//无参构造
	vector<int> v2(5, 3);//构造并初始化5个3
	vector<int> v3(v2);//拷贝构造v2
	vector<int> v4(v3.begin(), v3.end());//迭代器构造v3

	for (auto&e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
#endif
	system("pause");
	return 0;
}