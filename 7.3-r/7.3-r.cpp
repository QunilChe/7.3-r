#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Input(int** a, const int rowCount, const int colCount);
void InputRows(int** a, const int rowCount, const int colCount, int rowNo);
void InputRow(int** a, const int rowNo, const int colCount, int colNo);
void Print1(int** a, const int rowCount, const int colCount, int sum, int* c, int i, int j);
void Stovb(int** a, int n, const int colCount, int* c, int i, int j);
void Calc(int** a, const int rowCount, int colCount);
int col_count(int** a, int m, int n, int j, int i);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;
	int High = 23;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	int* c = new int[rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	InputRows(a, rowCount, colCount, 0);
	Print1(a, rowCount, colCount, 0, c, 0, 0);
	cout << col_count(a, rowCount, colCount, 0, 0)<< endl;
	Stovb(a, rowCount, colCount, c, 0, 0);
	Print1(a, rowCount, colCount, 0, c, 0, 0);
	return 0;
}
void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	InputRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void Print1(int** a, const int rowCount, const int colCount, int sum, int* c, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (a[i][j] > 0 && a[i][j] % 2 == 0) sum += a[i][j];
	if (j < colCount - 1)
		Print1(a, rowCount, colCount, sum, c, i, j + 1);

	else
	{
		cout << " sum=" << sum << " ";
		if (i < rowCount - 1)
		{
			cout << endl;
			c[i] = sum;
			Print1(a, rowCount, colCount, 0, c, i + 1, 0);
		}
		else
			cout << endl << endl;
	}
}
int col_count(int** a, int m, int n, int j, int i)
{
	int count = n;
	if (j < n)
	{

		{
			if (i < m)
				if (a[i][j] == 0)
				{
					col_count(a, m, count - 1, j + 1, i + 1);
				}
		}
	}
	return count;
}
void Stovb(int** a, int n, int colCount, int* c, int i, int j)
{
	if (i < (n + (- 1)))
	{
		if (j < n - i - 1)
		{
			if (c[j] > c[j + 1])
			{
				swap(c[j], c[j + 1]);
				swap(a[j], a[j + 1]);
				Stovb(a, n, colCount, c, i + 1, j);
			}
		}
	}
}

