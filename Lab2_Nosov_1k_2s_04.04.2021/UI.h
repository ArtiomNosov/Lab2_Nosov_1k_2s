#pragma once
#include <string>
using namespace std;

class UIMenu {
    int len;
    string* shoice;
public:
    UIMenu(int numberOfMenuElements, string *);
    UIMenu();
    ~UIMenu();
    int user�hoice(string title_str);
    //��� ������� enter. �������� ������ ��� ����� ������ � ����������� �.
    void waitingUserPressEnter(void);
};



//���������� ��������� �� ������ �������� ������������� � ���������� � ���������� ������.
//char* get_str();