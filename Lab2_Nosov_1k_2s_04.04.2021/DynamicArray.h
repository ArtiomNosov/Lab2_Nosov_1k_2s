#pragma once
#include "AbstractCollection.h"

template <class T> class DynamicArray: AbstractCollection<T>
{
// Конструкторы
	DynamicArray(T* items, int count); //	Копировать элементы из переданного массива
	DynamicArray(int size); //	Создать массив заданной длины
	DynamicArray(const DynamicArray<T>& dynamicArray); //	Копирующий конструктор

// Декомпозиция
	T Get(int index);	// Получить элемент по индексу. 
						// Может выбрасывать исключения :	− IndexOutOfRange(если индекс отрицательный, больше 
						// или равен числу элементов или указывает на не заданный элемент)
	int GetSize(); //	Получить размер массива
	
// Операции
	void Set(int index, T value); // Задать элемент по индексу. Может выбросить IndexOutOfRange
	void Resize(int newSize);	// Изменить размер массива.Если размер увеличивается, все элементы копируются в начало новой памяти.
								// Если уменьшается – элементы, которые не помещаются, отбрасываются.

};

