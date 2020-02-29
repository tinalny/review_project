#include<iostream>
#include<list>
#include<vector>
using namespace std;

void Print(list<int> l)
{
	list<int>::iterator it = l.begin();
	for (; it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//push front/push back/pop front/pop back
void test1(list<int> l)
{
	l.push_back(9);
	Print(l);

	l.push_front(0);
	Print(l);

	l.pop_back();
	Print(l);

	l.pop_front();
	Print(l);
}

//insert/erase
void test2(list<int> l)
{
	list<int>::iterator pos = ++l.begin();
	cout << *pos << endl;

	//在pos前插入元素2
	l.insert(pos, 2);
	Print(l);

	//在pos前插入3个4
	l.insert(pos, 3, 4);
	Print(l);

	//在pos前插入[v.begin(), v.end)区间中的元素
	vector<int> v{ 33,44,55 };
	l.insert(pos, v.begin(), v.end());
	Print(l);

	//删除pos处的元素
	l.erase(pos);
	Print(l);

	//删除区间[++l.begin(), --l.end()]的元素
	l.erase(++l.begin(), --l.end());
	Print(l);
}

//swap/clear
void test3(list<int> l)
{
	// 用数组来构造list
	int array1[] = { 1, 2, 3 };
	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	Print(l1);
	// 交换l1和l2中的元素
	l1.swap(l);
	Print(l1);
	Print(l);
	// 将l2中的元素清空
	l.clear();
	cout << l.size() << endl;
}

void test4()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给其赋值
		l.erase(it);
		++it;
	}
}
// 改正
void test5()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0])); 

	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it++); // it = l.erase(it);
	}
}

int main()
{
	int arr[] = { 2,3,4,5,6,7 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Print(l);

	//test1(l);
	//test2(l);
	//test3(l);

	test4();
	test5();
	system("pause");
	return 0;
}