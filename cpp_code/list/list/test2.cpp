#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int>& l)
{
	// ע��������õ���list�� begin() const������list��const_iterator����
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
		// *it = 10; ���벻ͨ��
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

	// ʹ���������������list�е�Ԫ��
	for (list<int>::iterator it1 = l.begin(); it1 != l.end(); it1++)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	// ʹ�÷�������������ӡlist�е�Ԫ��
	for (list<int>::reverse_iterator it2 = l.rbegin(); it2 != l.rend(); it2++)
	{
		cout << *it2 << " ";
	}
	cout << endl;

	print_list(l);
	system("pause");
	return 0;
}