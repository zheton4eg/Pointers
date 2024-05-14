#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);
	int even_count = 0;
	int odd_count = 0;
	//1) ��������� ������� �������� ��� ������ � �������� ���������:
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_count++;
		else odd_count++;
		
	}
	cout << "����������� ������ ���������: " << even_count << endl;
	cout << "����������� �������� ���������: " << odd_count << endl;

	//2) �������� ������ ��� ��������:
	int* even_arr = new int[even_count];
	int* odd_arr = new int[even_count];

	//3) ������� �������� �� ��������� ������� � ���������������:
	for (int i = 0, j = 0, k = 0; i < n; i++)

	{
		//arr[i] % 2 == 0 ? even_arr[j++] = arr[i] : odd_arr[k++] = arr[i];
		(arr[i] % 2 == 0 ? even_arr[j++]:odd_arr[k++]) = arr[i];
	}
		
			
	
	//4)������� ���������� �� �����:
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);
	//5)!!!������� �������!!!
	delete[]odd_arr;
	delete[]even_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] <<tab;
	}
	cout << endl;
}