#include<iostream>
using namespace std;
/*
//static_cast
int main()
{
	double d = 3.4;
	int i = static_cast<int>(d);

	cout << "d: " << d << endl;
	cout << "i: " << i << endl;

	system("pause");
	return 0;
}

//reinterpret_cast
typedef void(*FUNC)();
int DoSomething(int i)
{
	cout << "DoSomething" << endl;
	return 0;
}

void Test()
{
	// reinterpret_cast���Ա�������FUNC�Ķ��巽ʽȥ����DoSomething����
	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������
	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�������������ʱ�������ȷ���Ľ��
	//
	FUNC f = reinterpret_cast< FUNC>(DoSomething);
	f();
}

//const_cast
void Test()
{
	const int m = 6;
	int* p = const_cast< int*>(&m);
	*p = 3;
	cout << m << endl;
}

//dynamic_cast
class A
{
public:
	virtual void f() 
	{

	}
};

class B : public A
{

};

void fun(A* pa)
{
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main()
{
	A a;
	B b;
	fun(&a);
	fun(&b);
	system("pause");
	return 0;
}
*/
class A
{
public:
	explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};

int main()
{
	A a1(1);
	// ��ʽת��-> A tmp(1); A a2(tmp);
	A a2 = 1;//�������
}
