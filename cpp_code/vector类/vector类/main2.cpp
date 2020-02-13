#include<iostream>
#include<vector>
using namespace std;

#if 0
int main()
{
	vector<int> v = { 2,3,4,5 };

	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//insert的三种方法
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
#if 0
	//v.insert(pos,val); 在pos前插入元素的值val
	v.insert(pos, 6);//在pos前插入元素6
	for (auto &e : v)
	{
		cout << e << " ";
}
	cout << endl;
#elif 0
	//v.insert(pos, n, val);//在pos前插入n个val
	v.insert(pos, 3, 5);//在pos前插入3个5
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
#endif
	vector<int> v2 = { 1,2,3,4,5 };
	//v.insert(pos, v2.begin(), v2.end());在pos前插入一段元素的值
	v.insert(pos, v2.begin(), v2.end());
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

#endif

#if 0
int main()
{
	vector<int> v = { 2,3,4,5 };

	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//erase的两种方法
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
#if 0
	v.erase(pos);//删除pos位置的元素
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
#endif
	//v.erase(arr.begin(),arr.end()); 删除数组中的一段元素
	v.erase(v.begin() + 2,v.end());

	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif

#if 1
int main()
{
	vector<int> v = { 2,3,4,6,7,8 };
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 6);
	
	//在pos处删除数据，会导致迭代器失效
	//因为把pos处的元素删除后,pos还指向原来的空间，此时的元素已经被删除，
	//空间也被释放，从而导致迭代器失效。
	v.erase(pos);//删除pos处的元素
	cout << *pos << endl;//此时pos位置处的元素不能访问，即迭代器失效

	// 在pos位置插入数据，导致pos迭代器失效。
	// insert会导致迭代器失效，是因为insert可能会导致增容，
	//增容后pos还指向原来的空间，而原来的空间已经释放了。
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // 此处会导致非法访问
	system("pause");
	return 0;
}
#endif