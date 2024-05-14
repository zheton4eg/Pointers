#include <iostream>
using namespace std;
#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int mainArr[n];
	char* even=new char[n];
	char* odd = new char[n];
		int evenCount = 0, oddCount = 0;
// Заполняем главный массив псевдослучайными числами
	for (int i = 0; i < 10; i++) 
	{
		mainArr[i] = rand() % 100;

// Проверяем значения и добавляем в нужный массив
		if (mainArr[i] % 2 == 0) 
		{
			even[evenCount++] = mainArr[i];
			
			
		}
		else {
			odd[oddCount++] = mainArr[i];
			
		}
		
	}
// Выводим even
	cout<< "Чётные: ";
	for (int i = 0; i < evenCount; i++) 
	{
		cout << (int)even[i] << tab;
	}
	cout <<endl;
// Выводим odd
	cout << "Нечётные: ";
	for (int i = 0; i < oddCount; i++) 
	{
		cout << (int)odd[i] << tab;
	}
	cout << endl;

	delete[]even;
	delete[]odd;
}