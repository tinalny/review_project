//string��ĳ��ýӿ�˵��
#include<iostream>
#include<string>
using namespace std;

//string��������������
void Teststring1()
{
	string s("hello world");
	cout << s.length() << endl;//length()��size()��������һ���ģ����Ǽ�����Ч�ַ��ĸ���
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.clear();//�ַ�����գ���s.size()���㣬���ǲ��ı�ײ�ռ�Ĵ�С
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, 'q');//����Ч�ַ��ĸ������ӵ�n(20)����������Ŀռ����ַ�'q'���
	cout << s << endl;

	s.resize(20);//����Ч�ַ��ĸ������ӵ�n(20)����������Ŀռ��� 0 ���
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.resize(5);//��s�е���Ч�ַ�������С��5
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//reserve��ı�ײ�ռ�Ĵ�С�����ǲ���ı�s���ַ�����Ч����
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.reserve(5);//reserve�Ĳ���С�ڵײ�ռ��Сʱ��reserve()��������ı�ײ�ռ�Ĵ�С
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

//string�����ķ��ʲ���
void Teststring2()
{
	string s1("hello");
	const string s2("world");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << s1 << endl;

	//s2[0] = 'W';//����ʧ�ܣ���Ϊs2��const���Ͷ��󣬲����޸�
	//cout << s2 << endl;

	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}
}

//string�������޸Ĳ���
void Teststring3()
{
	string s("tian");
	s.push_back('d');//���ַ��������һ���ַ�
	s.append("ui");//׷��һ���ַ���
	cout << s << endl;

	s += 'd';//׷��һ���ַ�
	s += "ui";//׷��һ���ַ���
	cout << s << endl;
	cout << s.c_str() << endl;//����C���Եĸ�ʽ��ӡ�ַ���

	string s1("string.cpp");
	int pos = s1.find('.');
	string s2(s1.substr(pos, s1.size() - pos));
	cout << s2 << endl;
}

int main()
{
	//Teststring1();
	//Teststring2();
	Teststring3();
	system("pause");
	return 0;
}