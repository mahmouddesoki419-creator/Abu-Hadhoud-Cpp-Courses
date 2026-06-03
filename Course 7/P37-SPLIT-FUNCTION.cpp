#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string ReadString()
{
	string S1 = "";

	cout << "Please Enter Your String ? " << endl;
	getline(cin, S1);

	return S1;
}

vector<string> SplitString(string S1, string delim)
{
	short pos = 0;
	string sWord;

	vector<string> vString;

//use find() function to get the position of the delimiters
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);//store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

int main()
{
	vector<string> vString;

	vString = SplitString(ReadString(), " ");

	cout << "Tokens = " << vString.size() << endl;
	for(string &i : vString)
	{
		cout << i << endl;
	}

	system("pause>0");
	return 0;
}