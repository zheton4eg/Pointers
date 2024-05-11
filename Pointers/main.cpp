#include <iostream>
using namespace std;
//#define POINTERS_BASIKS
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;
	cout << &a << endl;//взятие адреса переменной 'a' 
	cout << pa << endl;//вывод адреса, хранящегося в указателе
	cout << *pa << endl;//Разыменовываем указатель 'pa' и получаем значение хранящееся по адресу

	int* pb;
	int b = 3;
	*pb = &b;
	//int - 'int'
	//int* - указатель на'int'
	//double* - указатель на'double'  
#endif // POINERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout <<  *(arr+i) << "\t";
	}
	cout << endl;


}