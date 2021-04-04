#include <iostream>
#include <random>
#include <ctime>

using namespace std;
std::mt19937 engine1; // mt19937 как один из вариантов

#include "testUnit.h"
#include "LinkedList.h"

#define ITEMS_COUNT 10
#define MAX_RANDOM_WHOLE_NUMBER 10000

int testLinkedListInt(void)
{
	engine1.seed(std::time(nullptr)); // Семя для рандома

	int arr[ITEMS_COUNT] = { 0 };

	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		arr[i] = randomWholeNumber();
	}
	cout << "*Тестирование LinkedList для типа int" << endl;
	cout << "Начальный массив int:" << endl;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		cout << "a[" << i << "] = " << arr[i] << endl;
	}
	LinkedList<int> listInt(arr, ITEMS_COUNT);
	cout << "Печатаем элементы типа int из LinkedList:" << endl;
	bool flag = true;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		flag &= listInt[i]->data == arr[i];
		cout << "listInt[" << i << "] = " << listInt[i]->data << "			flagBrakets = " << flag << endl;
	}
	flag ? cout << "Успешно пройден тест для LinkedListInt обращение по индексу" << endl : cout << "Тест LinkedListInt обращение по индексу провален!";
	//GetFirst
	cout << "Печатаем первый элемент из LinkedList с помощью GetFirst:" << listInt.GetFirst() << endl;
	listInt.GetFirst() == arr[0] ?
		cout << "Успешно пройден тест для LinkedListInt вызов последнего элемента с помощью GetFirst" << endl :
		cout << "Тест для LinkedListInt вывод последнего элемента с помощью GetFirst провален!" << endl;

	cout << "Печатаем первый элемент из LinkedList с помощью GetFirst:" << listInt.GetLast() << endl;
	listInt.GetLast() == arr[ITEMS_COUNT - 1] ?
		cout << "Успешно пройден тест для LinkedListInt вызов последнего элемента с помощью GetLast" << endl :
		cout << "Тест для LinkedListInt вывод последнего элемента с помощью GetLast провален!" << endl;

	cout << "Печатаем число элементов из LinkedList с помощью GetLength:" << listInt.GetLength() << endl;
	listInt.GetLength() == ITEMS_COUNT ?
		cout << "Успешно пройден тест для LinkedListInt вывода числа элементов с помощью GetLength" << endl :
		cout << "Тест для LinkedListInt вывод числа элементов с помощью GetLength провален!" << endl;

	cout << "Печатаем элементы типа int из LinkedList c помощью Get:" << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		flag &= listInt.Get(i) == arr[i];
		cout << "listInt.Get(" << i << ") = " << listInt.Get(i) << "			flagBrakets = " << flag << endl;
	}
	flag ? cout << "Успешно пройден тест для LinkedListInt обращение по индексу c помощью Get" << endl : cout << "Тест LinkedListInt обращение по индексу c помощью Get провален!";
	// GetSubList

	cout << "Печатаем элементы типа int из подсписка LinkedList c помощью GetSubList со 2 по lenght-2: " << endl;
	LinkedList<int>* ptrListInt2;
	ptrListInt2 = listInt.GetSubList(2, listInt.GetLength() - 2);
	for (int i = 0; i < ptrListInt2->GetLength(); i++)
	{
		flag &= ptrListInt2->Get(i) == listInt.Get(i + 2);
		cout << "ptrListInt2->Get(" << i << ") = " << ptrListInt2->Get(i) << "			flag = " << flag << endl;
	}
	flag ? cout << "Succes" << endl : cout << "Fail!";

	cout << "Тестирование Append" << endl;
	cout << "Напеччатанный наоборот arr: " << endl;
	for (int i = ITEMS_COUNT - 1; i >= 0; i--)
	{
		cout << "a[" << i << "] = " << arr[i] << endl;
	}
	cout << "Печатаем LinkedList изменённый с помощью Append: " << endl;
	for (int i = ITEMS_COUNT - 1; i >= 0; i--)
	{
		listInt.Append(arr[i]);
	}
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		cout << "listInt[" << i << "] = " << listInt.Get(i) << "			flag = " << flag << endl;
	}
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		flag &= listInt.Get(ITEMS_COUNT + i) == arr[ITEMS_COUNT - 1 - i];
	}
	flag ? cout << "Succes" << endl : cout << "Fail!";

	cout << "Тестирование Prepend" << endl;
	cout << "a[" << ITEMS_COUNT % 7 << "] = " << arr[ITEMS_COUNT % 7] << endl;
	cout << "Исходный список: " << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		cout << "listInt.Get(" << i << ") = " << listInt.Get(i) << endl;
	}
	listInt.Prepend(arr[ITEMS_COUNT % 7]);
	cout << "После применения Prepend: " << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		cout << "listInt.Get(" << i << ") = " << listInt.Get(i) << endl;
	}
	flag = (listInt.Get(0) == arr[ITEMS_COUNT % 7]) ? true : false;
	flag ? cout << "Succes" << endl : cout << "Fail!";

	cout << "Тестирование InsertAt" << endl;
	cout << "a[" << ITEMS_COUNT % 6 << "] = " << arr[ITEMS_COUNT % 6] << endl;
	cout << "Исходный список: " << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		cout << "listInt.Get(" << i << ") = " << listInt.Get(i) << endl;
	}
	listInt.InsertAt(arr[ITEMS_COUNT % 6], listInt.GetLength() % 6);
	cout << "После применения InsertAt: " << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		if (i != (listInt.GetLength() % 6)+2) cout << "listInt.Get(" << i << ") = " << listInt.Get(i) << endl;
		else cout << "Вставленный listInt.Get(" << i << ") = " << listInt.Get(i) << endl;

	}
	flag = (listInt.Get((listInt.GetLength() % 6)+2) == arr[ITEMS_COUNT % 6]) ? true : false;
	flag ? cout << "Succes" << endl : cout << "Fail!";

	cout << "Тестирование Concat" << endl;
	cout << "Исходный список: " << endl;
	for (int i = 0; i < ptrListInt2->GetLength(); i++)
	{
		cout << "listInt2[" << i << "] = " << ptrListInt2->Get(i) << endl;
	}
	cout << "Cписок для склеивания: " << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		cout << "listInt.Get[" << i << "] = " << listInt.Get(i) << endl;
	}
	int lenghtListInt2BeforeConcat = ptrListInt2->GetLength();
	ptrListInt2->Concat(&listInt);
	cout << "Cписок после склеивания: " << endl;
	for (int i = 0; i < ptrListInt2->GetLength(); i++)
	{
		flag &= i < lenghtListInt2BeforeConcat || ptrListInt2->Get(i) == listInt.Get(i- lenghtListInt2BeforeConcat);
		if (i< lenghtListInt2BeforeConcat)
			cout << "listInt.Get[" << i << "] = " << ptrListInt2->Get(i) << endl;
		else
			cout << "+listInt.Get[" << i << "] = " << ptrListInt2->Get(i) << endl;
	}
	flag ? cout << "Succes" << endl : cout << "Fail!";

	//чистим память
	//delete listInt;
	//delete (*ptrListInt2);
	if (flag)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}