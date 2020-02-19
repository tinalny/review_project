#include<iostream>
using namespace std;

class A { };

class B : public A { };

class Person
{
public:
	virtual A * fun()
	{
		return new A;
	}
};

class  SeniorCard : public Person
{
public:
	virtual B * fun()
	{
		return new B;
	}
};
void func(Person & people)
{
	people.fun();
}

int main2()
{
	Person tina;
	func(tina);

	SeniorCard Mail;
	func(Mail);
	system("pause");
	return 0;
}