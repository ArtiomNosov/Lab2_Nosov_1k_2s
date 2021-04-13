#include <complex.h>
#include <string>

#include "UI.h"
#include "Queque.h"

//��� ���������
string strForListMenuLevel1[8] = { "Push", "Peek", "Size", "Map", "Where", "Concat", "GetSubsequence", "SubSequenceSearch" };
UIMenu menuLab2_lvl_1_functions(8, strForListMenuLevel1);



int testQueueUI(int userType)
{ 
	switch (userType)
	{
	case 1: //����� �����
		cout << "������� ���������� ����� �����" << endl;
		testQueue<int>();
		break;
	case 2: //����������� �����
		cout << "������� ���������� ����������� �����" << endl;
		testQueue<_Fcomplex>();
		break;
	case 3: //������
		cout << "������� ���������� �����" << endl;
		testQueue<string>();
		break;
	default:
		break;
	}
}

//������� ��� mup T mupFunc(T& arg)
template <typename T>
T
template <typename T>
int testQueue()
{
	Queue<T>* que1;
	Queue<T>* que2;
	int userType;
	do {
		userType = menuLab2_lvl_1_functions.user�hoice();
		switch (userType)
		{
		case 1:
			cout << "�������� ������� 1 ��� 2: ";
			char userChoise;
			cin >> userChoise;
			cout << "������� �������: ";
			T userElem;
			cin >> userElem;
			(userChoise == '1') ? que1->push(userElem) : que2->push(userElem);
			break;
		case 2:
			cout << "�������� ������� 1 ��� 2: ";
			char userChoise;
			cin >> userChoise;
			cout << "������� ������� ����� ��������: ";
			int n;
			cin >> n;
			if (n<0 || n > que1->Size() && userChoise == '1' || n > que2->Size())
			{
				cout << "��� �������� � ����� ������� � ������� ";
				cout << (userChoise == '1') ? "1" : "2" << endl;
				break;
			}
			(userChoise == '1') ? que1->Peek(n) : que2->Peek(n);
			break;
		case 3:
			cout << "�������� ������� 1 ��� 2: ";
			char userChoise;
			cin >> userChoise;
			cout<<"Ÿ ������ "
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
		cout << "������ �������" << endl;
		que1->printQueue();
		cout << "������ �������" << endl;
		que2->printQueue();
	} while (userType != 0);
}