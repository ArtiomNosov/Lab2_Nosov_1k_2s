#pragma once
#include <cassert>

template <typename T> class Item
{
public:
	T data;	// Любые данные
	Item<T>* next;	//Указатель на следующиий элемент в цепочке
	Item<T>* previos;
};

template <typename T> class LinkedList
{
	Item<T>* head;	// Голова списка
	Item<T>* tail;
	int lenght;	// Длинна списка
public:
// Конструкторы
	LinkedList(); // Создать пустой список
	LinkedList(T* items, int count) //	Копировать элементы из переданного массива
	{
		head = NULL;
		tail = NULL;

		for (int i = 0; i < count; i++)
		{
			Append(items[i]);
		}
	}
	LinkedList(const LinkedList <T>& list); // Копирующий конструктор
// Декомпозиция
	T GetFirst(); // Получить первый элемент в списке. Может выбрасывать исключения : − IndexOutOfRange(если список пуст)
	T GetLast(); // Получить последний элемент в списке. Может выбрасывать исключения : − IndexOutOfRange(если список пуст)
	T Get(int index); // Получить элемент по индексу. Может выбрасывать исключения :− IndexOutOfRange(если индекс отрицательный или больше / равен числу элементов)		
	LinkedList<T>* GetSubList(int startIndex, int endIndex); // Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
																// Может выбрасывать исключения :− IndexOutOfRange(если хотя бы один из 
																// индексов отрицательный или больше / равен числу элементов)
	int GetLength();	// Получить длину списка

// Операции

	// Добавляет элемент в конец списка
	void Append(T item);
	void Prepend(T item); // Добавляет элемент в начало списка
	void InsertAt(T item, int index); // Вставляет элемент в заданную позицию. 
									// Может выбрасывать исключения : − IndexOutOfRange(если индекс отрицательный или больше / равен числу элементов)
		
	LinkedList<T>* Concat(LinkedList<T>* list); //Сцепляет два списка
	Item<T>* operator[](const int index);
};


