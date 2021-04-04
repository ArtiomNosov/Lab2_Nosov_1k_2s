#pragma once
//Темплейт класс какого-то типа T
template <class T> class Sequence
{
private:
	
public:
	// Конструкторы
	Sequence();
	Sequence(T* items, int count);
	
	// Декомпозиция
	T GetFirst();
	T GetLast();
	T Get(int index);
	Sequence<T>* GetSubsequence(int startIndex, int endIndex);
	int GetLength();

	// Операции
	void Append(T item); // Добавляет элемент в конец списка
	void Prepend(T item); // Добавляет элемент в начало списка
	void InsertAt(T item, int index); // Вставляет элемент в заданную позицию
	Sequence <T>* Concat(Sequence <T>* list); // Сцепляет два списка
	//map, reduce, zip, unzip, where
};

