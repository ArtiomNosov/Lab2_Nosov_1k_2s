#include <iostream>
#include <random>
using namespace std;

#include "LinkedList.h"
#define ITEMS_COUNT 10

int testLinkedListInt(void)
{
	int arr[ITEMS_COUNT] = { 0 };
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		arr[i] = rand();
	}
	cout <<"*Тестирование LinkedList для типа int"<< endl;
	cout << "Начальный массив int:" << endl;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		cout << "a[" << i << "] = " << arr[i] << endl;
	}
	LinkedList<int> listInt(arr, ITEMS_COUNT);
	return 0;
}