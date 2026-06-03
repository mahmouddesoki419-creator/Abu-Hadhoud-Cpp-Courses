#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <string>



using namespace std;


int RandomNmber(int min , int max)
{
	return rand() % (max - min + 1) + min;
}


void MatrixOne(int arr[3][3] , short rows , short cols)//{{1 , 2 , 3} ,
																	//	{4 , 5 , 6} , 
																	// 	{7 , 8 , 9 }}
{
	for(short i = 0; i < 3; i++)
	{
		for(short x = 0; x < 3; x++)
		{
			arr[i][x] = RandomNmber(1 , 10);
		}
	}
}

void MatrixTwo(int arr2[3][3] ,  short rows ,  short cols)
{
	for(short i = 0; i < rows; i++)
	{
		for(short x = 0; x < cols; x++)
		{
			arr2[i][x] = RandomNmber(1 , 10);
		}	
	} 

}

void printMatrix(int arr[3][3] ,  short rows , short cols)
{
	for(short i = 0; i < rows; i++)
	{
		for(short x = 0; x < cols; x++)
		{
			printf( "%02d ", arr[i][x]); 
			//cout << left << setw(3) << arr[i][x] << "  ";
		}
		cout << endl;
	}
}

void FillMatrixArr1XArr2(int arrMultiply[3][3] , int arr[3][3] , int arr2[3][3] , short Rows , short Cols)
{
for(short i = 0; i < Rows; i++)
{
	for(short x = 0; x < Cols; x++)
	{
		arrMultiply[i][x] = arr[i][x] * arr2[i][x];
	}
}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arr2[3][3];
	MatrixOne(arr , 3,3);
	MatrixTwo(arr2 , 3,3);

	cout << "\nMatrix 1: \n";
	printMatrix(arr , 3,3);

	cout << "\nMatrix 2: \n";
	printMatrix(arr2 , 3,3);

	int arrMultiply[3][3];
	FillMatrixArr1XArr2(arrMultiply , arr , arr2 , 3 ,3);

	cout << "\nResults: \n";
	printMatrix(arrMultiply , 3 , 3);
	return 0;
}




