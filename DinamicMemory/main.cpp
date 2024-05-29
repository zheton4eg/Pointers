#include <iostream>
using namespace std;
//#define DIN_MEM_1
//#define DIN_MEM_2

#define tab "\t"

void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);

int* Push_back(int arr[], int& n, const int value);
int* Push_front(int arr[], int& n, const int value);

int* Pop_back(int arr[], int& n);
int* Pop_Front(int arr[], int& n);

int* Insert(int arr[], int& n, const int value, int index);
int* Erase(int arr[], int& n, int index);

int** Allocated(const int rows, const int cols);
void FillRand(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int** Push_row_back(int** arr, int& rows, const int cols);
int** Push_row_front(int** arr, int& rows, const int cols);
int** Insert_row(int** arr, int& rows, const int cols, const int index);
int** Erase_row(int** arr, int& rows, const int cols, const int index);
int** Pop_row_front(int** arr, int& rows, const int cols);
int** Pop_row_back(int** arr, int& rows, const int cols);

void Push_col_back(int** arr, const int rows, int& cols);
void Push_col_front(int** arr, const int rows, int& cols);
void Insert_coll(int** arr, const int rows, int& cols, const int index);
void Erase_coll(int** arr, const int rows, int& cols, const int index);
void Pop_col_back(int** arr, const int rows, int& cols);
void Pop_col_front(int** arr, const int rows, int& cols);

void Clear(int** arr, const int rows);

void main()
{
	setlocale(LC_ALL, "");
#ifdef DIN_MEM_1
	int n = 5;
	cout << "������� ������ �������: "; cin >> n;

	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n); cout << endl;
	int value;
	cout << "������� ����������� �������� � �����: "; cin >> value; cout << endl;

	arr = Push_back(arr, n, value);
	Print(arr, n); cout << endl;

	cout << "������� ����������� �������� � ������: "; cin >> value; cout << endl;
	arr = Push_front(arr, n, value);
	Print(arr, n); cout << endl;

	arr = Pop_back(arr, n);
	Print(arr, n); cout << tab "�������� ���������� ��������"; cout << endl;

	arr = Pop_Front(arr, n);
	Print(arr, n); cout << tab "�������� ������� ��������"; cout << endl;

	cout << "������� ����������� ��������: "; cin >> value;
	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index; cout << endl;

	arr = Insert(arr, n, value, index);
	Print(arr, n); cout << endl;

	cout << "������� ������ ���������� ��������: "; cin >> index; cout << endl;

	arr = Erase(arr, n, index);
	Print(arr, n);

	delete[]arr;


#endif // DIN_MEM_1

	int rows = 3;
	int cols = 4;

	cout << "������� ���-�� �����: "; cin >> rows;
	cout << "������� ���-�� ��������� ������: "; cin >> cols;

	int** arr = Allocated(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols); cout << endl;

	arr = Push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols); cout << "���������� ������ � �����: "; cout << endl;
	Print(arr, rows, cols); cout << endl;

	arr = Push_row_front(arr, rows, cols);
	FillRand(arr[0], cols); cout << "���������� ������ � ������: "; cout << endl;
	Print(arr, rows, cols); cout << endl;

	int index;
	cout << "������� ������ ����������� ������: "; cin >> index;
	arr = Insert_row(arr, rows, cols, index);
	FillRand(arr[index], cols);
	Print(arr, rows, cols); cout << endl;

	cout << "������� ������ ��������� ������: "; cin >> index;
	arr = Erase_row(arr, rows, cols, index);
	Print(arr, rows, cols); cout << endl;
	cout << "�������� ������ ������: "; cout << endl;
	arr = Pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);



	cout << "�������� ��������� ������: "; cout << endl;
	arr = Pop_row_back(arr, rows, cols);
	Print(arr, rows, cols); cout << endl;


	Push_col_back(arr, rows, cols); cout << "��������� ��������� �������: "; cout << endl;
	Print(arr, rows, cols); cout << endl;


	Push_col_front(arr, rows, cols); cout << "��������� ������ �������: "; cout << endl;
	Print(arr, rows, cols); cout << endl;


	cout << "������� ������ ������������ �������: "; cin >> index;
	Insert_coll(arr, rows, cols, index);
	Print(arr, rows, cols); cout << endl;

	cout << "������� ������ ���������� �������: "; cin >> index;
	Erase_coll(arr, rows, cols, index);
	Print(arr, rows, cols); cout << endl;

	Pop_col_back(arr, rows, cols); cout << "������� ��������� �������: "; cout << endl;
	Print(arr, rows, cols); cout << endl;

	Pop_col_front(arr, rows, cols); cout << "������� ������ �������: "; cout << endl;
	Print(arr, rows, cols); cout << endl;

	Clear(arr, rows);
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)arr[i] = rand() % 100;
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)cout << arr[i] << tab;
}

int* Push_back(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
int* Push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[]arr;
	buffer[0] = value;
	arr = buffer;
	n++;
	return arr;
}
int* Pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
int* Pop_Front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[]arr;
	return buffer;
}
int* Insert(int arr[], int& n, const int value, int index)
{
	int* buffer = new int[n + 1];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	for (int i = 0; i < n; i++)(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	delete[]arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* Erase(int arr[], int& n, int index)
{
	int* buffer = new int[n - 1];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < n; i++)buffer[i - 1] = arr[i];
	for (int i = 0; i < n; i++)(i < index ? buffer[i] : buffer[i - 1]) = arr[i];
	delete[]arr;
	--n;
	return buffer;
}
int** Allocated(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
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
int** Push_row_back(int** arr, int& rows, const int cols)
{
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
int** Push_row_front(int** arr, int& rows, const int cols)
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
int** Insert_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	delete[]arr;
	buffer[index] = new int [cols] {};
	rows++;
	return buffer;
}
int** Erase_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i < index ? i : i + 1];
	delete[]arr;
	rows--;
	return buffer;
}
int** Pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[]arr;
	return buffer;
}
int** Pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
void Push_col_back(int** arr, const int rows, int& cols)
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
void Push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void Insert_coll(int** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)(j < index ? buffer[j] : buffer[j + 1]) = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void Erase_coll(int** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j < index ? j : j + 1];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void Pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void Pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
