#include<iostream>
#include<map>
#include<string>
using namespace std;

void MapTest()
{
	map<int, string> mp;

	mp.insert(pair<int, string>(1, "Math"));
	mp.insert(pair<int, string>(2, "Chinese"));
	mp.insert(pair<int, string>(3, "English"));

	mp.erase(1);
	mp.insert(pair<int, string>(5, "pt"));
	for (auto&e : mp)
	{ 
		cout << e.first << " " << e.second << endl;
	}
}

int main()
{
	MapTest();
	system("pause");
	return 0;
}