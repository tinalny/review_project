#include<iostream>
#include<memory>
using namespace std;

class Date
{
public:
	Date()
	{
		cout << "Date()" << endl; 
	}
	~Date() { 
		cout << "~Date()" << endl; 
	}
	int m_year;
	int m_month;
	int m_day;
};

int main2()
{
	auto_ptr<Date> ap(new Date);
	auto_ptr<Date> copy(ap);
	// auto_ptr�����⣺�����󿽱����߸�ֵ��ǰ��Ķ����������
	ap->m_year = 2018;
	system("pause");
	return 0;
}