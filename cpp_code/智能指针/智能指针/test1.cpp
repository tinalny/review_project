#include<iostream>
using namespace std;

struct Date
{
	int m_year;
	int m_month;
	int m_day;
};

template<class T>
class SmartPtr
{
	T* m_ptr;
public:
	SmartPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{}

	T& operator*()
	{
		return *m_ptr; 
	}

	T* operator->()
	{
		return m_ptr; 
	}

	~SmartPtr()
	{
		if (m_ptr)
			delete m_ptr;
	}
};

int main1()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 10;
	cout << *sp1 << endl;
	SmartPtr<Date> sparray(new Date);
	// ��Ҫע���������Ӧ����sparray.operator->()->m_year = 2018;
	// ����Ӧ����sparray->->m_year�����﷨��Ϊ�˿ɶ��ԣ�ʡ����һ��->
	sparray->m_year = 2018;
	sparray->m_month = 1;
	sparray->m_day = 1;
	system("pause");
	return 0;
}
