#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string EnterString()
{
	string input = ""; 

	cout << "Please Enter Your String ?" << endl;
	getline(cin , input);

	return input;
}

string FirstLetters(string Input)//mahmoud eldesoki ali donia
{
	bool IsFisrtLetter = true; 
	
	//Mahmoud Eldesoki Ali Donia
	for(short i = 0; i < Input.length(); i++)
	{
		if(Input[i] != ' ' && IsFisrtLetter) 
		{
			Input[i] = toupper(Input[i]); // بتحول الحرف ل كابيتال
		}
		
		IsFisrtLetter = (Input[i] == ' ' ?  true : false);// هنا بنسئل لو فراغ  ايبقي ترو عشان نكبر حرف البعدو 
	}
	return Input;
}

int main()
{	

	string S1 = EnterString();

	cout << "\nstirng after conversion:" << endl;
	S1 = FirstLetters(S1);
	cout << S1 << endl;

	return 0;
}
