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
//	{{1 , 2 , 1} ,
// 	 {5 , 5 , 5} ,
// 	 {7 , 3 , 7 }}
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

bool isPalindromeOrNot(int Matrix[3][3] , short Rows , short Cols)
{
	int CurrentVal = 0;
	for(int i = 0; i < Rows; i++)
	{
		for(int x = 0; x < Cols / 2; x++)// 1
		{ 
			if(Matrix[i][x] != Matrix[i][Cols - 1 - x])// مش اشيشك عل الشرط ده غير لما يبقي في توافق حقيقي ووصل بلفعل
			{//4 - 1 - 0 = 3// 4 - 1 - 1 = 2 here if mtrx[4][4] 
				return false;//هنا ايطلع من الفانكشن مش ايكمل وايرجع فالس  
			}
		}
	}
	return true;// طالما وصل لهنا يبقي الشرط اتحقق وايرجع ترو 
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3] = { {1,5,1},{5,9,},{1,8,1} }; // Example is identity

	//MatrixOne(Matrix1 , 3,3);

	cout << "\nMatrix 1: \n";
	printMatrix1(Matrix1, 3, 3);

	if(isPalindromeOrNot(Matrix1 , 3,3))
	{
		cout << "\nYes: Matrix is Palindrome.";
	}
	else 
		cout << "\nNo: Matrix is Not Palindrome.";

	return 0;
}
