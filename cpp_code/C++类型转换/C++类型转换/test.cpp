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
	// reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
	// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
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
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
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
	// 隐式转换-> A tmp(1); A a2(tmp);
	A a2 = 1;//编译错误
}
