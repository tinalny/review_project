#include"list.h"

int main()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 7);
	ListPushBack(&list, 6);
	ListPushBack(&list, 5);
	ListPushBack(&list, 4);
	ListPrint(&list);

	ListPushBack(&list, 8);
	ListPrint(&list);

	ListPushFront(&list, 1);
	ListPushFront(&list, 2);
	ListPushFront(&list, 3);
	ListPrint(&list);

	ListPopFront(&list);
	ListPrint(&list);

	ListPopBack(&list);
	ListPrint(&list);
	ListDestory(&list);
	system("pause");
	return 0;
}