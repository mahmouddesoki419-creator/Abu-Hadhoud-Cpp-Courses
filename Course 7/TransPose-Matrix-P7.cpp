#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


void MatrixWithOrderedNumbers(int arr[3][3] , short rows , short cols)//{{1 , 2 , 3} ,
																	//	{4 , 5 , 6} , 
																	// 	{7 , 8 , 9 }}
{
	short num = 1;
	for(int i = 0; i < 3; i++)
	{
		for(int x = 0; x < 3; x++)
		{
			arr[i][x] = num;
			num++;
			// or num = 0;  & num++; first then arr[i][x];
		}
	}
}

void printMatrix(int arr[3][3] , short rows , short cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int x = 0; x < cols; x++)
		{
			cout <<  arr[i][x] << "   ";
		}
		cout << "\n";
	}
}

void TransposeMatrix(int arr[3][3] , int arrTrans[3][3] , short rows ,  short cols)
//																		{{1 , 2 , 3} , 	{{1, 4 , 7} ,
																						// {2 , 5 , 8} ,
																						// {3 , 6 , 9 }}
																	//	{4 , 5 , 6} , 
																	// 	{7 , 8 , 9 }}
{
	for(int i = 0; i < rows; i++)
	{
		for(int x = 0; x < cols; x++)
		{
			arrTrans[i][x] = arr[x][i];// 00 = 00 / 01= 10 / 02 = 20 / 10 = 01 / 11 = 11 / 12 = 21 / 20 = 02 / 21 = 12
			// 22 = 22
		}	
	}

}

void PrintMatrix(int arrTrans[3][3] , short rows , short cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int x = 0; x < cols; x++)
		{
			cout << arrTrans[i][x] << "  ";
		}
		cout << "\n";
	}
}

int main()
{
	int arr[3][3];
	int arrTransPose[3][3];
	MatrixWithOrderedNumbers(arr , 3,3);

	cout << "\nThe following is a 3x3 ordered matrix: \n";
	printMatrix(arr , 3,3);

	TransposeMatrix(arr , arrTransPose , 3 ,3);

	cout << "\nThe following is the transpose matrix: \n";
	PrintMatrix(arrTransPose , 3,3);

	return 0;
}




