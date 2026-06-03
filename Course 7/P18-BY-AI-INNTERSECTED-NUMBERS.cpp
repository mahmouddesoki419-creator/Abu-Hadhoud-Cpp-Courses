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

bool ExsitedInMatrix1(int Matrix1[3][3], short Rows, short Cols, short CurrentVal)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int x = 0; x < Cols; x++)
		{
			if (Matrix1[i][x] == CurrentVal)
			{
				return true;
			}
		}
	}
	return false;
}

vector<int> IntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols, vector<int> &IntersectedArr)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int x = 0; x < Cols; x++)
		{
			short CurrentVal = Matrix2[i][x];
			if (ExsitedInMatrix1(Matrix1, 3, 3, CurrentVal))
			{
				bool alreadyExists = false;
				for (int val : IntersectedArr)
				{
					if (val == CurrentVal)
					{
						alreadyExists = true;
						break;
					}
				}
				if (alreadyExists == false)
				{
					IntersectedArr.push_back(CurrentVal);
				}
			}
		}
	}
	return IntersectedArr;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3] = {{1, 7, 9}, {0, 4, 8}, {10, 3, 1}}; // Example is identity
	int Matrix2[3][3] = {{7, 1, 2}, {0, 7, 8}, {10, 3, 1}};
	vector<int> IntersectedArr;
	// MatrixOne(Matrix1 , 3,3);
	cout << "\nMatrix 1: \n";
	printMatrix1(Matrix1, 3, 3);
	cout << "\nMatrix 2: \n";
	printMatrix1(Matrix2, 3, 3);

	IntersectedNumbers(Matrix1, Matrix2, 3, 3, IntersectedArr);

	cout << "\nIntersected Numbers are: \n";
	for (int &i : IntersectedArr)
	{
		cout << i << "  ";
	}

	return 0;
}
