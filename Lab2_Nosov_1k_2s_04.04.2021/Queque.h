

#include <cassert> // для assert
#include <iostream>

using namespace std;
//мои инклюды
#include "LinkedListSequence.h"

//	− map, where
//	− объединение
//  - Извлечениеподпоследовательности(по заданным индексам)
//  − Поиск на вхождение подпоследовательности

template <class T>
class Queue{
private:
    LinkedListSequence<T>* internalListSequence; // указатель на связный список
public:

    // Конструкторы
    Queue() 
    { 
        internalListSequence = new LinkedListSequence<T>; 
    }; 
    Queue(const Queue<T>& que) // конструктор копирования
    {
        internalListSequence = new LinkedListSequence<T>;
        for (int i = 0; i< que.Size();i++)
        {
            internalListSequence->Append(que.Peek(i));
        }
    }; 
    // Деструктор
    ~Queue()
    {
        delete internalListSequence;
    };


    void push(const T& data) // добавить элемент в очередь
    {
        internalListSequence->Append(data);
    }; 
    //pol вместо pop по соглашению
    T pop() // удалить элемент из начала очереди
    {
        T result = internalListSequence->GetFirst();
        internalListSequence = (LinkedListSequence<T>*)internalListSequence->GetSubsequence(1, internalListSequence->GetLength() - 1);
        return result;
    }; 
    // TODO: Если будет сложно состовной тип класс, то в нём описываем перегрузку оператора стрелочки <<
    void printQueue()// вывод очереди
    {
        for (int i = 0; i < internalListSequence->GetLength();i++)
        {
            cout <<i<<".  "<<internalListSequence->Get(i)<< endl;
        }
    }; 
    T& Peek(int index) // n-й элемент от вершины очереди
    {
        return internalListSequence->Get(index);
    }; 
    int Size() // получить размер очереди
    {
        return internalListSequence->GetLength();
    };  
    bool isEmpty() // пуста ли очередь
    {
        return (internalListSequence->GetLength() < 1)? true : false;
    }; 
    void map(T mupFunc(T& arg))
    {
        internalListSequence->map(mupFunc);
    }
    void where(T whereFunc(T& arg))
    {
        internalListSequence->where(whereFunc);
    }
    Queue<T>* Concat(Queue<T>& que2)
    {
        internalListSequence->Concat(que2.internalListSequence);
        return this;
    }
    Queue<T>* GetSubsequence(int startIndex, int endIndex)
    {
        Queue<T>* bufQue = new Queue<T>;
        bufQue->internalListSequence = internalListSequence->GetSubsequence(startIndex, endIndex);
        return bufQue;
    }
    bool SubSequenceSearch(Queue<T>& que)
    {
        return internalListSequence->GetSubsequence(que.internalListSequence);
    };
};