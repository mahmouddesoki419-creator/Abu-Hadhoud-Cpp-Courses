#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string trimLeft(string S1)// مسح ال علي شمال
{
	for(short i = 0; i < S1.length(); i++)
	{
		if(S1[i] != ' ')
		{
			return S1.substr(i , S1.length() - i);//" Mahmoud El "// يبقي داله دي بتاخر من 0 و عدد حروف البراميتر تاني
		}//s.substr(start_index, number_of_characters) parameters this function mean <=
	}
	return "";
}

string trimRight(string S1)
{
	for(short i = S1.length() - 1; i >= 0; i--)
	{
		if(S1[i] != ' ')
		{
			return S1.substr(0 , i + 1); //" Mahmoud El "
		}
	}
	return "";
}

string trim(string S1)
{
	return trimLeft(trimRight(S1));
}

int main()
{
	string S1 = "  Mahmoud Eldesoki  ";
	cout << "String   = " << S1 << endl;
	cout << S1.length() << endl;

	cout << "\nTrim Left = " << trimLeft(S1) << endl;
	cout << trimLeft(S1).length() << endl;

	cout << "\nTrim Right = " << trimRight(S1) << endl;
	cout << trimRight(S1).length() << endl;
	
	cout << "\nTrim = " << trim(S1) << endl;
	cout << trim(S1).length() << endl;

	system("pause>0");
	return 0;
}