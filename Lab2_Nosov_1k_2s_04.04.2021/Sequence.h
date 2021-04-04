#pragma once
//�������� ����� ������-�� ���� T
template <class T> class Sequence
{
private:
	
public:
	// ������������
	Sequence();
	Sequence(T* items, int count);
	
	// ������������
	T GetFirst();
	T GetLast();
	T Get(int index);
	Sequence<T>* GetSubsequence(int startIndex, int endIndex);
	int GetLength();

	// ��������
	void Append(T item); // ��������� ������� � ����� ������
	void Prepend(T item); // ��������� ������� � ������ ������
	void InsertAt(T item, int index); // ��������� ������� � �������� �������
	Sequence <T>* Concat(Sequence <T>* list); // �������� ��� ������
	//map, reduce, zip, unzip, where
};

