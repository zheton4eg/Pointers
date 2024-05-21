#include<iostream>
#include <stack>
using namespace std;
using std::cout;
//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows,const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, const int value, int index);
int* erase(int arr[], int& n, const int index);

void main()
{
	setlocale(LC_ALL, "");
#ifdef DINAMIC_MEMORY_1
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);


	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);
	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс числа: "; cin >> index;
	arr = insert(arr, n, value, --index);
	Print(arr, n);

	cout << "Введите индекс удаляемого числа: "; cin >> index;
	arr = erase(arr, n, --index);
	Print(arr, n);




	delete[] arr;
#endif // DINAMIC_MEMORY_1

	int rows = 3;
	int cols = 4;
	//////////////////////////////////////////////////////////////////////////
   /////          Обьявление двумерного динамического массива           /////
  //////////////////////////////////////////////////////////////////////////

     //1) Создаём массив указателей:
	int** arr = new int* [rows];

	//2) Выделяем память под строки:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	//////////////////////////////////////////////////////////////////////////
   /////     Обращение к элементам двумерного динамического массива     /////
  //////////////////////////////////////////////////////////////////////////
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
		cout << endl;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
int* push_back(int arr[],int& n,const int value)
{
	//1) Cоздаём буфепный массив нужного размера
	int* buffer = new int[n + 1];
	//2) Копируем значения элементов исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив
	delete[] arr;
	//4) Подменяем адрес в указателе arr адресом нового массива
	arr = buffer;
	//5) Только после всего этого можно добавить значение в конец массива
	arr[n] = value;
	//6) После добавления элемента кв конец массива, колличество его элементов увеличивается на 1:
	n++;
	return arr;
}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	buffer[0]=value;
	n++;
	return buffer;
}


int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n-1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	n--;
	return buffer;
}
int* insert(int arr[], int& n, const int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[index] = value;
	n++;
	return buffer;
}
int* erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[]arr;
	return buffer;
}