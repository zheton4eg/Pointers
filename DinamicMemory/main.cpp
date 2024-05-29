#include <iostream>
using namespace std;
//#define DIN_MEM_1
#define DIN_MEM_2

#define tab "\t"
void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);

template<typename T>void Print(T arr[], const int n);

template<typename T>T* Push_back(T arr[], int& n, const T value);
template<typename T>T* Push_front(T arr[], int& n, const T value);

template<typename T>T* Pop_back(T arr[], int& n);
template<typename T>T* Pop_Front(T arr[], int& n);

template<typename T>T* Insert(T arr[], int& n, const T value, int index);
template<typename T>T* Erase(T arr[], int& n, int index);

template<typename T>T** Allocated(const int rows, const int cols);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T** Push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** Push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** Insert_row(T** arr, int& rows, const int cols, const int index);
template<typename T>T** Erase_row(T** arr, int& rows, const int cols, const int index);
template<typename T>T** Pop_row_front(T** arr, int& rows, const int cols);
template<typename T>T** Pop_row_back(T** arr, int& rows, const int cols);

template<typename T>void Push_col_back (T** arr, const int rows, int& cols);
template<typename T>void Push_col_front(T** arr, const int rows, int& cols);
template<typename T>void Insert_coll   (T** arr, const int rows, int& cols, const int index);
template<typename T>void Erase_coll    (T** arr, const int rows, int& cols, const int index);
template<typename T>void Pop_col_back  (T** arr, const int rows, int& cols);
template<typename T>void Pop_col_front (T** arr, const int rows, int& cols);

template<typename T>void Clear(T** arr, const int rows);

void main()
{
	setlocale(LC_ALL, "");
	typedef double DataType;
	
#ifdef DIN_MEM_1
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	
	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n); cout << endl;

	DataType value;
	cout << "Введите добавляемое значение в конец: "; cin >> value; cout << endl;

	arr = Push_back(arr, n, value);
	Print(arr, n); cout << endl;

	cout << "Введите добавляемое значение в начало: "; cin >> value; cout << endl;
	arr = Push_front(arr, n, value);
	Print(arr, n); cout << endl;

	arr = Pop_back(arr, n);
	Print(arr, n); cout << tab "Удаление последнего элемента"; cout << endl;

	arr = Pop_Front(arr, n);
	Print(arr, n); cout << tab "Удаление первого элемента"; cout << endl;

	cout << "Введите добавляемое значение: "; cin >> value;
	int index;
	cout << "Введите индекс добавляемого значения: "; cin >> index; cout << endl;

	arr = Insert(arr, n, value, index);
	Print(arr, n); cout << endl;

	cout << "Введите индекс удаляемого значения: "; cin >> index; cout << endl;

	arr = Erase(arr, n, index);
	Print(arr, n);

	delete[]arr;


#endif // DIN_MEM_1

#ifdef DIN_MEM_2
	int rows = 3;
	int cols = 4;

	cout << "Введите кол-во строк: "; cin >> rows;
	cout << "Введите кол-во элементов строки: "; cin >> cols;

	DataType** arr = Allocated<double>(rows, cols);

	//double** arr = new double* [rows];
	//for (int i = 0; i < rows; i++)
	//{
	//	arr[i] = new double[cols];
	//}

    FillRand(arr, rows, cols);
	Print(arr, rows, cols); cout << endl;

	arr = Push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols); cout << "Добавление строки в конец: "; cout << endl;
	Print(arr, rows, cols); cout << endl;
	
	arr = Push_row_front(arr, rows, cols);
	FillRand(arr[0], cols); cout << "Добавление строки в начало: "; cout << endl;
	Print(arr, rows, cols); cout << endl;
	
	int index;
	cout << "Введите индекс добавляемой строки: "; cin >> index;
	arr = Insert_row(arr, rows, cols, index);
	FillRand(arr[index], cols);
	Print(arr, rows, cols); cout << endl;
	
	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = Erase_row(arr, rows, cols, index);
	Print(arr, rows, cols); cout << endl;
	cout << "Удаление первой строки: "; cout << endl;
	arr = Pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	
	
	
	cout << "Удаление последней строки: "; cout << endl;
	arr = Pop_row_back(arr, rows, cols);
	Print(arr, rows, cols); cout << endl;
	
	
	Push_col_back(arr, rows, cols); cout << "Добавляет последний стодбец: "; cout << endl;
	Print(arr, rows, cols); cout << endl;
	
	
	Push_col_front(arr, rows, cols); cout << "Добавляет первый стодбец: "; cout << endl;
	Print(arr, rows, cols); cout << endl;
	
	
	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	Insert_coll(arr, rows, cols, index);
	Print(arr, rows, cols); cout << endl;
	
	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	Erase_coll(arr, rows, cols, index);
	Print(arr, rows, cols); cout << endl;
	
	Pop_col_back(arr, rows, cols); cout << "Удаляет последний стодбец: "; cout << endl;
	Print(arr, rows, cols); cout << endl;
	
	Pop_col_front(arr, rows, cols); cout << "Удаляет первый стодбец: "; cout << endl;
	Print(arr, rows, cols); cout << endl;
	
	Clear(arr, rows);
#endif // DIN_MEM_2

}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)*(arr + i) = rand() % (maxRand - minRand) + minRand;
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;

	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		*(arr + i) /= 100;
	}
}

void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
	}
}
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)cout << arr[i] << tab;
}

template<typename T>T* Push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
template<typename T>T* Push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[]arr;
	buffer[0] = value;
	arr = buffer;
	n++;
	return arr;
}
template<typename T>T* Pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
template<typename T>T* Pop_Front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[]arr;
	return buffer;
}
template<typename T>T* Insert(T arr[], int& n, const T value, int index)
{
	T* buffer = new T[n + 1];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	for (int i = 0; i < n; i++)(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	delete[]arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
template<typename T>T* Erase(T arr[], int& n, int index)
{
	T* buffer = new T[n - 1];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < n; i++)buffer[i - 1] = arr[i];
	for (int i = 0; i < n; i++)(i < index ? buffer[i] : buffer[i - 1]) = arr[i];
	delete[]arr;
	--n;
	return buffer;
}
template<typename T>T** Allocated(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = double(rand() % (maxRand-minRand)+minRand)/100;
		}
	}
}

template<typename T>void Print(T** arr, const int rows, const int cols)
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
template<typename T>T** Push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** Push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[0] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** Insert_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	delete[]arr;
	buffer[index] = new T [cols] {};
	rows++;
	return buffer;
}
template<typename T>T** Erase_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i < index ? i : i + 1];
	delete[]arr;
	rows--;
	return buffer;
}
template<typename T>T** Pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[]arr;
	return buffer;
}
template<typename T>T** Pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
template<typename T>void Push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void Push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void Insert_coll(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)(j < index ? buffer[j] : buffer[j + 1]) = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void Erase_coll(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j < index ? j : j + 1];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void Pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void Pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
