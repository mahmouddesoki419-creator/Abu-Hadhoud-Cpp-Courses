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

void printEachRowSum(int arr[3][3] , short rows , short cols)// See the difference between it and the first print naseted loop. 
{
for(int i = 0; i < rows; i++)// هنا بنمشي علي صفوف
{
	cout << "\nThe following are the sum of each row in the matrix: \n";

	cout << "Row " << i + 1 << " Sum: " << RowSum(arr , i , cols) << endl;//نستدعي العمود لنجمع الاعمده بالصف ثم نطبعهم
}
}

int main()
{
	//Seeds the random number generator in c++, called only once
	srand((unsigned)time(NULL));
	int arr[3][3];

	fillMatrixWithRandomNumbers(arr , 3 , 3);//{{1 , 2 , 3} , {2 , 4 , 6} , {3 , 6 , 9}}
	
	cout << "\nThe following is a 3x3 Random matrix:\n";
	PrintMatrix(arr , 3 , 3);

	printEachRowSum(arr , 3 , 3);// نطبع النتيجه الجمع


	return 0;
}





