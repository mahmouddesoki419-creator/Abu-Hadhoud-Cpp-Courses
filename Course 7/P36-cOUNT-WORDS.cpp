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


short CountWords(string S1)//ali maher Dawoud
{
	string delim = " ";
	string sWord;
	short pos = 0;
	short Counter = 0;

	while((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0 , pos);
		if(sWord != "")
		{
			Counter++;
		}
		
		S1 = S1.erase(0 , pos + delim.length());
	}

	if(sWord != "")
	Counter++;

	return Counter;
}

int main()
{

	string S1 = ReadString();
	cout << "\nThe Number of words in your string is: " << CountWords(S1) << endl;


	system("pause>0");
	return 0;
}