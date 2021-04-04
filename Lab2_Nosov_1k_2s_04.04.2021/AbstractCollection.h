#pragma once

//TODO: Больше комментариев
template <class T> class AbstractCollection
{
	int abc_len;	// Число элементов в коллекции
	AbstractCollection();
	AbstractCollection(int size);
	T Get(int index);	// Получить элемент по индексу. 
						// Может выбрасывать исключения :	− IndexOutOfRange(если индекс отрицательный, больше 
						// или равен числу элементов или указывает на не заданный элемент)
	int GetSize(); //	Получить размер массива
};

