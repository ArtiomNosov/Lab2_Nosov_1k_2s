#pragma once

#include <iostream>
using namespace std;

#pragma inline_depth(2)

#include <cassert>

template <typename T> class Item
{
public:
	T data;	// Любые данные
	Item<T>* next;	//Указатель на следующиий элемент в цепочке
	Item<T>* previous;
};

template <typename T> class LinkedList
{
	Item<T>* head;	// Голова списка
	Item<T>* tail;
	int lenght;	// Длинна списка
public:
// Конструкторы
	LinkedList()// Создать пустой список
	{
		head = NULL;
		tail = NULL;
		lenght = 0;
	};
	LinkedList(T* items, int count) //	Копировать элементы из переданного массива
	{
		head = NULL;
		tail = NULL;

		for (int i = 0; i < count; i++)
		{
			Append(items[i]);
		}
	}
	LinkedList(const LinkedList <T>& list) {}; // Копирующий конструктор
// Декомпозиция
	T GetFirst() // Получить первый элемент в списке. Может выбрасывать исключения : − IndexOutOfRange(если список пуст)
	{
		return T(head->data);
	}
	T GetLast() // Получить последний элемент в списке. Может выбрасывать исключения : − IndexOutOfRange(если список пуст)
	{
		return T(tail->data);
	}
	Item<T>* operator[](const int index)
	{
		if (index == 0 && lenght == 0)
			return NULL;
		//cout << "test - " << "index = " << index << endl;
		assert(index >= 0);
		assert(index < lenght);
		Item<T>* buf = head;
		//cout << "test - " << "lenght = " << lenght << endl;
		//cout <<"test - "<<"head->data = "<< head->data<<endl;
		for (int i = 0; i < index; i++)
		{
			buf = buf->next;
		}
		return buf;
	}
	T Get(int index) // Получить элемент по индексу. Может выбрасывать исключения :− IndexOutOfRange(если индекс отрицательный или больше / равен числу элементов)		
	{
		assert(!(index == 0 && lenght == 0));

		//cout << "test - " << "index = " << index << endl;
		assert(index >= 0);
		assert(index < lenght);
		Item<T>* buf = head;
		//cout << "test - " << "lenght = " << lenght << endl;
		//cout <<"test - "<<"head->data = "<< head->data<<endl;
		for (int i = 0; i < index; i++)
		{
			buf = buf->next;
		}
		return buf->data;
	}

	// Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
	// Может выбрасывать исключения :− IndexOutOfRange(если хотя бы один из 
	// индексов отрицательный или больше / равен числу элементов)
	LinkedList<T>* GetSubList(int startIndex, int endIndex) 
	{
		assert(startIndex >= 0);
		assert(endIndex <= lenght);
		assert(startIndex <= endIndex);
		LinkedList<T>* buf = new LinkedList<T>();
		for (int i = startIndex; i <= endIndex; i++)
		{
			buf->Append(Get(i));
		}
		return buf;
	}

	int GetLength()	// Получить длину списка
	{
		return lenght;
	}

// Операции

	// Добавляет элемент в конец списка
	void Append(T item)
	{
		lenght++;	//Увеличиваем число элементов на единицу
		Item<T>* buf = new Item<T>;
		buf->next = NULL;
		buf->data = item;
		if (head == NULL)
		{
			head = buf;
			head->previous = NULL;
			tail = head;
		}
		else
		{
			tail->next = buf;
			buf->previous = tail;
			tail = buf; // Смещаем хвост
		}
	}
	void Prepend(T item) // Добавляет элемент в начало списка
	{
		lenght++;	//Увеличиваем число элементов на единицу
		Item<T>* buf = new Item<T>;
		buf->next = NULL;
		buf->data = item;
		if (head == NULL)
		{
			head = buf;
			head->previous = NULL;
			tail = head;
		}
		else
		{
			head->previous = buf;
			buf->next = head;
			head = buf; // Смещаем голову
		}
	}
	void InsertAt(T item, int index) // Вставляет элемент в заданную позицию. 
									// Может выбрасывать исключения : − IndexOutOfRange(если индекс отрицательный или больше / равен числу элементов)
	{
		Item<T>* itemBefor = (*this)[index];
		if (itemBefor == NULL)
			Append(item);
		else
		{
			Item<T>* buf = new Item<T>;
			buf->data = item;
			buf->previous = itemBefor;
			buf->next = itemBefor->next;
			itemBefor->next = buf;
			itemBefor->next->previous = buf;
		}

	}
	//Сцепляет два списка
	LinkedList<T>* Concat(LinkedList<T>* list) 
	{
		for (int i = 0; i < list->lenght; i++)
			Append(list->Get(i));
		return this;
	}
	
};


