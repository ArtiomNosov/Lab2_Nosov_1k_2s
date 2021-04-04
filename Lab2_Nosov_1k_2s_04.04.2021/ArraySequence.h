#pragma once
#include "Sequence.h"


template <class T> class ArraySequence : Sequence<T>
{
private:
	DynamicArray<T>* items;
public:
	// ������������:
	ArraySequence(); // ������� ������ ������
	ArraySequence(T* items, int count); // ���������� �������� �� ����������� �������
	ArraySequence(LinkedList <T>& list const); // ������� �� ������ ������� - ���������� �����������
	
};

//ArraySequence<int> arrInt;