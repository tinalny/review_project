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
	// unique_ptr�����˼·�ǳ��Ĵֱ�-��������Ҳ���ǲ��ÿ����͸�ֵ��
	unique_ptr<Date> copy(ap);
	return 0;
}