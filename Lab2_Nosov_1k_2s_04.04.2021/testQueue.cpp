#include <string>

#include "MyComplex.h"
#include "UI.h"
#include "Queque.h"


typedef class complex complexType;
//Вид коллекции
string strForListMenuLevel1[9] = { "Push", "Peek", "Size", "Map", "Where", "Concat", "GetSubsequence", "SubSequenceSearch", "pol" };
UIMenu menuLab2_lvl_1_functions(9, strForListMenuLevel1);

//Функция для mup T mupFunc(T& arg)
template <typename T>
T mapFunc(T arg)
{
	return arg + arg;
}

//bool whereIntFunc(int& arg)
//{
//	return arg > 5;
//}
//
//bool whereComplexFunc(complexType& arg)
//{
//	complexType hol(5.0,6.0);
//	
//	return arg > hol;
//}
template <typename T>
bool whereStringFunc(T arg)
{
	return true;
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
void testQueue()
{
	Queue<T>* que1;
	Queue<T>* que2;
	que1 = new Queue<T>;
	que2 = new Queue<T>;
	int userType = 1;
	char userChoice;
	T userElem;
	int SubSize, n1, n2;
	cout<<"Наберите число элементов, которые хотите добавить в первую очередь: ";
	cin >> userType;
	for (int i = 0; i < userType; i++)
	{
		cin >> userElem;
		que1->push(userElem);
	}
	cout << "Наберите число элементов, которые хотите добавить во вторую очередь: ";
	cin >> userType;
	for (int i = 0; i < userType; i++)
	{
		cin >> userElem;
		que2->push(userElem);
	}
	do {
		userType = menuLab2_lvl_1_functions.userСhoice("Выберите функцию");
		switch (userType)
		{
		case 1:
			cout << "Выберите очередь 1 или 2: ";
			cin >> userChoice;
			cout << "Введите элемент: ";
			cin >> userElem;
			(userChoice == '1') ? que1->push(userElem) : que2->push(userElem);
			break;
		case 2:
			cout << "Выберите очередь 1 или 2: ";
			cin >> userChoice;
			cout << "Введите номер элемента: ";
			int n;
			cin >> n;
			if (n<0 || n > (que1->Size()-1) && userChoice == '1' || n > (que2->Size()-1)&& userChoice != '1')
			{
				cout << "Нет элемента с таким номером в очереди ";
				cout << ((userChoice == '1') ? "1" : "2") << endl;
				break;
			}
			cout<<"Это элемент "<<((userChoice == '1') ? que1->Peek(n) : que2->Peek(n));
			cout << endl;
			break;
		case 3:
			cout << "Выберите очередь 1 или 2: ";
			cin >> userChoice;
			cout << "Её размер ";
			cout << ((userChoice == '1') ? que1->Size() : que2->Size());
			cout << endl;
			break;
		case 4:
			cout << "Выберите очередь 1 или 2: ";
			cin >> userChoice;
			(userChoice == '1') ? que1->map(mapFunc) : que2->map(mapFunc);
			break;
		case 5:
			cout << "Выберите очередь 1 или 2: ";
			cin >> userChoice;
			(userChoice == '1') ? que1->wwhere(whereStringFunc) : que2->wwhere(whereStringFunc);
			break;
		case 6:
			que1 = que1->Concat(*que2);
			break;
		case 7:
			cout << "Выберите очередь 1 или 2: ";
			cin >> userChoice;
			cout << "Введите элемент номер первого индекса: ";
			cin >> n1;
			cout << "Введите элемент номер второго индекса: ";
			cin >> n2;
			SubSize = n2 - n1;
			if (n1<0 || SubSize<0 || userChoice == '1' && SubSize>que1->Size() || SubSize>que2->Size()&&userChoice != '1')
			{
				cout << "Нльзя извлечь подпоследовательность с такими индексами из очереди ";
				cout << ( (userChoice == '1') ? "1" : "2" ) << endl;
				break;
			}
			(userChoice == '1') ? que1 = que1->GetSubsequence(n1, n2) : que2 = que2->GetSubsequence(n1, n2);
			break;
		case 8:
			cout << "Выберите очередь для поиска её в другой 1 или 2: ";
			cin >> userChoice;
			bool flag;
			flag = ((userChoice == '1') ? que2->SubSequenceSearch(*que1) : que1->SubSequenceSearch(*que2));
			cout << (flag ? "Является подочередью" : "Не является подочередью")<<endl;
			break;
		case 9:
			cout << "Выберите очередь 1 или 2: ";
			cin >> userChoice;
			cout << "Элемент " << endl;
			cout<<((userChoice == '1') ? que1->pop() : que2->pop());
			cout << " удалён из очереди" << endl;
			menuLab2_lvl_1_functions.waitingUserPressEnter();
			break;
		default:
			break;
		}
		cout << "***Содержимое очередей после выполнения функции***" << endl;
		cout << "Первая очередь" << endl;
		que1->printQueue();
		cout << "Вторая очередь" << endl;
		que2->printQueue();
		menuLab2_lvl_1_functions.waitingUserPressEnter();
	} while (userType != 0);
}

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
		testQueue<complexType>();
		break;
	case 3: //Строки
		cout << "Введите количество строк" << endl;
		testQueue<string>();
		break;
	default:
		break;
	}
	return 0;
}