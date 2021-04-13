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
    int userСhoice(string title_str);
    //Ждёт нажатия enter. Выделяет память для ввода строки и освобождает её.
    void waitingUserPressEnter(void);
};



//Возвращает указатель на строку введённую пользователем с клавиатуры с выделением памяти.
//char* get_str();