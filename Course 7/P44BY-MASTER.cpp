#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string RemovePuncuationFromString(string S1)
{
	string Result = "";
	for(int i = 0; i < S1.length(); i++) //Welcome to Jorden , Jorden is a nice Country ; it's amazing."
	{
		if(!ispunct(S1[i]))//  لو الحرف لا يساوي بانكويشن امسحو من السترينج
		{

		Result += S1[i];

		}
	}
	
	return Result;
}

int main()
{

	string S1 = "Welcome ''.to,. Jorden , Jord./en is a nice Country ; it's amazing.";
	cout << "Original String \n" << S1;

	cout << "\n\nPauncuations Removed\n" << RemovePuncuationFromString(S1);


	system("pause>0");
	return 0;
}