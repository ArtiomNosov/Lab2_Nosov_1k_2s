#include <complex.h>
#include <string>

#include "UI.h"
#include "Queque.h"

//��� ���������
string strForListMenuLevel1[9] = { "Push", "Peek", "Size", "Map", "Where", "Concat", "GetSubsequence", "SubSequenceSearch", "pol" };
UIMenu menuLab2_lvl_1_functions(9, strForListMenuLevel1);

int testQueueUI(int userType)
{ 
	switch (userType)
	{
	case 1: //����� �����
		cout << "������� ���������� ����� �����" << endl;
		testQueue((int)1);
		break;
	case 2: //����������� �����
		cout << "������� ���������� ����������� �����" << endl;
		//testQueue<_Fcomplex>();
		break;
	case 3: //������
		cout << "������� ���������� �����" << endl;
		//testQueue<string>();
		break;
	default:
		break;
	}
}

//������� ��� mup T mupFunc(T& arg)
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
		userType = menuLab2_lvl_1_functions.user�hoice();
		switch (userType)
		{
		case 1:
			cout << "�������� ������� 1 ��� 2: ";
			char userChoise;
			cin >> userChoise;
			cout << "������� �������: ";
			T userElem;
			//cin >> userElem;
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
			cout << "Ÿ ������ ";
			cout<< (userChoise == '1') ? que1->Size() : que2->Size();
			cout << endl;
			break;
		case 4:
			cout << "�������� ������� 1 ��� 2: ";
			char userChoise;
			cin >> userChoise;
			(userChoise == '1') ? que1->map(mupFunc): que2->map(mupFunc);
			break;
		case 5:
			cout << "�������� ������� 1 ��� 2: ";
			char userChoise;
			cin >> userChoise;
			(userChoise == '1') ? que1->where(mupFunc) : que2->where(mupFunc);
			break;
		case 6:
			que1 = que1->Concat(que2);
			break;
		case 7:
			cout << "�������� ������� 1 ��� 2: ";
			char userChoise;
			cin >> userChoise;
			cout << "������� ������� ����� ������� �������: ";
			int n1;
			cin >> n1;
			cout << "������� ������� ����� ������� �������: ";
			int n2;
			cin >> n2;
			int SubSize = n2 - n1;
			if (n1<0 || SubSize<0 || userChoise == '1' && SubSize>que1->Size() || SubSize>que2->Size())
			{
				cout << "����� ������� ��������������������� � ������ ��������� �� ������� ";
				cout << (userChoise == '1') ? "1" : "2" << endl;
				break;
			}
			(userChoise == '1') ? que1 = que1->GetSubsequence(n1,n2) : que2 = que2->GetSubsequence(n1, n2);
			break;
		case 8:
			cout << "�������� ������� ��� ������ � � ������ 1 ��� 2: ";
			char userChoise;
			cin >> userChoise;
			bool flag;
			flag = (userChoise == '1') ? que2->SubSequenceSearch(que1) : que1->SubSequenceSearch(que2);
			cout << flag ? "�������� �����������" : "�� �������� �����������";
			break;
		case 9:
			cout << "�������� ������� 1 ��� 2: ";
			char userChoise;
			cin >> userChoise;
			cout << "������� " << endl;
			//printData((userChoise == '1') ? que1->pop() : que2->pop());
			cout<<" ����� �� �������"<<endl;
			menuLab2_lvl_1_functions.waitingUserPressEnter();
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

