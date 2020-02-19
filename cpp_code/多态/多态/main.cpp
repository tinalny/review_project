#include<iostream>
using namespace std;

class Person
{
public:
	virtual void BrushBusCard()
	{
		cout << "°ë¼Û" << endl;
	}
};

class  SeniorCard : public Person
{
public:
	virtual void BrushBusCard() = 0
	{
		cout << "Ãâ·Ñ" << endl;
	}
};

void Func(Person & people)
{
	people.BrushBusCard();
}

int main1()
{

	system("pause");
	return 0;
}