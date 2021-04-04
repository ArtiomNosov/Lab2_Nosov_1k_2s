

#include <cassert> // для assert
#include <iostream>


//template <class T>
//class Queue : public PushPopContainer<T> {
//private:
//    T* arr; // указатель на очередь
//    const int size; // Емкость очереди
//    int begin, end; // начало, конец очереди
//    int elemCT; //счетчик элементов
//public:
//    Queue(int = 10); //размер очереди = 10 элементам
//    Queue(const Queue<T>&); // конструктор копирования
//    ~Queue();
//
//
//    inline void push(const T&); // добавить элемент в очередь
//    inline T pop(); // удалить элемент из очереди
//    inline void printQueue(); // вывод очереди
//    inline const T& Peek(int) const; // n-й элемент от вершины очереди
//    inline int Size() const;  // получить размер очереди
//    inline bool isEmpty() const; // пуста ли очередь
//};
//
//
//// конструктор по умолчанию
//template <class T>
//Queue<T>::Queue(int sizeQueue) : size(sizeQueue), // инициализация константы
//begin(0), end(0), elemCT(0)
//{
//    // дополнительная позици поможет нам различать конец и начало очереди
//    arr = new T[size + 1];
//}