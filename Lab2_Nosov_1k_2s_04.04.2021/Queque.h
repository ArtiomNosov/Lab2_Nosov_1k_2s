

#include <cassert> // ��� assert
#include <iostream>


//template <class T>
//class Queue : public PushPopContainer<T> {
//private:
//    T* arr; // ��������� �� �������
//    const int size; // ������� �������
//    int begin, end; // ������, ����� �������
//    int elemCT; //������� ���������
//public:
//    Queue(int = 10); //������ ������� = 10 ���������
//    Queue(const Queue<T>&); // ����������� �����������
//    ~Queue();
//
//
//    inline void push(const T&); // �������� ������� � �������
//    inline T pop(); // ������� ������� �� �������
//    inline void printQueue(); // ����� �������
//    inline const T& Peek(int) const; // n-� ������� �� ������� �������
//    inline int Size() const;  // �������� ������ �������
//    inline bool isEmpty() const; // ����� �� �������
//};
//
//
//// ����������� �� ���������
//template <class T>
//Queue<T>::Queue(int sizeQueue) : size(sizeQueue), // ������������� ���������
//begin(0), end(0), elemCT(0)
//{
//    // �������������� ������ ������� ��� ��������� ����� � ������ �������
//    arr = new T[size + 1];
//}