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



int main()
{
    string strForListMenuLevel0[3] = { "целыми числами", "комплексными числами", "строками" };
    UIMenu menuLab2_lvl_0((int)3, strForListMenuLevel0);
    setlocale(LC_ALL, "Russian");
    int userСhoice = menuLab2_lvl_0.userСhoice("***Главное меню***\n\nТестирование коллекций с:");
    if (userСhoice != 0)
        testQueueUI(userСhoice);
    int n, q;
    cin >> n >> q;
    LinkedListSequence<int>* peopleStatistic = new LinkedListSequence<int>;
    Queue<int>* que = new Queue<int>;
    Queue<int>* que_buf_1 = new Queue<int>;
    Queue<int>* que_buf_2 = new Queue<int>;
    for (int i = 1; i <= n; i++)
    {
        peopleStatistic->Append(0);
    }
    int type, id;
    for (int k = 0;k<q;k++)
    {
        cin >> type >> id;
        if (type == 1)
        {
            que->push(id);
        }
        else
        {
            for (int i = 0; i < que->Size(); i++)
            {
                if (que->Peek(i) == id)
                {
                    que_buf_1 = que->GetSubsequence(0, i-1);
                    que_buf_2 = que->GetSubsequence(i+1, que->Size()-1);
                    que_buf_1->Concat(*que_buf_2);
                    delete que;
                    que = que_buf_1;
                    delete que_buf_2;
                }
            }
        }
        int temporary_id = 0;
        for (int i = 0; i < que->Size(); i++)
        {
            temporary_id = que->Peek(i);
            peopleStatistic->Set(temporary_id, peopleStatistic->Get(temporary_id)+1);
        }
    }
    int happiest_id = 0, max_time = 0;
    int temporary_time=0;
    for (int i = 0; i < n; i++)
    {
        temporary_time = peopleStatistic->Get(i);
        if (temporary_time > max_time)
        {
            happiest_id = i;
            max_time = temporary_time;
        }
    }
    cout << happiest_id<<" "<< max_time;
    system("pause>0");
}


