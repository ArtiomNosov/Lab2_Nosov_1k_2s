#pragma once
#include "Sequence.h"
#include "linkedList.h"

template <class T> class LinkedListSequence : public Sequence<T>
{
private:
	LinkedList<T>* internalList;
public:
	//Конструкторы
	LinkedListSequence(LinkedListSequence <T>& list)
	{
		internalList = new LinkedList<T>;
		for (int i = 0; i < list.GetLength(); i++)
		{
			this->Append(list.Get(i));
		}
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
	/*~LinkedListSequence()
	{
		delete internalList;
	}*/

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
	LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		LinkedList<T>* bufList = new LinkedList<T>(*(internalList->GetSubList(startIndex, endIndex)));
		LinkedListSequence<T>* bufListSeq = new LinkedListSequence<T>;
		for (int i = 0; i < bufList->GetLength(); i++)
		{
			bufListSeq->Append(bufList->Get(i));
		}
		delete bufList;
		return (LinkedListSequence<T>*)bufListSeq;
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
		for (int i = 0; i < ((LinkedListSequence<T>*)list)->GetLength(); i++)
		{
			this->Append(((LinkedListSequence<T>*)list)->Get(i));
		}
		return (Sequence <T>*)this;
	}
	LinkedListSequence<T>* wwhere(bool (*whereFunc)(T))
	{
		LinkedListSequence<T>* buf = new LinkedListSequence<T>;
		for (int i = 0; i < this->GetLength(); i++)
		{
			if ( whereFunc(this->Get(i)) ) buf->Append(this->Get(i));
		}
		return (LinkedListSequence<T>*)buf;
	}
	
};

