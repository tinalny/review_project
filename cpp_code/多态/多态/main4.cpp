#include<iostream>
using namespace std;

class Base1
{
public:
	virtual void func1()
	{
		cout << "Base1::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "Base1::func2()" << endl;
	}
};

class Base2
{
public:
	virtual void func1()
	{
		cout << "Base2::func1()" << endl;
	}
};

class Derive : public Base1 , public Base2
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
};

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Base b;
	Derive d;
		// ˼·��ȡ��b��d�����ͷ4bytes����������ָ�룬ǰ������˵���麯��������һ�����麯��ָ���
		//ָ�����飬���������������һ��nullptr
		// 1.��ȡb�ĵ�ַ��ǿת��һ��int*��ָ��
		// 2.�ٽ�����ȡֵ����ȡ����b����ͷ4bytes��ֵ�����ֵ����ָ������ָ��
		// 3.��ǿת��VFPTR*����Ϊ������һ����VFPTR����(�麯��ָ������)�����顣
		// 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���
		// 5.��Ҫ˵�����������ӡ���Ĵ��뾭�����������Ϊ��������ʱ�����Ĵ����ɾ�����������û��
		//��nullptr������Խ�磬���Ǳ����������⡣����ֻ��Ҫ��Ŀ¼���� - ���� - �������������ٱ���ͺ��ˡ�
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	system("pause");
	return 0;
}