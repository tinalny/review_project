#include"SeqList.h"

int main()
{
	SeqList test;

	SeqListInit(&test, 10);//±ØÐë´«µØÖ·

	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 6);
	SeqListPushBack(&test, 7);
	SeqListPushBack(&test, 8);
	SeqListPushBack(&test, 9);

	SeqListPrint(&test);

	SeqListPopFront(&test);
	SeqListPrint(&test);

	SeqListPopBack(&test);
	SeqListPrint(&test);

	SeqListInsert(&test, 1, 10);
	SeqListPrint(&test);

	SeqListErase(&test, 6);
	SeqListPrint(&test);

	SeqListRemove(&test, 8);
	SeqListPrint(&test);

	SeqListModify(&test, 2, 12);
	SeqListPrint(&test);

	SeqListBubbleSort(&test);
	SeqListPrint(&test);

	cout << SeqListBinaryFind(&test, 6) << endl;

	SeqListDestory(&test);
	system("pause");
	return 0;
}