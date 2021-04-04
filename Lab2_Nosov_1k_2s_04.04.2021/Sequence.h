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
	virtual T GetFirst();
	virtual T GetLast();
	virtual T Get(int index);
	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex);
	virtual int GetLength();

	// Операции
	virtual void Append(T item); // Добавляет элемент в конец списка
	virtual void Prepend(T item); // Добавляет элемент в начало списка
	virtual void InsertAt(T item, int index); // Вставляет элемент в заданную позицию
	virtual Sequence <T>* Concat(Sequence <T>* list); // Сцепляет два списка
	//map, reduce, zip, unzip, where
};

