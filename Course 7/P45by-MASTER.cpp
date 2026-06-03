#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct sClient 
{
	string AccountNumber;
	string pinCode;
	string Name;
	string PhoneNumber;
	int AccountBalance;
};

sClient ReadNewClient()
{
	sClient Client;
	cout << "Enter Account Number? ";
	getline(cin , Client.AccountNumber);

	cout << "Enter PinCode ? ";
	getline(cin , Client.pinCode);

	cout << "Enter Name ? ";
	getline(cin , Client.Name);

	cout << "Enter Phone ? ";
	getline(cin , Client.PhoneNumber);

	cout << "Enter AccountBallance ? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToline(sClient Client , string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.pinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.PhoneNumber + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

int main()
{
	cout << "\nPlease Enter Client Data\n\n";

	sClient Client;
	Client = ReadNewClient();


	cout << "\n\nClient Record for Saving is:\n";
	cout << ConvertRecordToline(Client);

	system("pause>0");
	return 0;
}