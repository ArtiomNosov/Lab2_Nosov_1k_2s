#include <complex.h>
#include <string>

#include "UI.h"
#include "Queque.h"

//Вид коллекции
string strForListMenuLevel1[9] = { "Push", "Peek", "Size", "Map", "Where", "Concat", "GetSubsequence", "SubSequenceSearch", "pol" };
UIMenu menuLab2_lvl_1_functions(9, strForListMenuLevel1);

int testQueueUI(int userType)
{ 
	switch (userType)
	{
	case 1: //Целые числа
		cout << "Введите количество целых чисел" << endl;
		testQueue((int)1);
		break;
	case 2: //Комплексные числа
		cout << "Введите количество комплексных чисел" << endl;
		//testQueue<_Fcomplex>();
		break;
	case 3: //Строки
		cout << "Введите количество строк" << endl;
		//testQueue<string>();
		break;
	default:
		break;
	}
}

//Функция для mup T mupFunc(T& arg)
template <typename T>
T mupFunc(T& arg)
{
	return T + T;
}

template <typename T>
int printData(T data)
{
	switch (data)
	{
	case 1:
		cout << data;
		break;
	default:
		break;
	}
}

template <typename T>
int testQueue(T data)
{
	Queue<T>* que1;
	Queue<T>* que2;
	que1 = new Queue<T>;
	que2 = new Queue<T>;
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
			//cin >> userElem;
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
			cout << "Её размер ";
			cout<< (userChoise == '1') ? que1->Size() : que2->Size();
			cout << endl;
			break;
		case 4:
			cout << "Выберите очередь 1 или 2: ";
			char userChoise;
			cin >> userChoise;
			(userChoise == '1') ? que1->map(mupFunc): que2->map(mupFunc);
			break;
		case 5:
			cout << "Выберите очередь 1 или 2: ";
			char userChoise;
			cin >> userChoise;
			(userChoise == '1') ? que1->where(mupFunc) : que2->where(mupFunc);
			break;
		case 6:
			que1 = que1->Concat(que2);
			break;
		case 7:
			cout << "Выберите очередь 1 или 2: ";
			char userChoise;
			cin >> userChoise;
			cout << "Введите элемент номер первого индекса: ";
			int n1;
			cin >> n1;
			cout << "Введите элемент номер второго индекса: ";
			int n2;
			cin >> n2;
			int SubSize = n2 - n1;
			if (n1<0 || SubSize<0 || userChoise == '1' && SubSize>que1->Size() || SubSize>que2->Size())
			{
				cout << "Нльзя извлечь подпоследовательность с такими индексами из очереди ";
				cout << (userChoise == '1') ? "1" : "2" << endl;
				break;
			}
			(userChoise == '1') ? que1 = que1->GetSubsequence(n1,n2) : que2 = que2->GetSubsequence(n1, n2);
			break;
		case 8:
			cout << "Выберите очередь для поиска её в другой 1 или 2: ";
			char userChoise;
			cin >> userChoise;
			bool flag;
			flag = (userChoise == '1') ? que2->SubSequenceSearch(que1) : que1->SubSequenceSearch(que2);
			cout << flag ? "Является подочередью" : "Не является подочередью";
			break;
		case 9:
			cout << "Выберите очередь 1 или 2: ";
			char userChoise;
			cin >> userChoise;
			cout << "Элемент " << endl;
			//printData((userChoise == '1') ? que1->pop() : que2->pop());
			cout<<" удалён из очереди"<<endl;
			menuLab2_lvl_1_functions.waitingUserPressEnter();
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

