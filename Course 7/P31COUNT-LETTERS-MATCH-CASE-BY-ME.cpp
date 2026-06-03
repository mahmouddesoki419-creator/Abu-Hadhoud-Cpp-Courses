#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string ReadString()
{
	string s1;

	cout << "Please enter your stirng ?" << endl;
	getline(cin, s1);
	return s1;
}

char ReadAchar()
{
	char Letter;

	cout << "\nPlease enter a Character ? " << endl;
	cin >> Letter;

	return Letter;
}

short CountLetterInString(string S1, char Letter)
{
	short counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Letter)
		{
			counter++;
		}
	}
	return counter;
}

char InvertLetterCase(char Ch1)
{

	char Ch2Inverting = (islower(Ch1) ? toupper(Ch1) : tolower(Ch1));
	return Ch2Inverting;
}

short CountCapAndSmallLetter(string S1, char Letter)
{
	short Counter = 0;
	char Ch2 = InvertLetterCase(Letter);

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Ch2)
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();
	char Letter = ReadAchar();
	short CountLetter = (CountLetterInString(S1 , Letter));
	cout << "Letter '" << Letter << "' Count = ";
	cout <<CountLetter;

	char Ch2Inverting = InvertLetterCase(Letter);
	short CountCandSchar = CountCapAndSmallLetter(S1 , Letter);
	cout << "\nLetter '" << Letter << "' Or '" << Ch2Inverting<< "' Count = ";
	cout << CountCandSchar + CountLetter;




	system("pause>0");
	return 0;
}
