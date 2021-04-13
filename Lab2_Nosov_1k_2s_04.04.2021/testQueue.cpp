#include <complex.h>
#include <string>

#include "UI.h"
#include "Queque.h"

//Вид коллекции
string strForListMenuLevel1[8] = { "Push", "Peek", "Size", "Map", "Where", "Concat", "GetSubsequence", "SubSequenceSearch" };
UIMenu menuLab2_lvl_1_functions(8, strForListMenuLevel1);



int testQueueUI(int userType)
{ 
	switch (userType)
	{
	case 1: //Целые числа
		cout << "Введите количество целых чисел" << endl;
		testQueue<int>();
		break;
	case 2: //Комплексные числа
		cout << "Введите количество комплексных чисел" << endl;
		testQueue<_Fcomplex>();
		break;
	case 3: //Строки
		cout << "Введите количество строк" << endl;
		testQueue<string>();
		break;
	default:
		break;
	}
}

//Функция для mup T mupFunc(T& arg)
template <typename T>
T
template <typename T>
int testQueue()
{
	Queue<T>* que1;
	Queue<T>* que2;
	int userType;
	do {
		userType = menuLab2_lvl_1_functions.userСhoice();
		switch (userType)
		{
		case 1:
			cout << "Выберите очередь 1 или 2: ";
			char userChoise;
			cin >> userChoise;
			cout << "Введите элемент: ";
			T userElem;
			cin >> userElem;
			(userChoise == '1') ? que1->push(userElem) : que2->push(userElem);
			break;
		case 2:
			cout << "Выберите очередь 1 или 2: ";
			char userChoise;
			cin >> userChoise;
			cout << "Введите элемент номер элемента: ";
			int n;
			cin >> n;
			if (n<0 || n > que1->Size() && userChoise == '1' || n > que2->Size())
			{
				cout << "Нет элемента с таким номером в очереди ";
				cout << (userChoise == '1') ? "1" : "2" << endl;
				break;
			}
			(userChoise == '1') ? que1->Peek(n) : que2->Peek(n);
			break;
		case 3:
			cout << "Выберите очередь 1 или 2: ";
			char userChoise;
			cin >> userChoise;
			cout<<"Её размер "
			cout<< (userChoise == '1') ? que1->Size() : que2->Size();
			cout << endl;
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			break;
		}
		cout << "Первая очередь" << endl;
		que1->printQueue();
		cout << "Вторая очередь" << endl;
		que2->printQueue();
	} while (userType != 0);
}