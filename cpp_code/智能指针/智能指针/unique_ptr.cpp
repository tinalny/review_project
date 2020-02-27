#include<iostream>
#include<memory>
using namespace std;

struct Date
{
	int m_year;
	int m_month;
	int m_day;
};

int main()
{
	unique_ptr<Date> ap(new Date);
	// unique_ptr的设计思路非常的粗暴-防拷贝，也就是不让拷贝和赋值。
	unique_ptr<Date> copy(ap);
	return 0;
}