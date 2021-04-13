#include <iostream> // Стандартная библиотека ввода-вывода
#include <string>   // Стандартная библиотека для работы состроками
#include <locale>

#include "testUnit.h"
#include "LinkedList.h"
#include "LinkedListSequence.h"
#include "Sequence.h"
#include "Queque.h"
#include "UI.h"
using namespace std;

// вариант 14. 
// Очередь:
//	− Целые числа
//	− Комплексные числа
//	− Строки
// Нужно реализовать:
//	− map, where
//	− объединение
//	− пересечение
//	− вычитание
//	− проверка на включение подмножества
//	− проверка на вхождение элемента
//	− сравнение(равенство) двух множеств
// 
// − Перегрузка операторов (например, оператора [] для обращения/задания значения элемента по индексу).

//Меню для лабароторной работы
string strForListMenuLevel0[3] = {"целыми числами", "комплексными числами", "строками"};
UIMenu menuLab2_lvl_0((int)3, strForListMenuLevel0);

int main()
{
    setlocale(LC_ALL, "Russian");
    int userСhoice = menuLab2_lvl_0.userShoes("***Главное меню***\n\nТестирование коллекций с:");
    if (userСhoice != 0)
        testQueueUI(userСhoice);
    //LinkedListSequence<float>* mySeq = new LinkedListSequence<float>;
    //float arr[3] = { 1.5, 2.3, 3.14 };
    /*mySeq->Append(arr[0]);
    mySeq->Append(arr[1]);
    mySeq->Append(arr[2]);
    cout << "Элемент под номером нуль " << mySeq->Get(0) << endl;
    cout << "Элемент под номером один " << mySeq->Get(1) << endl;
    cout << "Элемент под номером два " << mySeq->Get(2)<<endl;
    cout << "Длинна списка " << mySeq->GetLength() << endl;*/

    //Queue<float>* que = new Queue<float>;
    //que->push(arr[0]);
    //que->push(arr[1]);
    //que->push(arr[2]);
    //que->printQueue();
    //cout << "Элемент под номером нуль " << que->pop() << endl;
    //cout << "Элемент под номером один " << que->pop() << endl;
    //cout << "Элемент под номером два " << que->pop() << endl;
    //cout << "Длинна списка " << que->Size() << endl;
    ////testLinkedListInt();
    //cout << endl;
    //testDynamicArrayChar();
    
    system("pause>0");
}


