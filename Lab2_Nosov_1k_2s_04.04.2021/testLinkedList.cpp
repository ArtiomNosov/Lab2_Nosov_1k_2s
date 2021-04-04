#include <iostream>
#include <random>
#include <ctime>

using namespace std;
std::mt19937 engine1; // mt19937 ��� ���� �� ���������

#include "testUnit.h"
#include "LinkedList.h"

#define ITEMS_COUNT 10
#define MAX_RANDOM_WHOLE_NUMBER 10000

int testLinkedListInt(void)
{
	engine1.seed(std::time(nullptr)); // ���� ��� �������

	int arr[ITEMS_COUNT] = { 0 };

	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		arr[i] = randomWholeNumber();
	}
	cout << "*������������ LinkedList ��� ���� int" << endl;
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
		cout << "listInt[" << i << "] = " << listInt[i]->data << "			flagBrakets = " << flag << endl;
	}
	flag ? cout << "������� ������� ���� ��� LinkedListInt ��������� �� �������" << endl : cout << "���� LinkedListInt ��������� �� ������� ��������!";
	//GetFirst
	cout << "�������� ������ ������� �� LinkedList � ������� GetFirst:" << listInt.GetFirst() << endl;
	listInt.GetFirst() == arr[0] ?
		cout << "������� ������� ���� ��� LinkedListInt ����� ���������� �������� � ������� GetFirst" << endl :
		cout << "���� ��� LinkedListInt ����� ���������� �������� � ������� GetFirst ��������!" << endl;

	cout << "�������� ������ ������� �� LinkedList � ������� GetFirst:" << listInt.GetLast() << endl;
	listInt.GetLast() == arr[ITEMS_COUNT - 1] ?
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
		cout << "listInt.Get(" << i << ") = " << listInt.Get(i) << "			flagBrakets = " << flag << endl;
	}
	flag ? cout << "������� ������� ���� ��� LinkedListInt ��������� �� ������� c ������� Get" << endl : cout << "���� LinkedListInt ��������� �� ������� c ������� Get ��������!";
	// GetSubList

	cout << "�������� �������� ���� int �� ��������� LinkedList c ������� GetSubList �� 2 �� lenght-2: " << endl;
	LinkedList<int>* ptrListInt2;
	ptrListInt2 = listInt.GetSubList(2, listInt.GetLength() - 2);
	for (int i = 0; i < ptrListInt2->GetLength(); i++)
	{
		flag &= ptrListInt2->Get(i) == listInt.Get(i + 2);
		cout << "ptrListInt2->Get(" << i << ") = " << ptrListInt2->Get(i) << "			flag = " << flag << endl;
	}
	flag ? cout << "Succes" << endl : cout << "Fail!";

	cout << "������������ Append" << endl;
	cout << "������������� �������� arr: " << endl;
	for (int i = ITEMS_COUNT - 1; i >= 0; i--)
	{
		cout << "a[" << i << "] = " << arr[i] << endl;
	}
	cout << "�������� LinkedList ��������� � ������� Append: " << endl;
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

	cout << "������������ Prepend" << endl;
	cout << "a[" << ITEMS_COUNT % 7 << "] = " << arr[ITEMS_COUNT % 7] << endl;
	cout << "�������� ������: " << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		cout << "listInt.Get(" << i << ") = " << listInt.Get(i) << endl;
	}
	listInt.Prepend(arr[ITEMS_COUNT % 7]);
	cout << "����� ���������� Prepend: " << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		cout << "listInt.Get(" << i << ") = " << listInt.Get(i) << endl;
	}
	flag = (listInt.Get(0) == arr[ITEMS_COUNT % 7]) ? true : false;
	flag ? cout << "Succes" << endl : cout << "Fail!";

	cout << "������������ InsertAt" << endl;
	cout << "a[" << ITEMS_COUNT % 6 << "] = " << arr[ITEMS_COUNT % 6] << endl;
	cout << "�������� ������: " << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		cout << "listInt.Get(" << i << ") = " << listInt.Get(i) << endl;
	}
	listInt.InsertAt(arr[ITEMS_COUNT % 6], listInt.GetLength() % 6);
	cout << "����� ���������� InsertAt: " << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		if (i != (listInt.GetLength() % 6)+2) cout << "listInt.Get(" << i << ") = " << listInt.Get(i) << endl;
		else cout << "����������� listInt.Get(" << i << ") = " << listInt.Get(i) << endl;

	}
	flag = (listInt.Get((listInt.GetLength() % 6)+2) == arr[ITEMS_COUNT % 6]) ? true : false;
	flag ? cout << "Succes" << endl : cout << "Fail!";

	cout << "������������ Concat" << endl;
	cout << "�������� ������: " << endl;
	for (int i = 0; i < ptrListInt2->GetLength(); i++)
	{
		cout << "listInt2[" << i << "] = " << ptrListInt2->Get(i) << endl;
	}
	cout << "C����� ��� ����������: " << endl;
	for (int i = 0; i < listInt.GetLength(); i++)
	{
		cout << "listInt.Get[" << i << "] = " << listInt.Get(i) << endl;
	}
	int lenghtListInt2BeforeConcat = ptrListInt2->GetLength();
	ptrListInt2->Concat(&listInt);
	cout << "C����� ����� ����������: " << endl;
	for (int i = 0; i < ptrListInt2->GetLength(); i++)
	{
		flag &= i < lenghtListInt2BeforeConcat || ptrListInt2->Get(i) == listInt.Get(i- lenghtListInt2BeforeConcat);
		if (i< lenghtListInt2BeforeConcat)
			cout << "listInt.Get[" << i << "] = " << ptrListInt2->Get(i) << endl;
		else
			cout << "+listInt.Get[" << i << "] = " << ptrListInt2->Get(i) << endl;
	}
	flag ? cout << "Succes" << endl : cout << "Fail!";

	//������ ������
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