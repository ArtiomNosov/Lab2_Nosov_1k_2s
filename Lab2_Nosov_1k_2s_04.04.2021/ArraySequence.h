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
	
};

//ArraySequence<int> arrInt;