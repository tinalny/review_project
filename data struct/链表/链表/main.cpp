#include"slist.h"

void ListTest()
{
	SList test;

	SListInit(&test);
	SListPushFront(&test, 1);
	SListPushFront(&test, 3);
	SListPushFront(&test, 5);
	SListPushFront(&test, 7);
	SListPushFront(&test, 9);
	SListPrint(&test);

	SListPopFront(&test);
	SListPrint(&test);

	SListInsertAfter(SListFind(&test, 3), 8);
	SListPrint(&test);

	SListEraseAfter(SListFind(&test, 8));
	SListPrint(&test);

	SListDestory(&test);
}

int main1()
{
	ListTest();
	system("pause");
	return 0;
}
