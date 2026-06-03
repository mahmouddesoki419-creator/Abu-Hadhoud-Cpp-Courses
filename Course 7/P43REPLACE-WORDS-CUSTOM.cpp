#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

vector<string> SplitString(string S1 , string Delim)
{
	
vector<string> vString;

short pos = 0;
string sWord = "";

while((pos = S1.find(Delim)) != std::string::npos)//Welcome to Jorden , Jorden is a nice Country
{
	sWord = S1.substr(0 , pos);

	if(sWord != " ")
	{
		vString.push_back(sWord);
	}

	S1.erase(0 , pos + Delim.length());
}

if(S1 != "")
{
	vString.push_back(S1);
}

return vString;
}

string LowerAllString(string S)
{
	for(short i = 0; i < S.length(); i++)
	{
		S[i] = tolower(S[i]);
	}

return S;
}

string joinString(vector<string> vString , string Delim)
{
string s1 = "";

for(string& word : vString)
{
	s1 += word + " ";
}

return s1.substr(0 , s1.length() - Delim.length());

}

string ReplaceStirngWithCaseMatch(string S1 , string wordToReplace , string ToReplace , bool matchCase = true)
{
	vector<string> vString = SplitString(S1 , " ");

	for(string& word : vString)
	{
		if(matchCase) // حاله تطابق الحروف
		{

		if(word == wordToReplace)
		{
			word = ToReplace;
		}

		}
		else 
		{
		if(LowerAllString(word) == LowerAllString(wordToReplace))
		word = ToReplace;
		}

	}


	return joinString(vString , " ");
}

int main()
{

	string S1 = "Welcome to Jorden , Jorden is a nice Country";
	cout << "Orginal String\n"; 	
	cout << S1 << endl;

	string StringToReplace = "jorden";
	string ToReplace = "USA";

	string RCaseMatch = ReplaceStirngWithCaseMatch (S1 , StringToReplace , ToReplace);
	cout << "\n\nReplace with match case\n";
	cout << RCaseMatch << endl;


	string R_dontMatchCace = ReplaceStirngWithCaseMatch(S1 , StringToReplace , ToReplace , false);
	cout << "\n\nReplace With Dont Match Case\n";
	cout << R_dontMatchCace << endl;
	

	system("pause>0");
	return 0;
}