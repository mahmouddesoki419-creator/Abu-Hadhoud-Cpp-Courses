#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
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
			// printf("%0*d  ", 2, Matrix1[i][x]);
			cout << left << setw(3) << Matrix1[i][x] << "  ";
		}
		cout << endl;
	}
}

bool IsNumberInMatrix(int Matrix2[3][3] , int number,short Rows, short Cols)
{
	for(short i = 0; i < Rows; i++)
	{
		for(short x = 0; x < Cols; x++)
		{
			if(Matrix2[i][x] == number)
			{
				return true; 
			}
		}
	}
	return false;
}

void PrintIntersectedNumbers(int Matrix1[3][3] , int Matrix2[3][3] , short Rows , short Cols)
{
int number = 0;

for(short i = 0; i < Rows; i++)
{
	for(short x = 0; x < Cols; x++)
	{
		number = Matrix1[i][x];
		if(IsNumberInMatrix(Matrix2 , number , 3,3)) // send number cheack if in matrix2 or not 
		{//if true will be print it 
			cout << setw(3) << number << "  ";
		}
	}
}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} }; // Example is identity
	int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };
	// MatrixOne(Matrix1 , 3,3);
	cout << "\nMatrix 1: \n";
	printMatrix1(Matrix1, 3, 3);
	cout << "\nMatrix 2: \n";
	printMatrix1(Matrix2, 3, 3);

	cout << "\nIntersected Numbers are: \n\n";
	PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);


	return 0;
}
