#include<iostream>
#include<list>
using namespace std;

int main1()
{
	list<int> l1;//构造空的list
	list<int> l2(4, 5);//构造4个值为5的list
	list<int> l3(l2);//拷贝构造
	list<int> l4(l2.begin(), l2.end());//构造一段区间

	for (auto & e:l2)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::iterator it = l3.begin();
	for (; it != l3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	list<int>::iterator it2 = l4.begin();
	for (; it2 != l4.end(); it2++)
	{
		cout << *it2 << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}