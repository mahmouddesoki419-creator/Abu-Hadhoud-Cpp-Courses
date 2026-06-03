#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string ReadString()
{
	string S1 = "";

	cout << "Please Enter Your String ? " << endl;
	getline(cin , S1);

	return S1;
}

bool IsVowelLetter(char letter) // دي فاكشن بتمسك الحرف بتقارن هل هو بياوي اي حرف من الفاولز 
{
	letter = toupper(letter); 
	return ((letter == 'A') || (letter == 'E') || (letter == 'I') || (letter == 'O') || (letter == 'U'));
}

void PrintvowelsLetters(string S1)
{
	cout << "\nVowels in string are: ";
	for(short i = 0; i < S1.length(); i++)
	{
		if(IsVowelLetter(S1[i]))
		{
			cout << S1[i] << "   ";
		}
	}
}

int main()
{
	string S1 = ReadString();
	PrintvowelsLetters(S1);

	system("pause>0");
	return 0;
}
