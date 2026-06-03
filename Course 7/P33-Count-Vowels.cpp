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

bool IsVowelLetter(char letter) // دي فاكشن بتمسك الحرف بتقارن هل هو بيساوي اي حرف من الفاولز 
{
	letter = toupper(letter); 
	return ((letter == 'A') || (letter == 'E') || (letter == 'I') || (letter == 'O') || (letter == 'U'));
}

short CountVowels(string S1)
{
	short Counter = 0;
	for(short i = 0; i < S1.length(); i++)
	{
		if(IsVowelLetter(S1[i])) // send letter to check vowel or not is true  counter++
		{
				Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\nNumber of Vowels is: " << CountVowels(S1) << endl;

	system("pause>0");
	return 0;
}
