#pragma once
#include "MyComplex.h"
//Темплейт класс какого-то типа T
template <class T> class Sequence
{
private:
	
public:
	// Конструкторы
	Sequence() {};
	Sequence(T* items, int count);
	
	// Декомпозиция
	virtual T GetFirst() = 0;	// Возвращает первый элемент
	virtual T GetLast() = 0;	// Возвращает последний элемент
	virtual T Get(int index) = 0;	// Возвращает элемент по индексу
	//GetSubsequence возвращает указатель на подпоследовательность используя 
	// индексы начала и конца подпоследовательности из  Sequence 
	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
	virtual int GetLength() = 0;	// Возвращает длину последовательности
	virtual void Set(int index, T data) = 0;	// Меняет значение i-го элемента

	// Операции
	virtual void Append(T item) = 0; // Добавляет элемент в конец списка
	virtual void Prepend(T item) = 0; // Добавляет элемент в начало списка
	virtual void InsertAt(T item, int index) = 0; // Вставляет элемент в заданную позицию
	virtual Sequence <T>* Concat(Sequence <T>* list) = 0; // Сцепляет два списка
	//map, reduce, zip, unzip, where
	void map(T mupFunc(T arg))
	{
		for (int i = 0; i < GetLength(); i++)
		{
			Set(i, mupFunc(Get(i)));
		}
	}
	T reduce(T reduceFunc(T& arg1, T& arg2), T startVal)
	{
		T buf = startVal;
		for (int i = 0; i < GetLength(); i++)
		{
			buf = reduceFunc(Get(i), buf);
		}
		return buf;
	}
	// TODO: Много тестов SubSequenceSearch
	bool SubSequenceSearch(Sequence<T>* seq)
	{
		bool result = false;
		for (int i = 0; i < GetLength() - seq->GetLength(); i++)
		{
			result = true;
			for (int j = 0; j < seq->GetLength(); j++)
			{
				result &= (Get(i + j) == (seq->Get(j)));
			};
			if (result == true)break;
		}
		return result;
	}
};

