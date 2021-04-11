#pragma once
#include <cassert>

//TODO:Тесты на все функции
// TODO: Добавление в конец.

template <class T> class DynamicArray
{
	T* data;
	int lenght;
public:
// Конструкторы
	DynamicArray(T* items, int count) //	Копировать элементы из переданного массива
	{
		data = new T[count];
		lenght = count;
		for (int i = 0; i < lenght ; i++)
		{
			data[i] = items[i];
		}
	}
	DynamicArray(int size) //	Создать массив заданной длины
	{
		data = new T[size];
		lenght = size;
	}
	T operator[](int const index)
	{
		return data[index];
	}
	DynamicArray(DynamicArray<T>& dynamicArray) //	Копирующий конструктор
	{
		lenght = dynamicArray.lenght;
		data = new T[lenght];
		for (int i = 0; i < lenght; i++)
		{
			data[i] = dynamicArray.Get(i);
		}
	}

// Декомпозиция
	
	// Получить элемент по индексу. 
	// Может выбрасывать исключения :	− IndexOutOfRange(если индекс отрицательный, больше 
	// или равен числу элементов или указывает на не заданный элемент)
	T Get(int index)
	{
		assert(index >= 0);
		assert(index < lenght);
		return data[index];
	}
	int GetSize() //	Получить размер массива
	{
		return lenght;
	}
	
// Операции
	void Set(int index, T value) // Задать элемент по индексу. Может выбросить IndexOutOfRange
	{
		assert(index>=0);
		assert(index < lenght);
		data[index] = value;
	}

	// Изменить размер массива.Если размер увеличивается, все элементы копируются в начало новой памяти.
	// Если уменьшается – элементы, которые не помещаются, отбрасываются.
	void Resize(int newSize)
	{
		assert(newSize > 0);
		T* newData = new T[newSize];
		int tempSize= 0;
		tempSize = (newSize > lenght) ? lenght : newSize;
		for (int i = 0; i < tempSize; i++)
			newData[i] = data[i];
		delete data;
		data = newData;
		lenght = newSize;
	}
	void ResizeRight(int newSize)
	{
		assert(newSize > 0);
		T* newData = new T[newSize];
		int tempSize = 0;
		tempSize = (newSize > lenght) ? lenght : newSize;
		for (int i = 0; i < tempSize; i++)
			newData[i] = data[i];
		delete data;
		data = newData;
		lenght = newSize;
	}
};



