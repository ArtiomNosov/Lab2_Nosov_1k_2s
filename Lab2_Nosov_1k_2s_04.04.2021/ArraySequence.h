#pragma once
#include "Sequence.h"
#include "DynamicArray.h"

template <class T> class ArraySequence : public Sequence<T>
{
private:
	DynamicArray<T>* items;
public:
	// ������������:
	ArraySequence() 
	{
		items = new DynamicArray<T>(0);
	} // ������� ������ ������
	ArraySequence(T* arr, int count) {
		items = new DynamicArray<T>(0);
		items->Resize(count);
		for (int i = 0; i < count; i++)
		{
			items->Set(i, arr[i]);
		}
	} // ���������� �������� �� ����������� �������
	ArraySequence(ArraySequence <T>& list)
	{
		items = new DynamicArray<T>(0);
		items->Resize(list.GetLength());
		for (int i = 0; i < (list.GetLength()); i++)
		{
			items->Set(i, list.Get(i));
		}
	}// ������� �� ������ ������� - ���������� �����������
	
	//�������� �� Sequence
	T GetFirst()
	{
		return this->Get(0);
	}
	T GetLast()
	{
		return this->Get(items->GetSize()-1);
	}
	T Get(int index)
	{
		return items->Get(index);
	}
	ArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		ArraySequence<T>* buf = new ArraySequence<T>;
		int dif = endIndex - startIndex+1;
		buf->Resize(dif);
		for (int i = 0; i< dif;i++)
		{
			buf->Set(i, this->Get(startIndex+i));
		}
		return buf;
	}
	int GetLength()
	{
		return items->GetSize();
	}
	void Set(int index, T value) // ������ ������� �� �������. ����� ��������� IndexOutOfRange
	{
		items->Set(index, value);
	}

	// ��������� ������� � ����� ������
	// TODO: ������� ���������� ��� resize � Append, Prepend, InsertAt
	void Append(T item)
	{
		items->Resize(items->GetSize() + 1);
		items->Set(items->GetSize()-1, item);
	}
	// ��������� ������� � ������ ������
	
	// TODO: �������� ��� ������������� �������.
	void Prepend(T item)
	{
		items->ResizeRight(items->GetSize() + 1);
		items->Set(0, item);
	}
	// ��������� ������� � �������� �������
	void InsertAt(T item, int index)
	{
		int newLenght = this->GetLength() + 1;
		this->Resize(newLenght);
		T buf;
		int dif = newLenght - index -1 ;
		for (int i = 0; i < dif; i++)
		{
			buf = this->Get(newLenght - i - 2);
			this->Set(newLenght - i - 1, buf);
		}
		this->Set(index + 1, item);
	}
	Sequence <T>* Concat(Sequence <T>* list)
	{
		Sequence <T>* buf = NULL;
		items->Resize(items->GetSize() + ((ArraySequence <T>*)list)->items->GetSize());
		for (int i = 0 ;i < ((ArraySequence <T>*)list)->GetLength(); i++)
			items->Set(i + items->GetSize(),((ArraySequence <T>*)list)->Get(i));
		return (Sequence <T>*)buf;
	}
	/*bool subsequenceSearch()11
	{

	}*/
	void Resize(int newSize)
	{
		items->Resize(newSize);
		
	}
	void ResizeRight(int newSize)
	{
		items->ResizeRight(newSize);
	}
};

//ArraySequence<int> arrInt;