#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int>& l)
{
	// 注意这里调用的是list的 begin() const，返回list的const_iterator对象
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
		// *it = 10; 编译不通过
	}
	cout << endl;
}

int main2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	cout << l.size() << endl;
	cout << l.empty() << endl;

	cout << l.front() << endl;
	cout << l.back() << endl;

	// 使用正向迭代器正向list中的元素
	for (list<int>::iterator it1 = l.begin(); it1 != l.end(); it1++)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	// 使用反向迭代器逆向打印list中的元素
	for (list<int>::reverse_iterator it2 = l.rbegin(); it2 != l.rend(); it2++)
	{
		cout << *it2 << " ";
	}
	cout << endl;

	print_list(l);
	system("pause");
	return 0;
}