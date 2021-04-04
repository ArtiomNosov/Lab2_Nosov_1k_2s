#pragma once
#include "Sequence.h"
#include "linkedList.h"

// TODO: Объяснить Артёму что здесь происходит
template <class T> class LinkedListSequence : Sequence<T>
{
private:
	LinkedList<T>* internalList;


public:
	LinkedListSequence(T* items, int count);
	T GetFirst()
	{
		return internalList->GetFirst();
	}
	T GetLast()
	{
		return internalList->GetLast();
	}
	T Get(int index)
	{
		return internalList->Get(index);
	}
	// TODO:Вставить конструктор, чтобы пользователь получал указатель на новый Sequence
	Sequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		internalList = internalList->GetSubsequence(startIndex, endIndex);
		return this;
	}
	int GetLength()
	{
		return internalList->GetLenght;
	}
	void Append(T item)
	{
		internalList->Append(item);
	}
	void Prepend(T item)
	{
		internalList->Prepend(item);
	}
	void InsertAt(T item, int index)
	{
		internalList->InsertAt(item, index);
	}
	LinkedListSequence <T>* Concat(LinkedListSequence <T>* list)
	{
		internalList->Concat(list->internalList);
		return this;
	}
};

