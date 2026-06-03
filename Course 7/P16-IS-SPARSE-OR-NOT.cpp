#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>

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

int CountNumberInMatrix(int Matrix1[3][3] , short Rows , short Cols , int Number)
{
	short counterZero = 0;
	for(short i = 0; i < Rows; i++)
	{
		for(short x = 0; x < Cols; x++)
		{
			if(Matrix1[i][x] == Number)
			{
				counterZero++;
			}
		}
	}
	return counterZero;
}

bool CheackIsSparseOrNor(int Matrix1[3][3] , short Rows , short Cols)
{
	short MatrixSize = Rows * Cols;//9

	return CountNumberInMatrix(Matrix1 , 3 , 3 , 0) >=  ceil((float)(MatrixSize / 2)); //5

}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3] = {{0 , 0, 0} , { 0 , 0 , 8} , { 0 , 3 , 1}}; //Example is identity
	//MatrixOne(Matrix1 , 3,3);
	cout << "\nMatrix 1: \n";
	printMatrix1(Matrix1, 3, 3);

	if(CheackIsSparseOrNor(Matrix1 , 3,3))
	{
		cout << "\nYes: It is Sparse.";
	}
	else 
	{
		cout << "\nNo: It's Not Sparse.";//
	}

	cout << "\n" << ceil(4.2); // الفاكشن سيل تقوم بتقريب الرقم للاعلي هنا تقرب الي 5
	// اما round داله هي  التي تقرب عل حسب عدد عشري 
	
	return 0;
}
