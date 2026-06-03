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
			Matrix1[i][x] = RandomNmber(1, 100);
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


short MinimumNumberInMatrix(int Matrix1[3][3] , short Rows , short Cols)
{
	short MinimumNum = Matrix1[0][0];
	for(int i = 0; i < Rows; i++)
	{
		for(int x = 0; x < Cols; x++)
		{
			if(Matrix1[i][x] < MinimumNum)
			{
				MinimumNum = Matrix1[i][x];
			}
		}
	}
	return MinimumNum;
}

short MaxNumberInMatrix(int Matrix1[3][3] , short Rows , short Cols)
{
	short Max = Matrix1[0][0];
	for(int i = 0; i < Rows; i++)
	{
		for(int x = 0; x < Cols; x++)
		{
			if(Matrix1[i][x] > Max)
			{
				Max = Matrix1[i][x];
			}
		}
	}
	return Max;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} }; // Example is identity
	
	MatrixOne(Matrix1 , 3,3);

	cout << "\nMatrix 1: \n";
	printMatrix1(Matrix1, 3, 3);

	cout << "\nMinimum Number is: " << MinimumNumberInMatrix(Matrix1 , 3,3) << endl;
	cout << "Max Number is: " << MaxNumberInMatrix(Matrix1 , 3,3) << endl;

	return 0;
}
