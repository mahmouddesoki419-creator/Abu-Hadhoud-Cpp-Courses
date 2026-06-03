#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string ReadString()
{
	string s1;

	cout << "Please enter a stirng ?" << endl;
	getline(cin , s1);
	return s1;
}

char InvertLetterCase(char C1) // this function to invert letters in string
{
return islower(C1) ? toupper(C1) : tolower(C1); 
}

string InvertAllStringLettersCase(string s1) // this function return string after inverting
{
	for(short i = 0; i < s1.length(); i++)
	{
		s1[i] = InvertLetterCase(s1[i]);
	}
	return s1;
}

int main()
{
	string s1 = ReadString();

	s1 = InvertAllStringLettersCase(s1);
	cout << "\n\nString after inverting All Latters Case:" << endl;
	cout << s1 << endl;

	system("pause>0");
	return 0;
}
