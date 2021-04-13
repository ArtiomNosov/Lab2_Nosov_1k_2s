#pragma once
#include "MyComplex.h"
//�������� ����� ������-�� ���� T
template <class T> class Sequence
{
private:
	
public:
	// ������������
	Sequence() {};
	Sequence(T* items, int count);
	
	// ������������
	virtual T GetFirst() = 0;	// ���������� ������ �������
	virtual T GetLast() = 0;	// ���������� ��������� �������
	virtual T Get(int index) = 0;	// ���������� ������� �� �������
	//GetSubsequence ���������� ��������� �� ��������������������� ��������� 
	// ������� ������ � ����� ��������������������� ��  Sequence 
	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
	virtual int GetLength() = 0;	// ���������� ����� ������������������
	virtual void Set(int index, T data) = 0;	// ������ �������� i-�� ��������

	// ��������
	virtual void Append(T item) = 0; // ��������� ������� � ����� ������
	virtual void Prepend(T item) = 0; // ��������� ������� � ������ ������
	virtual void InsertAt(T item, int index) = 0; // ��������� ������� � �������� �������
	virtual Sequence <T>* Concat(Sequence <T>* list) = 0; // �������� ��� ������
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
	// TODO: ����� ������ SubSequenceSearch
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

