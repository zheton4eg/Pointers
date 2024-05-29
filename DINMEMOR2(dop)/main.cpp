#include <iostream>
using namespace std;
#define tab "\t" 
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_back(int arr[], int &n, const int value);
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];//�������� 'new' ���������� ����� ���������� ������

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;

	Print(arr, n);

	arr=Push_back(arr, n, value);
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)arr[i] = rand() % 100;
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)cout << arr[i] << tab; cout << endl;
}
int* Push_back(int arr[], int &n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return buffer;
}