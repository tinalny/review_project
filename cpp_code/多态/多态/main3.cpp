#include<iostream>
using namespace std;

class Base
{
	int m_b = 1;
public:
	virtual void fun1()
	{
		cout << "Base::fun1()" << endl;
	}
	virtual void fun2()
	{
		cout << "Base::fun2()" << endl;
	}
	void fun3()
	{
		cout << "Base::fun3" << endl;
	}
};

class Test : public Base
{
	int m_t = 2;
public:
	virtual void fun1()
	{
		cout << "Test::fun1()" << endl;
	}
};

int main3()
{
	Base b;
	Test t;
	b.fun1();
	b.fun2();
	b.fun3();
	t.fun1();
	t.fun2();
	t.fun3();
	system("pause");
	return 0;
}