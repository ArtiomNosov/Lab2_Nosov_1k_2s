#pragma once
#include "Sequence.h"

template <class T> class ArraySequence : Sequence<T>
{
private:
	DynamicArray<T>* items;
public:
	// ������������:
	ArraySequence(); // ������� ������ ������
	ArraySequence(T* items, int count); // ���������� �������� �� ����������� �������
	ArraySequence(LinkedList <T>& list const); // ������� �� ������ ������� - ���������� �����������
	
	//�������� �� Sequence
	T GetFirst()
	{
		return items->GetFirst();
	}
	T GetLast()
	{
		return items->GetLast();
	}
	T Get(int index)
	{
		return items->Get(index);
	}
	// TODO:�������, ����� ��������� ����� ArraySequence � ������� ������������
	// DynamicArray �� ����� ������� GetSubArray
	ArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		items->GetSubsequence(startIndex, endIndex);
		return this;
	}
	int GetLength()
	{
		return items->lenght;
	}
	void Set(int index, T value) // ������ ������� �� �������. ����� ��������� IndexOutOfRange
	{
		items->Set(index, value);
	}

	// ��������� ������� � ����� ������
	// TODO: ������� ���������� ��� resize � Append, Prepend, InsertAt
	void Append(T item)
	{
		items->Resize(items->lenght + 1);
		items->Set(items->lenght, item)
	}
	// ��������� ������� � ������ ������
	
	// TODO: �������� ��� ������������� �������.
	void Prepend(T item)
	{
		items->ResizeRight(items->lenght + 1);
		items->Set(0, item)
	}
	// ��������� ������� � �������� �������
	void InsertAt(T item, int index)
	{
		DynamicArray<T>* tmp items->DynamicArray(items, index);
		tmp->Append(item);
		for (int i = index+1; i < items->lenght+1; i++)
		{
			tmp->Append(items->Get(i));
		}
		items = tmp;
	}
	ArraySequence <T>* Concat(ArraySequence <T>* list)
	{
		items->Resize(items->lenght + list->items->lenght);
		for (int i = 0 ;i < list->items->lenght; i++)
			items->Append(list->items->Get(i);
	}
	bool subsequenceSearch()
	{

	}
};

//ArraySequence<int> arrInt;