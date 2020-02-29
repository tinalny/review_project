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

	//��posǰ����Ԫ��2
	l.insert(pos, 2);
	Print(l);

	//��posǰ����3��4
	l.insert(pos, 3, 4);
	Print(l);

	//��posǰ����[v.begin(), v.end)�����е�Ԫ��
	vector<int> v{ 33,44,55 };
	l.insert(pos, v.begin(), v.end());
	Print(l);

	//ɾ��pos����Ԫ��
	l.erase(pos);
	Print(l);

	//ɾ������[++l.begin(), --l.end()]��Ԫ��
	l.erase(++l.begin(), --l.end());
	Print(l);
}

//swap/clear
void test3(list<int> l)
{
	// ������������list
	int array1[] = { 1, 2, 3 };
	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	Print(l1);
	// ����l1��l2�е�Ԫ��
	l1.swap(l);
	Print(l1);
	Print(l);
	// ��l2�е�Ԫ�����
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
		// erase()����ִ�к�it��ָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ��丳ֵ
		l.erase(it);
		++it;
	}
}
// ����
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