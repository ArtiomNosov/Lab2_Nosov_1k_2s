#pragma once
#include "Sequence.h"
#include "linkedList.h"

template <class T> class LinkedListSequence : public Sequence<T>
{
private:
	LinkedList<T>* internalList;
public:
	//Конструкторы
	LinkedListSequence(LinkedList <T>& list)
	{
		internalList = new LinkedList<T>(list);
	};
	LinkedListSequence()
	{ 
		internalList = new LinkedList<T>;
	};
	LinkedListSequence(T* items, int count)
	{
		internalList = new LinkedList<T>(items, count);
	};
	// Деструктор
	~LinkedListSequence()
	{
		delete internalList;
	}

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
	LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		LinkedListSequence<T>* bufList = new LinkedListSequence<T>;
		((LinkedListSequence<T>*)bufList)->internalList = internalList->GetSubList(startIndex, endIndex);
		return bufList;
	}
	int GetLength()
	{
		return internalList->GetLength();
	}
	void Set(int index, T data)
	{
		internalList->Set(index, data);
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
	Sequence <T>* Concat(Sequence <T>* list)
	{
		internalList->Concat(((LinkedListSequence<T> *)list)->internalList);
		return (Sequence <T>*)this;
	}
	LinkedListSequence<T>* wwhere(bool (*whereFunc)(T))
	{
		LinkedListSequence<T>* buf = new LinkedListSequence<T>;
		for (int i = 0; i < GetLength(); i++)
		{
			if ( whereFunc(Get(i)) ) buf->Append(Get(i));
		}
		return (LinkedListSequence<T>*)buf;
	}
	
};

