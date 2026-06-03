#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct stClient 
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double NumberBalance;

};

vector<string> vStringRecord(string S , string Seperator = "#//#")
{
vector<string> vRecord;
short pos = 0;
string sWord = "";

while((pos = S.find(Seperator)) != std::string::npos)//"A150#//#1234#//#Mahmoud El desoky#//#078362#//#5380.000000"
{
	sWord = S.substr(0 , pos);

	if(sWord != " ")
	{
		vRecord.push_back(sWord);
	}
	S.erase(0 , pos + Seperator.length());
}

if(S != " ")
{
	vRecord.push_back(S);
}

return vRecord;
}

stClient ReadClientRecord(vector<string> vString)
{
	stClient Client;

	Client.AccountNumber = vString.at(0);
	Client.PinCode = vString.at(1);
	Client.Name = vString.at(2);
	Client.Phone = vString.at(3);
	Client.NumberBalance = stod(vString.at(4));// Cast String to Double
	//stod = string to double

	
	return Client;
}

void printClientRecord(stClient Client)
{
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code  : " << Client.PinCode;
	cout << "\nName	 : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountNumber;
}

int main()
{

	string LineRecord = "A150#//#1234#//#Mahmoud El desoky#//#078362#//#5380.000000";

	cout << "\nLine Record is\n";
	cout << LineRecord << "\n\n";

	vector<string> vRecord = vStringRecord(LineRecord);
	stClient Client = ReadClientRecord(vRecord);

	cout << "The following is the Extracted client record: " << endl;
	printClientRecord(Client);

	system("pause>0");
	return 0;
}