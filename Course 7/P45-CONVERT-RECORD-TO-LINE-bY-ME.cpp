#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct stClientData 
{
	string AccountNumber;

	int pinCode;
	
	string Name;
	
	string PhoneNumber;
	
	int AccountBalance;

};

void ReadClientData(stClientData& ClientData)
{
	cout << "Enter Account Number? ";
	getline(cin , ClientData.AccountNumber);

	cout << "Enter PinCode ? ";
	cin >> ClientData.pinCode;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter Name ? ";
	getline(cin , ClientData.Name);

	cout << "Enter Phone ? ";
	getline(cin , ClientData.PhoneNumber);// هنا مش محتاج ignore خالص! لأن getline هي أصلاً بتمسح الـ Enter بتاعها وهي ماشية.

	cout << "Enter AccountBallance ? ";
	cin >> ClientData.AccountBalance;
}

vector<string> ClientRecord(stClientData ClientData)
{
	vector<string> vClientData;

	vClientData.push_back(ClientData.AccountNumber);
	vClientData.push_back(to_string(ClientData.pinCode));
	vClientData.push_back(ClientData.Name);
	vClientData.push_back(ClientData.PhoneNumber);
	vClientData.push_back(to_string(ClientData.AccountBalance));

	return vClientData;
}

string JoinString(vector<string> vClient , string Delim)
{
	string S1 = "";

	for(const string& Data : vClient)
	{
		S1 += Data + Delim;
	}

	return S1.substr(0 , S1.length() - Delim.length());
}

int main()
{
	stClientData ClientData;

	cout << "\nPlease Enter Client Data\n\n";
	ReadClientData(ClientData);

	vector<string>vClient1 = ClientRecord(ClientData);

	cout << "\n\nClient Record for Saving is:\n";
	cout << JoinString(vClient1 , " #//# ") << endl;

	system("pause>0");
	return 0;
}