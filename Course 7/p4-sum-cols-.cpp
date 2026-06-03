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
	sum += arr[i][ColNumber] ;//الصف ثابت يتغير فقط العمود من الصف التحته 
}
return sum;
}

void printEachColSum(int arr[3][3] , short Rows , short Cols)
																/*/      {{3 , 4 ,6 } , 
																		{2 , 3 , 1 } , 
																		{3 , 6 , 1}}     /*/
{
cout << "\nThe Following are the sum of each col in the matrix: \n";
for(int x = 0; x < Cols; x++)
{
cout << "Col " << x + 1 << " Sum: " << ColSum(arr , Rows , x) << endl;//نستدعي مجموع عمود الصف الاول والتاني والتالت 
}

}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	fillMatrixWithRandomNumbers(arr , 3 , 3);

	cout << "\nThe Following is a 3x3 random Matrix:\n"; 
	printMatrix(arr , 3 , 3);

	printEachColSum(arr , 3 , 3);

	return 0;
}




