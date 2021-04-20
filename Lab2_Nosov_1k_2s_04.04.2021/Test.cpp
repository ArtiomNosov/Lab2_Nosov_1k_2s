#define BOOST_TEST_MODULE mytests
#define ITEMS_COUNT 10
#include <boost/test/included/unit_test.hpp>

#include "DynamicArray.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Queque.h"
#include "MyComplex.h"

complex mupFuncComplex(complex a)
{
	return a * a;
}

bool whereFunc(complex a)
{
	complex d {2.0, 2.0};
	return (a == d);
}
BOOST_AUTO_TEST_CASE(testDynamicArray)
{
	char arr[ITEMS_COUNT] = { 0 };

	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		arr[i] = i+40;
	}
	DynamicArray<char> DynArr1(arr, ITEMS_COUNT);
	DynamicArray<char> DynArr2(ITEMS_COUNT);
	DynamicArray<char> DynArr3(DynArr1);
	// Test for ResizeRight
	DynArr1.ResizeRight(11);
	BOOST_CHECK(DynArr1.GetSize()==11);
	DynArr1.Set(0, arr[0]);
	BOOST_CHECK(DynArr1.Get(0) == arr[0]);
	int elemSum1 = 0;
	int elemSum2 = 0;
	for (int i = 0; i < 11; i++)
	{
		elemSum1 += DynArr1.Get(i);
	}
	for (int i = 1; i < 11; i++)
	{
		elemSum2 += DynArr1.Get(i);
	}
	BOOST_CHECK(elemSum1 == elemSum2+arr[0]);
}

BOOST_AUTO_TEST_CASE(testArraySequence)
{
	complex complexArr[ITEMS_COUNT];
	complex endIndex(ITEMS_COUNT, ITEMS_COUNT);
	complex add(1, 1);
	int counterJ = 0;
	for (complex i(0, 0); i < endIndex; i += add, counterJ++)
	{
		complexArr[counterJ] = i;
	}
	// Тест ArraySequence()
	ArraySequence<complex>* arrSeq1 = new ArraySequence<complex>;
	ArraySequence<complex>* arrSeq2 = new ArraySequence<complex>;
	// Тест ArraySequence(T* arr, int count)
	ArraySequence<complex>* arrSeq3 = new ArraySequence<complex>(complexArr, ITEMS_COUNT);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(arrSeq3->Get(i) == complexArr[i]);
	}
	// Тест ArraySequence(ArraySequence <T>& list)
	ArraySequence<complex>* arrSeq4 = new ArraySequence<complex>(*arrSeq3);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(arrSeq4->Get(i) == arrSeq3->Get(i));
	}
	// Тест T GetFirst()
	BOOST_CHECK(arrSeq4->GetFirst() == complexArr[0]);
	// Тест T GetLast()
	BOOST_CHECK(arrSeq4->GetLast() == complexArr[ITEMS_COUNT-1]);
	// Тест T Get(int index)
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(arrSeq4->Get(i) == arrSeq3->Get(i));
	}
	// Тест ArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
	delete arrSeq1;
	int indexOne = 1;
	int indexTwo = (arrSeq3->GetLength() )/ 2;
	int difOneTwo = indexTwo - indexOne;
	arrSeq1 = arrSeq3->GetSubsequence(indexOne, indexTwo);
	for (int i = 0; i < difOneTwo; i++)
	{
		BOOST_CHECK(arrSeq1->Get(i) == arrSeq3->Get(i+ indexOne));
	}
	// Тест GetLength()
	BOOST_CHECK(arrSeq3->GetLength() == ITEMS_COUNT);
	// Тест Set(int index, T value)
	arrSeq3->Set(0, arrSeq3->GetLast());
	BOOST_CHECK(arrSeq3->GetFirst() == arrSeq3->GetLast());
	// Тест void Append(T item)
	arrSeq3->Append(arrSeq3->GetFirst());
	BOOST_CHECK(arrSeq3->Get(ITEMS_COUNT) == arrSeq3->GetFirst());
	// Тест Prepend(T item)
	arrSeq3->Prepend(arrSeq3->GetFirst());
	BOOST_CHECK(arrSeq3->Get(0) == arrSeq3->GetFirst());
	// Тест void InsertAt(T item, int index)
	int lenghtInsert = arrSeq3->GetLength();
	complex elemInsert = arrSeq3->GetLast() + arrSeq3->GetFirst();
	complex elem0 = arrSeq3->GetFirst();
	complex elem1 = arrSeq3->Get(1);
	arrSeq3->InsertAt(elemInsert, 0);
	BOOST_CHECK(lenghtInsert + 1 == arrSeq3->GetLength());
	BOOST_CHECK(arrSeq3->GetFirst() == elem0);
	BOOST_CHECK(arrSeq3->Get(1) == elemInsert);
	BOOST_CHECK(arrSeq3->Get(2) == elem1);
	// Тест Sequence <T>* Concat(Sequence <T>* list)
	delete arrSeq2;
	arrSeq2 = new ArraySequence<complex>(*arrSeq3);
	arrSeq3->Concat(arrSeq4);
	for (int i = 0; i < arrSeq2->GetLength(); i++)
	{
		BOOST_CHECK(arrSeq3->Get(i) == arrSeq2->Get(i));
	}
	for (int i = 0; i < arrSeq4->GetLength(); i++)
	{
		BOOST_CHECK(arrSeq3->Get(i + arrSeq2->GetLength()) == arrSeq4->Get(i));
	}
	// Тест void Resize(int newSize)
	int sizeBefResizeArr3 = arrSeq3->GetLength();
	arrSeq3->Resize(sizeBefResizeArr3+1);
	BOOST_CHECK(arrSeq3->GetLength() == sizeBefResizeArr3 + 1);
	// Тест void ResizeRight(int newSize)
	int sizeBefRightResizeArr3 = arrSeq3->GetLength();
	arrSeq3->ResizeRight(sizeBefResizeArr3 + 1);
	BOOST_CHECK(arrSeq3->GetLength() == sizeBefResizeArr3 + 1);
}

BOOST_AUTO_TEST_CASE(testLinkedListSequence)
{
	complex complexArr[ITEMS_COUNT];
	complex endIndex(ITEMS_COUNT, ITEMS_COUNT);
	complex add(1, 1);
	int counterJ = 0;
	for (complex i(0, 0); i < endIndex; i += add, counterJ++)
	{
		complexArr[counterJ] = i;
	}
	// Тест LinkedListSequence()
	LinkedListSequence<complex>* linkedListSeq1 = new LinkedListSequence<complex>;
	// Тест LinkedListSequence(T* items, int count)
	LinkedListSequence<complex>* linkedListSeq2 = new LinkedListSequence<complex>(complexArr, ITEMS_COUNT);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(linkedListSeq2->Get(i) == complexArr[i]);
	}
	// Тест LinkedListSequence(LinkedList <T>& list)
	LinkedListSequence<complex>* linkedListSeq3 = new LinkedListSequence<complex>(*linkedListSeq2);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(linkedListSeq3->Get(i) == complexArr[i]);
	}
	// Тест T GetFirst()
	BOOST_CHECK(linkedListSeq3->GetFirst() == complexArr[0]);
	// Тест T GetLast()
	BOOST_CHECK(linkedListSeq3->GetLast() == complexArr[ITEMS_COUNT-1]);
	// Тест T Get(int index)
	delete linkedListSeq1;
	linkedListSeq1 = new LinkedListSequence<complex>(*linkedListSeq2);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(linkedListSeq1->Get(i) == linkedListSeq2->Get(i));
	}
	// Тест LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex)=
	int startIndexSub = ITEMS_COUNT / 4;
	int endIndexSub = ITEMS_COUNT / 2;
	delete linkedListSeq2;
	linkedListSeq2 = new LinkedListSequence<complex>(*linkedListSeq1);
	delete linkedListSeq3;
	linkedListSeq3 = new LinkedListSequence<complex>(*(linkedListSeq1->GetSubsequence(startIndexSub, endIndexSub)));
	for (int i = 0; i < (linkedListSeq3->GetLength()); i++)
	{
		BOOST_CHECK((linkedListSeq3->Get(i)) == (linkedListSeq2->Get(i + startIndexSub)));
	}
	// Тест int GetLength()
	BOOST_CHECK(linkedListSeq2->GetLength() == ITEMS_COUNT);
	// Тест void Set(int index, T data)
	complex* c1 = new complex;
	*c1 = linkedListSeq3->Get(0);
	int indexDif = 0;
	for (int i = 0; i < linkedListSeq3->GetLength(); i++)
	{
		if (linkedListSeq3->Get(i)!=*c1)
		{
			indexDif = i;
			break;
		}
	}
	if (indexDif == 0)
	{
		linkedListSeq3->Set(linkedListSeq3->GetLength() - 1, *c1 + linkedListSeq3->Get(linkedListSeq3->GetLength() - 1));
		linkedListSeq3->Set(linkedListSeq3->GetLength() - 1, *c1);
		BOOST_CHECK(linkedListSeq3->Get(linkedListSeq3->GetLength() - 1)==*c1);
	}
	else
	{
		linkedListSeq3->Set(indexDif, *c1);
		BOOST_CHECK(linkedListSeq3->Get(indexDif) == *c1);
	}
	// Тест void Append(T item)
	int oldSizeAppend = linkedListSeq3->GetLength();
	linkedListSeq3->Append(linkedListSeq3->Get(oldSizeAppend-1));
	BOOST_CHECK(linkedListSeq3->GetLength()-1 == oldSizeAppend);
	BOOST_CHECK(linkedListSeq3->Get(oldSizeAppend - 1) == linkedListSeq3->Get(linkedListSeq3->GetLength()-1));
	// Тест void Prepend(T item)
	oldSizeAppend = linkedListSeq3->GetLength();
	linkedListSeq3->Prepend(linkedListSeq3->Get(0));
	BOOST_CHECK(linkedListSeq3->GetLength()-1 == oldSizeAppend);
	BOOST_CHECK(linkedListSeq3->Get(0) == linkedListSeq3->Get(1));
	// Тест void InsertAt(T item, int index)
	oldSizeAppend = linkedListSeq3->GetLength();
	complex* c2 = new complex;
	*c2 = complexArr[4];
	complex* c3 = new complex;
	*c3 = complexArr[5];
	linkedListSeq3->Set(0, *c1);
	linkedListSeq3->Set(1, *c2);
	linkedListSeq3->InsertAt(*c3, 0);
	BOOST_CHECK(linkedListSeq3->GetLength() - 1 == oldSizeAppend);
	BOOST_CHECK(linkedListSeq3->Get(0) == *c1);
	BOOST_CHECK(linkedListSeq3->Get(1) == *c3);
	BOOST_CHECK(linkedListSeq3->Get(2) == *c2);
	// Тест Sequence <T>* Concat(Sequence <T>* list)
	delete linkedListSeq1;
	linkedListSeq1 = new LinkedListSequence<complex>(*linkedListSeq2);
	linkedListSeq2->Concat(linkedListSeq3);
	for (int i = 0; i < linkedListSeq1->GetLength(); i++)
	{
		BOOST_CHECK(linkedListSeq1->Get(i) == linkedListSeq2->Get(i));
	}
	for (int i = 0; i < linkedListSeq3->GetLength(); i++)
	{
		BOOST_CHECK(linkedListSeq2->Get(i + linkedListSeq1->GetLength()) == linkedListSeq3->Get(i));
	}
	// LinkedListSequence<T>* wwhere(bool (*whereFunc)(T))
	int countRetTrueData = 0;
	delete linkedListSeq1;
	linkedListSeq1 = new LinkedListSequence<complex>;
	for (int i = 0; i < linkedListSeq2->GetLength(); i++)
	{
		if (whereFunc(linkedListSeq2->Get(i)))
		{
			countRetTrueData++;
			linkedListSeq1->Append(linkedListSeq2->Get(i));
		}
	}
	delete linkedListSeq3;
	linkedListSeq3 = linkedListSeq2->wwhere(whereFunc);
	BOOST_CHECK(linkedListSeq3->GetLength() == countRetTrueData);
	for (int i = 0; i < linkedListSeq3->GetLength(); i++)
	{
		BOOST_CHECK(linkedListSeq3->Get(i) == linkedListSeq1->Get(i));
	}
}

BOOST_AUTO_TEST_CASE(testQueue)
{
	complex complexArr[ITEMS_COUNT];
	complex endIndex(ITEMS_COUNT, ITEMS_COUNT);
	complex add(1, 1);
	int counterJ = 0;
	for (complex i(0,0); i<endIndex; i+=add, counterJ++)
	{
		complexArr[counterJ] = i;
	}
	// Queue()
	// Создадим 5 que с пустым конструктором
	Queue<complex>* que1 = new Queue<complex>;
	Queue<complex>* que2 = new Queue<complex>;
	Queue<complex>* que3 = new Queue<complex>;
	Queue<complex>* que4 = new Queue<complex>;
	Queue<complex>* que5 = new Queue<complex>;
	// Инициализация que1 проверка push
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		que1->push(complexArr[i]);
	}
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(que1->Peek(i) == complexArr[i]);
	}
	// Создадим que6 из конструктора копирования
	Queue<complex>* que6 = new Queue<complex>(*que1);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(que6->Peek(i) == que1->Peek(i));
	}
	// Проверка Peek()
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(que1->Peek(i) == complexArr[i]);
	}
	// Проверка Pop()
	BOOST_CHECK(que1->pop() == complexArr[0]);
	BOOST_CHECK(que1->Peek(0) == complexArr[1]);
	// Проверка Size()
	BOOST_CHECK(que1->Size()==ITEMS_COUNT-1);
	// Проверка isEmpty()
	BOOST_CHECK(que2->isEmpty());
	BOOST_CHECK(!(que1->isEmpty()));
	// Проверка map(T mupFunc(T arg))
	que6->map(mupFuncComplex);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(que6->Peek(i) == complexArr[i]* complexArr[i]);
	}
	// Проверка wwhere(bool(*whereFunc)(T))
	int countRetTrueData = 0;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		if (whereFunc(que6->Peek(i))) countRetTrueData++;
	}
	que6->wwhere(whereFunc);
	BOOST_CHECK(que6->Size() == countRetTrueData);
	// Проверка Concat(Queue<T>& que2)
	int sizeQ1PlusQ6 = que1->Size() + que6->Size();
	que1 = que1->Concat(*que6);
	BOOST_CHECK(que1->Size() == sizeQ1PlusQ6);
	// Проверка GetSubsequence(int startIndex, int endIndex)
	int startIndexInt = 1;
	int endIndexInt = (que1->Size()) / 2;
	que2 = que1->GetSubsequence(startIndexInt, endIndexInt);
	for (int i = 0; i < endIndexInt - startIndexInt; i++)
	{
		BOOST_CHECK(que2->Peek(i) == que1->Peek(i+ startIndexInt));
	}
	// Проверка SubSequenceSearch(Queue<T>& que)
	BOOST_CHECK(que1->SubSequenceSearch(*que2));
}