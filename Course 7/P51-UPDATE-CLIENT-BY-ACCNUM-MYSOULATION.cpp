#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits> // ضرورية لاستخدام numeric_limits

using namespace std;
string FileNameClients = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string ClientName;
	string Phone;
	double AccountBalance;

	bool MarkForDelete = false; // دي وحيده بنديها قيمه عشان لو عاوزين نحذف كلاينت من الفايل بنخليها ترو
};

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vClientRecord;

	short pos = 0;
	string sWord;

	while ((pos = S1.find(Delim)) != std::string::npos) // B709#//#1234#//#ahmed maher#//#012928434#//#12000.000000
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{

			vClientRecord.push_back(sWord);
		}

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vClientRecord.push_back(S1);
	}

	return vClientRecord;
}

sClient ConvertLineToRecord(string lineFile, string Separator = "#//#")
{
	sClient Client;

	vector<string> vClientData;
	vClientData = SplitString(lineFile, Separator);

	if (vClientData.size() >= 5)
	{
		Client.AccountNumber = vClientData.at(0);
		Client.PinCode = vClientData.at(1);
		Client.ClientName = vClientData.at(2);
		Client.Phone = vClientData.at(3);
		Client.AccountBalance = stod(vClientData.at(4));
	}
	else
	{
		cout << "Warning: Skipping Invalid Line: " << lineFile << endl;
	}

	return Client;
}

vector<sClient> LoadClientsDataFromFile(string FileName) // هنا بنفتح الفايل كل مره عشان نضيف السطور الي الفيكتور
{
	vector<sClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in); // read only

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}




string ConvertRecordToLine(sClient Client, string Separator = "#//#")
{
	string StrClient = "";

	StrClient += Client.AccountNumber + Separator;
	StrClient += Client.PinCode + Separator;
	StrClient += Client.ClientName + Separator;
	StrClient += Client.Phone + Separator;
	StrClient += to_string(Client.AccountBalance);

	return StrClient;
}

void printDataClient(sClient Client)
{
	cout << "\nThe following are the client details:\n";

	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code      : " << Client.PinCode;
	cout << "\nClientName    : " << Client.ClientName;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool ClientByAccNumber(string AccNum, vector<sClient> &vClients)
{
	sClient Client;

	for (sClient &C : vClients)
	{
		if (C.AccountNumber == AccNum)
		{
			printDataClient(C);
			return true;
		}
	}

	cout << "Client with Account Number (" << AccNum << ") Not Found!";
	return false;
}

sClient UpDateedClient(sClient &Client)
{
	cout << "\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter name ? ";
	getline(cin, Client.ClientName);

	cout << "Enter Phone ? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance ? ";
	cin >> Client.AccountBalance;
	cin.ignore();

	return Client;
}

void SaveClientsDataToFile(string FileName, vector<sClient> &vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		string Line;
		for (sClient &C : vClients)
		{
			if (C.MarkForDelete == false) // للتاكد من عدم كتابه العملاء المحذوفين مستقلا
			{
				Line = ConvertRecordToLine(C);
				MyFile << Line << endl;
			}
		}

		MyFile.close();
	}
}

bool UpdateClientByAccountNumber(string AccNum, vector<sClient> &vClients)
{
	char Answer = 'y';

	if (ClientByAccNumber(AccNum, vClients))
	{

		cout << "\n\nAre you sure you want Update this Client? y / n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient &C : vClients)
			{
				if (C.AccountNumber == AccNum)
				{
					C = UpDateedClient(C);

					SaveClientsDataToFile(FileNameClients, vClients);

					cout << "\n\nClient Updated Successfully.";
					return true;
				}
			}
		}
	}

	return false;
}

string ReadAccountNumber()
{
	string AccNum = "";

	cout << "Please enter AccountNumber ? ";
	cin >> AccNum;

	return AccNum;
}

int main()
{
	vector<sClient> vClientsRecords = LoadClientsDataFromFile(FileNameClients);
	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(AccountNumber, vClientsRecords);

	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
	cin.get();											 // بيستنى منك تضغط Enter عشان يقفل
	return 0;
}