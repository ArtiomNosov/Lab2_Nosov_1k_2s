#include <iostream>
using namespace std;
#include <random>
#include <ctime>
std::mt19937 engine;
#include "testUnit.h"
#include "DynamicArray.h"

int randomWholeNumber()
{
	unsigned int res = engine();
	if (res > INT_MAX / 2)
		return (res % MAX_RANDOM_WHOLE_NUMBER);
	else
		return (-1 * (res % MAX_RANDOM_WHOLE_NUMBER));
}

char randomCharSymbol(void)
{
	return (char)(randomWholeNumber() % CHAR_MAX);
}

int testDynamicArrayChar(void)
{
	engine.seed(std::time(nullptr)); // Семя для рандома

	char arr[ITEMS_COUNT] = { 0 };

	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		arr[i] = randomCharSymbol();
	}
	cout << "*Тестирование DynamicArray для типа char" << endl;
	cout << "Начальный массив char:" << endl;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		cout << "a[" << i << "] = " << arr[i] << endl;
	}
	bool flag = true;
	DynamicArray<char> DynArr1(arr, ITEMS_COUNT);
	DynamicArray<char> DynArr2(ITEMS_COUNT);
	DynamicArray<char> DynArr3(DynArr1);

	cout << "Тест конструктора №1 и оператора []" << endl;
	cout << "DynArr1: " << endl;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		flag &= DynArr1[i] == arr[i];
		cout << "DynArr1[" << i << "] = " << DynArr1[i]<<endl;
	}
	flag ? cout << "Succes" << endl : cout << "Fail!";

	cout << "Тест конструктора №2 и GetSize и Set" << endl;
	cout << "DynArr2: " << endl;
	for (int i = 0; i < DynArr2.GetSize();i++)
	{
		DynArr2.Set(i, arr[i]);
	}
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		flag &= DynArr2[i] == arr[i];
		cout << "DynArr2[" << i << "] = " << DynArr2[i]<<endl;
	}
	flag ? cout << "Succes" << endl : cout << "Fail!";

	cout << "Тест конструктора №3" << endl;
	cout << "DynArr3: " << endl;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		flag &= DynArr3[i] == arr[i];
		cout << "DynArr3[" << i << "] = " << DynArr3[i]<<endl;
	}
	flag ? cout << "Succes" << endl : cout << "Fail!";

	// TODO: Доделать тесты. Не работает Resize.
	cout << "Тест Resize" << endl;
	cout << "Перевёрнутый массив для вписывания: " << endl;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		DynArr3.Set(i, arr[ITEMS_COUNT - i - 1]);
	}
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		cout << "DynArr3[" << i << "] = " << DynArr3[i] << endl;
	}
	cout << "DynArr1 до Resize и вписывания инвертированного массива в конец: " << endl;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		flag &= DynArr1[i] == arr[i];
	}
	DynArr1.Resize(ITEMS_COUNT * 2);
	for (int i = ITEMS_COUNT; i < ITEMS_COUNT * 2; i++)
	{
		DynArr1.Set(i, DynArr3.Get(i - ITEMS_COUNT));
	}
	for (int i = 0; i < DynArr1.GetSize(); i++)
	{
		flag &= i < ITEMS_COUNT || DynArr1[i] == arr[ITEMS_COUNT-1-i];
		cout << "DynArr1[" << i << "] = " << DynArr1.Get(i)<<"			flag = "<<flag<<endl;
	}
	flag ? cout << "Succes" << endl : cout << "Fail!";

	return 0;
}