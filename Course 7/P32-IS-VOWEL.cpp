#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

char ReadAchar()
{
	char Letter;

	cout << "\nPlease enter a Character ? " << endl;
	cin >> Letter;

	return Letter;
}

bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1); // انحوله ل سمال 
	return (Ch1 == 'a' || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u')); //   هنا ايرجع ترو او فالس  بعد م يمشي علي كل احتمال ويقارن 
}
 
int main()
{

	char Ch1 = ReadAchar();

	if(IsVowel(Ch1))// لو ترو
	{
		cout << "\nYes Letter '" << Ch1 << "' is Vowel." << endl;
	}
	else
		cout << "\nNo Letter '" << Ch1 << "' Isn't Vowel." << endl;


	system("pause>0");
	return 0;
}
