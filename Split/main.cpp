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
// ��������� ������� ������ ���������������� �������
	for (int i = 0; i < 10; i++) 
	{
		mainArr[i] = rand() % 100;

// ��������� �������� � ��������� � ������ ������
		if (mainArr[i] % 2 == 0) 
		{
			even[evenCount++] = mainArr[i];
			
			
		}
		else {
			odd[oddCount++] = mainArr[i];
			
		}
		
	}
// ������� even
	cout<< "׸����: ";
	for (int i = 0; i < evenCount; i++) 
	{
		cout << (int)even[i] << tab;
	}
	cout <<endl;
// ������� odd
	cout << "��������: ";
	for (int i = 0; i < oddCount; i++) 
	{
		cout << (int)odd[i] << tab;
	}
	cout << endl;

	delete[]even;
	delete[]odd;
}