#include<iostream>
#include <stack>
using namespace std;
using std::cout;
//#define DINAMIC_MEMORY_1
//#define DINAMIC_MEMORY_2
#define performance_check
//#define SYNTAX
//#define NEVER_DO_IN_THIS_WAY

#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand=0, int maxRand=100);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, const int value, int index);
int* erase(int arr[], int& n, const int index);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int position);
int** erase_row(int** arr, int& rows, const int cols, int index2);

int** pop_row_back(int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);

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

#ifdef DINAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите колличество строк: "; cin >> rows;
	cout << "Введите колличество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	cout << "Memory allocated, loading data" << endl;
	FillRand(arr, rows, cols);
	cout << "Data loaded" << endl;
	cout << "Press any key to add row" << endl;
	system("PAUSE");

	arr = push_row_back(arr, rows, cols);
	cout << "Row added" << endl;
	cout << "To clear memory";
	system("PAUSE");

	Clear(arr, rows);
#endif // DINAMIC_MEMORY_2
#ifdef performance_check
	int rows;
	int cols;
	cout << "Введите колличество строк: "; cin >> rows;
	cout << "Введите колличество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols);
	Print(arr, rows, cols);
	cout << endl;

	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols);
	Print(arr, rows, cols);
	cout << endl;

	int index;
	cout << "Введите позицию добавляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	FillRand(arr[index], cols, 100, 1000);
	Print(arr, rows, cols);
	cout << endl;


	int index2;
	cout << "Введите позицию удаляемой строки: "; cin >> index2;
	arr = erase_row(arr, rows, cols, index2);
	Print(arr, rows, cols);
	cout << endl;

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);



	Clear(arr, rows);
	cout << endl;
#endif // performance_check

}
int** Allocate(const int rows, const int cols)
{
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
	return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand-minRand)+minRand;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
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
int* push_back(int arr[], int& n, const int value)
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
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
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
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
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
		buffer[i] = arr[i + 1];
	}
	delete[]arr;
	return buffer;
}
int** push_row_back(int** arr, int& rows, const int cols)
{

#ifdef NEVER_DO_IN_THIS_WAY
	int** buffer = Allocate(rows + 1, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, rows);
	buffer[rows++] = new int[cols];
	return buffer;
#endif // NEVER_DO_IN_THIS_WAY
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, int position)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	for (int i = position; i < rows; i++)buffer[i + 1] = arr[i];
	delete[]arr;
	buffer[position] = new int[cols];
	rows++;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr[index];
	delete[]arr;
	rows--;
	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[]arr[rows];
	delete arr;
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}