//string类的常用接口说明
#include<iostream>
#include<string>
using namespace std;

//string类对象的容量操作
void Teststring1()
{
	string s("hello world");
	cout << s.length() << endl;//length()与size()的作用是一样的，都是计算有效字符的个数
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.clear();//字符串清空，将s.size()清零，但是不改变底层空间的大小
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, 'q');//将有效字符的个数增加到n(20)个，多出来的空间用字符'q'填充
	cout << s << endl;

	s.resize(20);//将有效字符的个数增加到n(20)个，多出来的空间用 0 填充
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.resize(5);//将s中的有效字符个数缩小到5
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//reserve会改变底层空间的大小，但是不会改变s中字符的有效个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.reserve(5);//reserve的参数小于底层空间大小时，reserve()函数不会改变底层空间的大小
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

//string类对象的访问操作
void Teststring2()
{
	string s1("hello");
	const string s2("world");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << s1 << endl;

	//s2[0] = 'W';//编译失败，因为s2是const类型对象，不能修改
	//cout << s2 << endl;

	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}
}

//string类对象的修改操作
void Teststring3()
{
	string s("tian");
	s.push_back('d');//在字符串后插入一个字符
	s.append("ui");//追加一个字符串
	cout << s << endl;

	s += 'd';//追加一个字符
	s += "ui";//追加一个字符串
	cout << s << endl;
	cout << s.c_str() << endl;//按照C语言的格式打印字符串

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