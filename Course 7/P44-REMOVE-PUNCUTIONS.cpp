#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string stringWTpun(string S1)
{
	string Result = "";
	for(int i = 0; i < S1.length(); i++) //Welcome to Jorden , Jorden is a nice Country ; it's amazing."
	{
		if(ispunct(S1[i]))//  لو الحرف يساوي بانكويشن امسحو من السترينج
		{

		S1.erase(i , 1);// نمسح الحرف 
			// برميتر الاول ل مكان الحرف والتاني لطوله


		i--;//  نرجع خطوه لورا عشان السترينح كله بيتشفت خطوه   

		}
	}
	
	return S1;
}

int main()
{

	string S1 = "Welcome to Jorden , Jorden is a nice Country ; it's amazing.";
	cout << "Original String\n";
	cout << S1 << endl;

	string PauncuationsRemoved = stringWTpun(S1);
	cout << "\n\nPauncuations Removed\n";
	cout << PauncuationsRemoved << endl;


	system("pause>0");
	return 0;
}