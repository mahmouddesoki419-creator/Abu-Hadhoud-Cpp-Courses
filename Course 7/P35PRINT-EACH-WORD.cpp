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

void PrintEachWord(string S1)
{
	string delim = " ";

	cout << "\nYour string Words Are: " << endl;
	short pos = 0;
	string sWord;// define a string variable

	//use find() function to get the position of the delimiters
	while ((pos = S1.find(delim)) != std::string::npos)//npos here return -1 false 
	{// يعني لو ملقتش مسافه فراغ مش ايعمل الشرط 
		sWord = S1.substr(0 , pos); // store the word
		if(sWord != "")
		{
			cout << sWord << endl;
		}

		S1.erase(0 , pos + delim.length());//earse() until positon and move to next word
	}

	if (S1 != "")
	{
		cout << S1 << endl; // it print last word of the string
	}
}

int main()
{
	
	PrintEachWord(ReadString());

	string name  = "mahmoud eldesoki ali donia ";
	cout << "\n" <<name.substr(0 , 7) << endl;//this fuction  print from 0 & to 7
	cout << "\n" << name.find("h") << endl;//return 2
	cout << "\n" << name.erase(0 , 8) << endl;//return "eldesoki ali donia" 


	system("pause>0");
	return 0;
}
