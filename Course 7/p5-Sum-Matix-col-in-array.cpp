#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int randomNumber(short from , short to)
{
	return rand() % (to - from + 1) + from;
}

void fillMatrixWithRandomNumbers( int arr[3][3] , short Rows , short Cols )
{

	for(int i = 0; i < Rows; i++)
	{
		for(int x = 0; x < Cols; x++)
		{
			arr[i][x] = randomNumber(1 , 100);
		}
	}

}

void printMatrix(int arr[3][3] , short Rows , short Cols)
{
	for(int i = 0; i < Rows; i++)
	{
		for(int x = 0; x < Cols; x++)
		{
			cout <<  setw(3) << arr[i][x] << "  "; 
		}
		cout << "\n";
	}
}

int ColSum(int arr[3][3] , short Rows , short ColNumber)
{
int sum = 0;	

for(int i = 0; i < Rows; i++)
{
	sum += arr[i][ColNumber] ; 
}
return sum;
}

void printEachColSum(int arrSum[3] , int arr[3][3] , short Rows , short Cols)
																/*/      {{3 , 4 ,6 } , 
																		{2 , 3 , 1 } , 
																		{3 , 6 , 1}}     /*/
{
for(int x = 0; x < Cols; x++)
{
	arrSum[x] += ColSum(arr , Rows , x); 
}

}

void printColsSumArray(int arrSum[3] , short cols)
{
cout << "\nThe Following are the sum of each col in the matrix: \n";
for(int i = 0; i < cols; i++)
{
	cout << "Col " << i + 1 << " Sum: " << arrSum[i] << endl;
}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];
	fillMatrixWithRandomNumbers(arr , 3 , 3);

	cout << "\nThe Following is a 3x3 random Matrix:\n"; 
	printMatrix(arr , 3 , 3);

	printEachColSum(arrSum, arr , 3 , 3);

	printColsSumArray(arrSum , 3);

	cout << "\n";
	cout << arrSum[0] << endl;
	cout << arrSum[1] << endl;
	cout << arrSum[2] << endl;
	return 0;
}




