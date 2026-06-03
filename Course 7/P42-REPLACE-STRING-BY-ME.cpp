#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

/*/string readString()
{
	string s = "";
	cout << "Enter your string ? " << endl;
	getline(cin , s);
	return s;
}/*/

string ReplaceString(string S1, string Delim)
{
	short pos = 0;
	string sWord = "";
	string word = "USA";
	string OrgWord = "jorden";
	while ((pos = S1.find(Delim)) != std::string::npos) // welcome to jordan , jordan is a nice country
	{
		if (S1.substr(0, pos) == OrgWord)
		{
			sWord += word + " ";
			S1.erase(0, pos + Delim.length());
		}
		else
		{
			sWord += S1.substr(0, pos) + " ";
			S1.erase(0, pos + Delim.length());
		}
	}

	if (S1 != " " && S1 != OrgWord)
	{
		sWord += S1;
	}
	else
	{
		sWord += word;
	}

	return sWord;
}

/*/string ReplaceString(string S1)
{
	string wordReplace = "";

	vector<string> vS1 = SplitString(S1 , " ");

	while((pos))

}/*/

int main()
{

	string S1 = "welcome to jorden , jorden is a nice country   jorden is wow country and betiful jorden wow jorden";
	cout << "\nString Orginal\n";
	cout << S1 << endl;

	cout << "\n\nString After Replace\n";
	cout << ReplaceString(S1, " ");

	system("pause>0");
	return 0;
}