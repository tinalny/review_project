#include<iostream>
#include<vector>
using namespace std;

#if 0
int main()
{
	vector<int> v = { 2,3,4,5 };

	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//insert�����ַ���
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
#if 0
	//v.insert(pos,val); ��posǰ����Ԫ�ص�ֵval
	v.insert(pos, 6);//��posǰ����Ԫ��6
	for (auto &e : v)
	{
		cout << e << " ";
}
	cout << endl;
#elif 0
	//v.insert(pos, n, val);//��posǰ����n��val
	v.insert(pos, 3, 5);//��posǰ����3��5
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
#endif
	vector<int> v2 = { 1,2,3,4,5 };
	//v.insert(pos, v2.begin(), v2.end());��posǰ����һ��Ԫ�ص�ֵ
	v.insert(pos, v2.begin(), v2.end());
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

#endif

#if 0
int main()
{
	vector<int> v = { 2,3,4,5 };

	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//erase�����ַ���
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
#if 0
	v.erase(pos);//ɾ��posλ�õ�Ԫ��
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
#endif
	//v.erase(arr.begin(),arr.end()); ɾ�������е�һ��Ԫ��
	v.erase(v.begin() + 2,v.end());

	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif

#if 1
int main()
{
	vector<int> v = { 2,3,4,6,7,8 };
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 6);
	
	//��pos��ɾ�����ݣ��ᵼ�µ�����ʧЧ
	//��Ϊ��pos����Ԫ��ɾ����,pos��ָ��ԭ���Ŀռ䣬��ʱ��Ԫ���Ѿ���ɾ����
	//�ռ�Ҳ���ͷţ��Ӷ����µ�����ʧЧ��
	v.erase(pos);//ɾ��pos����Ԫ��
	cout << *pos << endl;//��ʱposλ�ô���Ԫ�ز��ܷ��ʣ���������ʧЧ

	// ��posλ�ò������ݣ�����pos������ʧЧ��
	// insert�ᵼ�µ�����ʧЧ������Ϊinsert���ܻᵼ�����ݣ�
	//���ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��ˡ�
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
	system("pause");
	return 0;
}
#endif