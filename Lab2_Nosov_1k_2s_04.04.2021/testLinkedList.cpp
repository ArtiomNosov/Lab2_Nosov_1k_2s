#include <iostream>
#include <random>
#include <ctime>

using namespace std;
std::mt19937 engine; // mt19937 ��� ���� �� ���������

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
	engine.seed(std::time(nullptr)); // ���� ��� �������

	int arr[ITEMS_COUNT] = { 0 };
	
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		arr[i] = randomWholeNumber();
	}
	cout <<"*������������ LinkedList ��� ���� int"<< endl;
	cout << "��������� ������ int:" << endl;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		cout << "a[" << i << "] = " << arr[i] << endl;
	}
	LinkedList<int> listInt(arr, ITEMS_COUNT);
	cout << "�������� �������� ���� int �� LinkedList:" << endl;
	bool flag = true;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		flag &= listInt[i]->data == arr[i];
		cout << "a[" << i << "] = " << listInt[i]->data<<"			flagBrakets = " << flag << endl;
	}
	flag ? cout << "������� ������� ���� ��� LinkedListInt ��������� �� �������" << endl : cout << "���� LinkedListInt ��������� �� ������� ��������!";
	//GetFirst
	cout << "�������� ������ ������� �� LinkedList � ������� GetFirst:" << listInt.GetFirst() << endl;
	listInt.GetFirst() == arr[0] ?
		cout << "������� ������� ���� ��� LinkedListInt ����� ���������� �������� � ������� GetFirst" << endl :
		cout << "���� ��� LinkedListInt ����� ���������� �������� � ������� GetFirst ��������!" << endl;

	cout << "�������� ������ ������� �� LinkedList � ������� GetFirst:" << listInt.GetLast() << endl;
	listInt.GetLast() == arr[ITEMS_COUNT-1] ?
		cout << "������� ������� ���� ��� LinkedListInt ����� ���������� �������� � ������� GetLast" << endl :
		cout << "���� ��� LinkedListInt ����� ���������� �������� � ������� GetLast ��������!" << endl;

	cout << "�������� ����� ��������� �� LinkedList � ������� GetLength:" << listInt.GetLength() << endl;
	listInt.GetLength() == ITEMS_COUNT ?
		cout << "������� ������� ���� ��� LinkedListInt ������ ����� ��������� � ������� GetLength" << endl :
		cout << "���� ��� LinkedListInt ����� ����� ��������� � ������� GetLength ��������!" << endl;

	cout << "�������� �������� ���� int �� LinkedList c ������� Get:" << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		flag &= listInt.Get(i) == arr[i];
		cout << "a[" << i << "] = " << listInt.Get(i) << "			flagBrakets = " << flag << endl;
	}
	flag ? cout << "������� ������� ���� ��� LinkedListInt ��������� �� ������� c ������� Get" << endl : cout << "���� LinkedListInt ��������� �� ������� c ������� Get ��������!";
	// GetSubList

	// TODO: �����������, ������ ���� � ������, �������� ��������� � �������� �������, ���� ��������� cout
	cout << "�������� �������� ���� int �� ��������� LinkedList c ������� GetSubList �� 2 �� lenght-2:" << endl;
	LinkedList<int>* ptrListInt2;
	ptrListInt2 = listInt.GetSubList(2, listInt.GetLength()-2);
	for (int i = 0; i < ptrListInt2->GetLength(); i++)
	{
		flag &= ptrListInt2->Get(i) == listInt.Get(i+2);
		cout << "a[" << i << "] = " << ptrListInt2->Get(i) << "			flagBrakets = " << flag << endl;
	}
	flag ? cout << "������� ������� ���� ��� LinkedListInt ��������� �� ������� c ������� Get" << endl : cout << "���� LinkedListInt ��������� �� ������� c ������� Get ��������!";
	return 0;
}