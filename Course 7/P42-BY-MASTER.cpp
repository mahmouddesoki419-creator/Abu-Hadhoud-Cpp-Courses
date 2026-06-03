#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;


string ReplaceString(string S1, string StringToReplace , string ReplaceTo)
{
	short pos = S1.find(StringToReplace);

	while(pos != std::string::npos)//this mean not found if pos = 0 stop//الـ find بترجع npos في حالة واحدة فقط: لو الكلمة مش موجودة نهائياً في النص.
	{// nops mean=> not found anything
		S1 = S1.replace(pos , StringToReplace.length() , ReplaceTo);
		pos = S1.find(StringToReplace  , pos + ReplaceTo.length()); // find next //// ابدأ البحث من بعد المكان اللي خلصنا فيه تبديل
	}

	return S1;

}


int main()
{

	string S1 = "welcome to jorden , jorden is a nice country   jorden is wow country and beatiful jorden wow jorden";
	string StringToReplace = "jorden";
	string ReplaceTo = "USA";
	cout << "\nOrginal String\n" << S1;

	cout << "\n\nString After Replace";
	cout << "\n" << ReplaceString(S1, StringToReplace , ReplaceTo);

	system("pause>0");
	return 0;
}