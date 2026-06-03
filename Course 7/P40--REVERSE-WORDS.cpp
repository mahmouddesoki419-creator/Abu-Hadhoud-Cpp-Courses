#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string ReadString()
{
	string S = "";

	cout << "Please Enter Your String ? " << endl;
	getline(cin, S);

	return S;
}

string trimRight(string s1)
{

	for (short i = s1.length() - 1; i >= 0; i--)
	{

		if (s1[i] != ' ')
		{
			return s1.substr(0, i + 1);
		}
	}
	return "";
}

string trimLeft(string s1)
{
	for(short i = 0; i < s1.length(); i++)
	{
		if(s1[i] != ' ')
		{
			return s1.substr(i , s1.length() - i);
		}
	}
	return s1;
}

string trim(string s1)
{
	return trimLeft(trimRight(s1));
}

string ReversingString(string S)
{
	string RevS = "";
	for (short i = S.length() - 1; i >= 0; i--) //ali maher ahmed//
	{
		if (S[i] == ' ')
		{
			RevS += S.substr(i + 1) + " ";

			S = S.erase(i);
		}
	}

	RevS += S;

	return trim(RevS);
}

int main()
{
	string S = ReadString();
	cout << "String after reversing words: " << endl;
	cout << ReversingString(S);

	system("pause>0");
	return 0;
}