#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string ReadString()
{
	string s1;

	cout << "Please enter your stirng ?" << endl;
	getline(cin, s1);
	return s1;
}

char ReadAchar()
{
	char Letter;

	cout << "\nPlease enter a Character ? " << endl;
	cin >> Letter;

	return Letter;
}

char InvertLetterCase(char Letter)
{
	return (isupper(Letter) ? tolower(Letter) : toupper(Letter));
}


short CountLetter(string S1 ,char Letter , bool MatchCase = true)// هنا البوليان باي ديفولت قيمه افرتاضيه لترو 
{
	short Counter = 0; 

	for(short i = 0; i < S1.length(); i++)
	{
		if(MatchCase)// طالما بول ترو ايبقي ايعد الحرف بالسترينج بحاله مطابقه للحرف ب ليتر كابيتال فقط او سمال فقط
		{
			if(S1[i] == Letter)
			{
				Counter++;
			}
		}
		else //bool match case = false;
			if(tolower(S1[i]) == tolower(Letter))// هنا بنجذم انه يحول كل الحفين ولو بيساوي بعض ايعدو 
			{
				Counter++;
			}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();
	char Letter = ReadAchar();

	cout << "\nLetter '" << Letter << "' Count = " << CountLetter(S1 , Letter) << endl;

	cout << "\nLetter '" << Letter << "' Or '" << InvertLetterCase(Letter) << "' Count = " << 
	CountLetter(S1 , Letter , false); // هنا لازم نبعت flase عشان يحول الحرفبن لنفس الوزن ويعد لو زيه 

	system("pause>0");
	return 0;
}
