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
	// shared_ptrͨ�����ü���֧������ָ�����Ŀ���
	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> copy(sp);
	cout << "ref count:" << sp.use_count() << endl;
	cout << "ref count:" << copy.use_count() << endl;
	return 0;
}