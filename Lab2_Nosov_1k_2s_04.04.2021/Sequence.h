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
	virtual T GetFirst();
	virtual T GetLast();
	virtual T Get(int index);
	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex);
	virtual int GetLength();

	// ��������
	virtual void Append(T item); // ��������� ������� � ����� ������
	virtual void Prepend(T item); // ��������� ������� � ������ ������
	virtual void InsertAt(T item, int index); // ��������� ������� � �������� �������
	virtual Sequence <T>* Concat(Sequence <T>* list); // �������� ��� ������
	//map, reduce, zip, unzip, where
};

