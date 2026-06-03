#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string readPassword()
{
	string pass = "";
	cout << "Enter a new password: " << endl;
	getline(cin , pass);	
	return pass;
}

int upperCase(string pss)
{
	int count = 0;
	for(int i = 0; i < pss.length(); i++)
	{
		if(isupper(pss[i]))
		{
			count++;
		}
	}
return count;
}

int lowerCase(string pss)
{
	int count = 0;
	for(int i = 0; i < pss.length(); i++)
	{
		if(islower(pss[i]))
		{
			count ++;
		}
	}
return count;	
}

int DigitCase(string pss)
{
	int count = 0;
	for(int i = 0; i < pss.length(); i++)
	{
		if(isdigit(pss[i]))
		{
			count ++;
		}
	}
return count;
}

int punctuation(string pss)
{
	int count  = 0;
	for(int i = 0; i < pss.length(); i++)
	{
		if(ispunct(pss[i]))
		{
			count ++;
		}
	}
return count;	
}

void CheakPassStrongOrNot(string pass)
{
	if(pass.length() > 8 && upperCase(pass) > 0
	&& lowerCase(pass) > 0 && DigitCase(pass) > 0 && punctuation(pass) > 0)
	{
		cout << "Storng password" << endl;
	}
	else 
		cout << "Weak Password" << endl;
}

int main()
{
	string pass = readPassword();

	CheakPassStrongOrNot(pass);

	return 0;
}

