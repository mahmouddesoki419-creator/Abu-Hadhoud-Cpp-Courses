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

vector<string> SplitString(string S1 , string Delim)//mahmoud eldesoki ali donia
{
	vector<string> vString;

	short pos = 0;
	string sWord;

	/* erase() until positon and move to next word. */
	while((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0 , pos);

		if(sWord != " ")
		{
			vString.push_back(sWord);
		}

		S1.erase(0 , pos + Delim.length());
		/* erase() until
		positon and move to next word. */
	}

	if(S1 != " ")
	{
		vString.push_back(S1);
	}

	return vString;
}

string ReversingString(string S1)
{
	vector<string> vString;
	string S2 = "";
	vString = SplitString(S1 , " ");

	//declare iterator 
	vector<string>::iterator iter = vString.end();

	while(iter != vString.begin())//mahmoud eldesoki ali donia
	{
		//--iter;
		S2 += *(--iter) + " "; // هنا انقص من القيمه الحاليه ثم انضيفها 
	}// لو كانت -- بعد ايتير اتبقي مشكله وغلط عشان اتعمل اضافه للقيمه ثم نقص 

	S2 = S2.substr(0 , S2.length() - 1); // delete last element is " " 

	return S2;
}

int main()
{
	string S1 = ReadString();
	cout << "\n\nString after reversing words: ";
	cout << "\n" << ReversingString(S1);

	system("pause>0");
	return 0;
}