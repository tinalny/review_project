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
	// 需要注意的是这里应该是sparray.operator->()->m_year = 2018;
	// 本来应该是sparray->->m_year这里语法上为了可读性，省略了一个->
	sparray->m_year = 2018;
	sparray->m_month = 1;
	sparray->m_day = 1;
	system("pause");
	return 0;
}
