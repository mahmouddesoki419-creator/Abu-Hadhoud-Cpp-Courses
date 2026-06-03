#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string ReadString()
{
	string s1;

	cout << "Please enter a stirng ?" << endl;
	getline(cin , s1);
	return s1;
}

enum enWhatToCount{ SmallLetters = 0 , CapitalLetters = 1 , All = 3};
// ده generic function 
short CountLetters(string S1 , enWhatToCount WhatToCount = enWhatToCount::All) // here is default paprameter for enum = all
{

	if(WhatToCount == enWhatToCount::All) // تحت في ال طباعه عدد حروف السترينج كلها بعتنا فقط لتسرينج 
	{
		return S1.length();
	}


	short Counter = 0;
	for(int i = 0; i < S1.length(); i++)
	{
		if(WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i])) // في الحاله دي بعتنا بارميتر بيساوي كابيتال
		{
			Counter++;
		}

		if(WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))// حاله دي بعتنا بارميتر بيساوي سمال
		{
			Counter++;
		}
	}
	return Counter; // انرجع  العدد الكاونتر ال في حاله الكابيتال فقط او سمال فقط 
}



// او الحل ده ب الاتين فاكشنز الكونتر واحد  لعد الكابيتل و التاني سمال
int CountCapitalLetters(string S1)
{
	short Counter = 0;
	for(short i = 0; i < S1.length(); i++)
	{
		if( isupper(S1[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int CountSmallLetters(string S1)
{
	short Counter = 0;
	for(short i = 0; i < S1.length(); i++)
	{
		if(islower(S1[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string s1 = ReadString();

	cout << "\nString length = " << CountLetters(s1) << endl;
	cout << "Capital Letters Count = " << CountLetters(s1 , enWhatToCount::CapitalLetters) << endl;
	cout << "Small Letters Count = " << CountLetters(s1 , enWhatToCount::SmallLetters) << endl;

	cout << "\n\nMethod 2\n";

	cout << "\n\nString length = " << s1.length() << endl;
	cout << "Capital Letters Count = " << CountCapitalLetters(s1) << endl;
	cout << "Small Letters Count = " << CountSmallLetters(s1) << endl;


	system("pause>0");
	return 0;
}
