#include <iostream>

#include "UI.h"

UIMenu::UIMenu(int numberOfMenuElements, string* strForListMenu)
{
	len = numberOfMenuElements;
	shoice = new string[len];
	for (int i = 0; i < len; i++)
		shoice[i] = strForListMenu[i];
}
UIMenu::UIMenu()
{
	len = 0;
	shoice = NULL;
};
UIMenu::~UIMenu() 
{
};
int UIMenu::userÑhoice(string title)
{
	char ch;
	do {
		system("cls");
		cout<<title<<endl;
		for (int i = 0; i < len; i++)
			cout << i + 1<< ") "<<shoice[i]<<endl;
		cout<<"Make your choice (0 - Exit):"<<endl;
		ch = cin.get();
	} while ((ch < '0') || (ch > ((char)'0' + len)));
	cout<<ch<<endl;
	return (int)ch - '0';
};
//
void UIMenu::waitingUserPressEnter(void)
{
	cout<<"PRESS ENTER TO COUNTINUE!"<<endl;
	do {} while (cin.get() != 13);
}