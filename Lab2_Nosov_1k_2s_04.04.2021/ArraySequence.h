#pragma once
#include "Sequence.h"

template <class T> class ArraySequence : Sequence<T>
{
private:
	DynamicArray<T>* items;
public:
	// Конструкторы:
	ArraySequence(); // Создать пустой список
	ArraySequence(T* items, int count); // Копировать элементы из переданного массива
	ArraySequence(LinkedList <T>& list const); // Создать на основе другого - Копирующий конструктор
	
	//Операции из Sequence
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
	// TODO:Сделать, чтобы появлялся новый ArraySequence с помощью конструктора
	// DynamicArray не имеет функции GetSubArray
	ArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		items->GetSubsequence(startIndex, endIndex);
		return this;
	}
	int GetLength()
	{
		return items->lenght;
	}
	void Set(int index, T value) // Задать элемент по индексу. Может выбросить IndexOutOfRange
	{
		items->Set(index, value);
	}

	// Добавляет элемент в конец списка
	// TODO: Сделать реализацию без resize в Append, Prepend, InsertAt
	void Append(T item)
	{
		items->Resize(items->lenght + 1);
		items->Set(items->lenght, item)
	}
	// Добавляет элемент в начало списка
	
	// TODO: Подумать над балансировкой массива.
	void Prepend(T item)
	{
		items->ResizeRight(items->lenght + 1);
		items->Set(0, item)
	}
	// Вставляет элемент в заданную позицию
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