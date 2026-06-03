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
			//printf("%0*d  ", 2, Matrix1[i][x]);
		 	cout << left << setw(3) << Matrix1[i][x] << "  ";
		}
		cout << endl;
	}
}

short CheackInbutNumberCountInMatrix(int MatrixOne[3][3] , short rows ,short cols , int& InputNumber)
{
	short counter = 0;

	for(short i = 0; i < rows; i++)
	{
		for(short x = 0; x < cols; x++)
		{
			if(MatrixOne[i][x] == InputNumber)
			{
				counter++;
			}
		}
	}
	return counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3]; //= {{11 , 0, 0} , { 0 , 11 , 0} , { 0 , 0 , 11}}; //Example is identity
	MatrixOne(Matrix1 , 3,3);
	cout << "\nMatrix 1: \n";
	printMatrix1(Matrix1, 3, 3);

	int number = 0;
	cout << "\nEnter The Number to count in matrix? ";
	cin >> number;


	cout << "\nNumber " << number << " count in Matrix is "
	 << CheackInbutNumberCountInMatrix(Matrix1 , 3,3 , number) << endl;

	return 0;
}
