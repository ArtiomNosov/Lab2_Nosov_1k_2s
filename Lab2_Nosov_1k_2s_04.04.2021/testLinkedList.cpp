#include <iostream>
#include <random>
#include <ctime>

using namespace std;
std::mt19937 engine; // mt19937 как один из вариантов

#include "LinkedList.h"
#define ITEMS_COUNT 10
#define MAX_RANDOM_WHOLE_NUMBER 10000

int randomWholeNumber(void)
{
	unsigned int res = engine();
	if (res > INT_MAX/2)
		return (res % MAX_RANDOM_WHOLE_NUMBER);
	else
		return (-1*(res % MAX_RANDOM_WHOLE_NUMBER));
}

int testLinkedListInt(void)
{
	engine.seed(std::time(nullptr)); // Семя для рандома

	int arr[ITEMS_COUNT] = { 0 };
	
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		arr[i] = randomWholeNumber();
	}
	cout <<"*Тестирование LinkedList для типа int"<< endl;
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
		cout << "a[" << i << "] = " << listInt[i]->data<<"			flagBrakets = " << flag << endl;
	}
	flag ? cout << "Успешно пройден тест для LinkedListInt обращение по индексу" << endl : cout << "Тест LinkedListInt обращение по индексу провален!";
	//GetFirst
	cout << "Печатаем первый элемент из LinkedList с помощью GetFirst:" << listInt.GetFirst() << endl;
	listInt.GetFirst() == arr[0] ?
		cout << "Успешно пройден тест для LinkedListInt вызов последнего элемента с помощью GetFirst" << endl :
		cout << "Тест для LinkedListInt вывод последнего элемента с помощью GetFirst провален!" << endl;

	cout << "Печатаем первый элемент из LinkedList с помощью GetFirst:" << listInt.GetLast() << endl;
	listInt.GetLast() == arr[ITEMS_COUNT-1] ?
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
		cout << "a[" << i << "] = " << listInt.Get(i) << "			flagBrakets = " << flag << endl;
	}
	flag ? cout << "Успешно пройден тест для LinkedListInt обращение по индексу c помощью Get" << endl : cout << "Тест LinkedListInt обращение по индексу c помощью Get провален!";
	// GetSubList

	// TODO: Коменнтарии, убрать ашки в выводе, добавить сравнение с основным спивком, ниже исправить cout
	cout << "Печатаем элементы типа int из подсписка LinkedList c помощью GetSubList со 2 по lenght-2:" << endl;
	LinkedList<int>* ptrListInt2;
	ptrListInt2 = listInt.GetSubList(2, listInt.GetLength()-2);
	for (int i = 0; i < ptrListInt2->GetLength(); i++)
	{
		flag &= ptrListInt2->Get(i) == listInt.Get(i+2);
		cout << "a[" << i << "] = " << ptrListInt2->Get(i) << "			flagBrakets = " << flag << endl;
	}
	flag ? cout << "Успешно пройден тест для LinkedListInt обращение по индексу c помощью Get" << endl : cout << "Тест LinkedListInt обращение по индексу c помощью Get провален!";
	return 0;
}