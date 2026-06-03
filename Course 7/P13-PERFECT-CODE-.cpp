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

/*/void MatrixOne(int Matrix1[3][3], short rows, short cols)
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
}/*/

void printMatrix1(int Matrix1[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short x = 0; x < cols; x++)
		{
			printf("%0*d  ", 2, Matrix1[i][x]);
			// cout << left << setw(3) << Matrix1[i][x] << "  ";
		}
		cout << endl;
	}
}

int sumMatrix1(int Matrix1[3][3], short Rows, short Cols)
{
	int sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int x = 0; x < Cols; x++)
		{
			sum += Matrix1[i][x];
		}
	}
	return sum;
}


bool IsIdentityMatrix(int Matrix1[3][3], short rows, short cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{// cheack for diagonals element 
			if(i == j && Matrix1[i][j] != 1) // بمجرد شرط ميتحققش مش ايكمل 
			{
				return false;
			}// cheack for rest element
			else if (i != j && Matrix1[i][j] != 0)// وها مجرد ميتحققش بتساوي عنصر بصفر مش ايكمل
			{
				return false;
			}
		}
	}
	return true;//  ف مفروض فوق في الشروط يكمل 1 وشرط تاني يكمل 0 للعنصر الاخر 
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3] = {{1 , 0, 0} , { 0 , 1 , 0} , { 0 , 0 , 1}}; //Example is identity

	cout << "\nMatrix 1: \n";
	printMatrix1(Matrix1, 3, 3);

	if(IsIdentityMatrix(Matrix1 , 3,3))
	{
		cout << "\nYes: Matrix is identity.";
	}
	else 
		cout << "\nNo: Matrix is NOT identity.";



	return 0;
}
