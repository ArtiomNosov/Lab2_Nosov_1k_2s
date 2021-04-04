#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
	lenght = 0;
};

//template<typename T>
//inline LinkedList<T>::LinkedList(T* items, int count)
//{
//	head = NULL;
//	tail = NULL;
//
//	for (int i = 0; i < count; i++)
//	{
//		Append(items[i]);
//	}
//};

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T>& list)
{

};

template<typename T>
T LinkedList<T>::GetFirst()
{
	return T(head->data);
};

template<typename T>
void LinkedList<T>::Append(T item)
{
	lenght++;	//Увеличиваем число элементов на единицу
	Item<T>* buf = new Item<T>;
	buf->next = NULL;
	buf->data = item;
	if (head == NULL)
	{
		head = buf;
		head->previos = NULL;
		tail = head;
	}
	else
	{
		tail->next = buf;
		buf->previous = tail;
		tail = buf; // Смещаем хвост
	}
};

template<typename T>
void LinkedList<T>::Prepend(T item)
{
	lenght++;	//Увеличиваем число элементов на единицу
	T* buf = new Item<T>;
	buf->next = NULL;
	buf->data = item;
	if (head == NULL)
	{
		head = buf;
		head->previos = NULL;
		tail = head;
	}
	else
	{
		head->prev = buf;
		buf->next = head;
		head = buf; // Смещаем голову
	}
};

template<class T>
void LinkedList<T>::InsertAt(T item, int index)
{
	Item<T>* itemBefor = this[index];
	if (itemBefor == NULL)
		Append(item);
	else
	{
		Item<T>* buf = new Item<T>;
		buf->data = item;
		buf->previos = itemBefor;
		buf->next = itemBefor->next;
		itemBefor->next = buf;
		itemBefor->next->previous = buf;
	}

};

template<class T>
Item<T>* LinkedList<T>::operator[](const int index)
{
	if (index == 0 && lenght == 0)
		return NULL;
	assert(index > 0);
	assert(index <= lenght);
	Item<T>* buf = head;
	for (int i = 0; i < lenght; i++)
		buf = buf->next;
	return buf;
};

