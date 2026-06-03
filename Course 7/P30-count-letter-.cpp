#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string ReadString()
{
	string s1;

	cout << "Please enter your stirng ?" << endl;
	getline(cin , s1);
	return s1;
}

char ReadAchar()
{
	char Letter;

	cout << "\nPlease enter a Character ? " << endl;
	cin >> Letter;

	return Letter;
}

short CountLetterInString(string S1 , char Letter)
{
	short counter = 0;
	for(short i = 0; i < S1.length(); i++)
	{
		if(S1[i] == Letter)
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	string S1 = ReadString();
	char Letter = ReadAchar();

	cout << "Letter '" << Letter << "' Count = ";
	cout << CountLetterInString(S1 , Letter);

	system("pause>0");
	return 0;
}
