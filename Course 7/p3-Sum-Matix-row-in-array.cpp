/*Write a program to fill a 3x3 matrix with random numbers ,
then sum each row in separate array and print the results:*/

#include <iostream>
#include <iomanip>
using namespace std;

int  RandNumber(int from , int to)
    {
        return rand() % (to - from + 1) + from;
    }

void fillMatrixWithRandomNumbers(int arr[3][3] , short Rows , short Cols)
{
	for(int i = 0; i < Rows; i++)
	{
		for(int x = 0; x < Cols; x++)
		{
			arr[i][x] = RandNumber(1 , 100);
		}
		cout << endl;
	}
}

void PrintMatrix(int arr[3][3] , short Rows , short Cols)
{
for(int i = 0; i < Rows; i++)
{
	for(int x = 0; x < Cols; x++)
	{
		cout << left << setw(3) << arr[i][x] << " ";
	}
	cout << "\n";
}
}

int RowSum (int arr[3][3] , short RowNumber , short cols)
{
int sum = 0;

for(short j = 0; j <= cols - 1; j++)
{
sum += arr[RowNumber][j];
}
return sum;
}

void SumMatrixRowsInArray(int arrSum[3] , int arr[3][3] , short Rows , short cols)//  ملي 1 دايمنشال اراي عباره عن  نتيجه جمع الصف  
{
	for(int i = 0; i < Rows; i++)
	{
		arrSum[i] = RowSum( arr ,  i , cols);

	}
	
}

void PrintRowsSumArray(int arrSum[3] , short row)// طباعه الاراي عباره عن جمع صف من صفوف الاراي 2 دايمنشال 
{
	cout << "\nThe following are the sum of each row in the matrix: \n";

	for(int i = 0; i < row; i++)
	{
		cout << "Row " << i + 1 << " Sum: " << arrSum[i] << endl;
	}
}

int main()
{
	//Seeds the random number generator in c++, called only once
	srand((unsigned)time(NULL));
	int arr[3][3];
	int arrSum[3];

	fillMatrixWithRandomNumbers(arr , 3 , 3);//{{1 , 2 , 3} , {2 , 4 , 6} , {3 , 6 , 9}}
	cout << "The following is a 3x3 Random matrix:\n";
	PrintMatrix(arr , 3 , 3);

	SumMatrixRowsInArray(arrSum , arr , 3 , 3);

	PrintRowsSumArray(arrSum , 3);


	return 0;
}




