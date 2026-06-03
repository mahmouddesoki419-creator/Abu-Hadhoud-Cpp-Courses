#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

int RandomNmber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void MatrixOne(int Matrix1[3][3], short rows, short cols) 
														//		{{1 , 2 , 3} ,
														 // 	 {4 , 5 , 6} ,
														  // 	 {7 , 8 , 9 }}
{
	for (short i = 0; i < 3; i++)
	{
		for (short x = 0; x < 3; x++)
		{
			Matrix1[i][x] = RandomNmber(1, 10);
		}
	}
}

void printMatrix1(int Matrix1[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short x = 0; x < cols; x++)
		{
			printf("%0*d  ", 2 , Matrix1[i][x]);
			// cout << left << setw(3) << Matrix1[i][x] << "  ";
		}
		cout << endl;
	}
}

//MATRIX  2
void MatrixTwo(int Matrix2[3][3] , short Rows, short Cols)
{
	for(int i = 0; i < Rows; i++)
	{
		for(int x = 0; x < Cols; x++)
		{
			Matrix2[i][x] = RandomNmber(1 , 10); 
		}
	}
}

void PrintMatrix2(int Matrix[3][3] , short Rows , short Cols)
{
	for(int i = 0; i < Rows; i++)
	{
		for(int x = 0; x < Cols; x++)
		{
			printf("%0*d  " , 2 , Matrix[i][x]);
			// cout << left << setw(3) << Matrix1[i][x] << "  ";

		}
		cout << endl;
	}
}


bool AreEqualMatrices(int Matrix1[3][3] , int Matrix2[3][3] , short rows , short cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int x = 0; x < cols; x++)
		{
			if(Matrix1[i][x] != Matrix2[i][x])// اذا اول عنصر لا يساوي عنصر ماتريكس 2 ايطلع من اللوب ومش ايكمل باقي العناصر
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	MatrixOne(Matrix1, 3, 3);
	cout << "\nMatrix 1: \n";
	printMatrix1(Matrix1, 3, 3);

	int Matrix2[3][3];
	MatrixTwo(Matrix2 , 3,3);
	cout << "\nMatrix 2: \n";
	PrintMatrix2(Matrix2 , 3,3);

	if(AreEqualMatrices(Matrix1 , Matrix2 , 3,3))
	{
		cout << "Yes: matrices are Typical.";
	}
	else 
		cout << "NO: matrices are NOT Typical.";

	return 0;
}
