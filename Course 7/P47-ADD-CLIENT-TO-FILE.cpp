+#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

const string fileClients = "Clients.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double NumberBalance;
};

stClient ReadClientRecord()
{
	stClient Client;

	cout << "Enter Account Number: ";
	getline(cin >> ws, Client.AccountNumber);
	cout << "Enter PinCode ? ";
	getline(cin, Client.PinCode);
	cout << "Enter Name ? ";
	getline(cin, Client.Name);
	cout << "Enter Phone: ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance ? ";
	cin >> Client.NumberBalance;

	return Client;
}

string ConvertRecordToLine(stClient Client, string Delim = " && ")
{
	string S1 = "";

	S1 += Client.AccountNumber + Delim;
	S1 += Client.PinCode + Delim;
	S1 += Client.Name + Delim;
	S1 += Client.Phone + Delim;
	S1 += to_string(Client.NumberBalance);

	/*/دقة الأرقام: في فنكشن ConvertRecordToLine أنت بتستخدم
	to_string(Client.NumberBalance). دي ساعات بتطلع أصفار كتير ملهاش لزمة (مثلاً 500.000000).
	 لو عايز الرقم يطلع زي ما دخلته بالظبط، ممكن تستخدم stringstream.*/

	return S1;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
}

void AddNewClient()
{
	stClient Client;
	Client = ReadClientRecord();
	AddDataLineToFile(fileClients, ConvertRecordToLine(Client));
}

void AddClients()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "\nAdding New Client:\n\n";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N ?";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

int main()
{
	AddClients();





	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
	cin.get();											 // بيستنى منك تضغط Enter عشان يقفل
	return 0;
}