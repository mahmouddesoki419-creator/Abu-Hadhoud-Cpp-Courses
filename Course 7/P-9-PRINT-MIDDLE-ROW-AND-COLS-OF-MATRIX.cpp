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

void MatrixOne(int Matrix1[3][3], short rows, short cols) //				{{1 , 2 , 3} ,
														  //	{4 , 5 , 6} ,
														  // 	{7 , 8 , 9 }}
{
	for (short i = 0; i < 3; i++)
	{
		for (short x = 0; x < 3; x++)
		{
			Matrix1[i][x] = RandomNmber(1, 2000);
		}
	}
}

void printMatrix(int Matrix1[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short x = 0; x < cols; x++)
		{
			printf(" %0*d ", 4 , Matrix1[i][x]);
			// cout << left << setw(3) << Matrix1[i][x] << "  ";
		}
		cout << endl;
	}
}

void printMiddleRowOfMatrix1(int Matrix1[3][3], short Rows, short Cols)
{
	short MiddleRow = Rows / 2;
	for (int i = 0; i < Rows; i++)
	{
		printf("  %0*d  " , 4 , Matrix1[MiddleRow][i]);
	}
	cout << "\n";
}

void PrintMiddleColOfMartrix1(int Matrix1[3][3], short Rows, short Cols)
{
	short MiddleCol = Cols / 2;
	for (int i = 0; i < Rows; i++)
	{
		printf("  %04d  ", Matrix1[i][MiddleCol]); // ملاحظة: إذا كنت متأكداً أن التنسيق ثابت ولن يتغير (مثلاً دائماً خانتين)، فاستخدام "%02d" هو الأسهل والأبسط. أما "%0*d" فتُستخدم حصراً عندما يكون عدد الخانات متغيراً بناءً على بيانات البرنامج.
	}
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	MatrixOne(Matrix1, 3, 3);
	cout << "\nMatrix 1: \n";
	printMatrix(Matrix1, 3, 3);

	cout << "\nMiddle Row of Matrix1 is: \n";
	printMiddleRowOfMatrix1(Matrix1, 3, 3);

	cout << "\nMiddle Col of Matrix1 is: \n";
	PrintMiddleColOfMartrix1(Matrix1, 3, 3);

	return 0;
}
