#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits> // ضرورية لاستخدام numeric_limits

using namespace std;
const string ClientsFileName = "Clients.txt";

struct sClient
{
	string AccoundNumber;
	string PinCode;
	string ClientName;
	string Phone;
	double Balance;
};

vector<string> SplitString(string sLine, string Delim)
{
	vector<string> vClientRecord;
	short pos = 0;
	string sWord = "";

	while ((pos = sLine.find(Delim)) != std::string::npos) // B709#//#1234#//#ahmed maher#//#012928434#//#12000
	{
		sWord = sLine.substr(0, pos);
		if (sWord != "")
		{
			vClientRecord.push_back(sWord);
		}
		sLine.erase(0, pos + Delim.length());
	}

	if (sLine != "")
	{
		vClientRecord.push_back(sLine);
	}

	return vClientRecord;
}

sClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
	sClient Client;
	vector<string> vClientData;

	vClientData = SplitString(Line, Separator);

	if (vClientData.size() >= 5)
	{
		Client.AccoundNumber = vClientData.at(0);
		Client.PinCode = vClientData.at(1);
		Client.ClientName = vClientData.at(2);
		Client.Phone = vClientData.at(3);
		Client.Balance = stod(vClientData.at(4));
	}
	else
	{
		cout << "Warning: Skipping invalid line: " << Line << endl;
	}
	return Client;
}

vector<sClient> LoadClientsDataFromFile(string FileName)
{
	vector<sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string line;
		sClient Client;

		while (getline(MyFile, line))
		{
			Client = ConvertLineToRecord(line); // هنا بنجز اللاين ل ستراكشرز
			vClients.push_back(Client);			// هنا بنضيف الستراكشرز بتاعت كل لاين = ستراكشر واحد // الي فيكتور يجمع سطور الفايل
		}

		MyFile.close();
	}

	return vClients;
}

void PrintDataClient(sClient dataClient)
{
	cout << "Account Number: " << dataClient.AccoundNumber << endl;
	cout << "PinCode: " << dataClient.PinCode << endl;
	cout << "ClientName: " << dataClient.ClientName << endl;
	cout << "Phone: " << dataClient.Phone << endl;
	cout << "Balance: " << dataClient.Balance << endl;
}

void AskAccountNumber(vector<sClient> DataClient)
{
	string AccNumber = "";

	cout << "Please Enter AccountNumber? ";
	getline(cin >> ws, AccNumber);

	for (const sClient &Client : DataClient)
	{
		if (Client.AccoundNumber == AccNumber)
		{
			cout << "\nThe Following are the Client details:\n\n";
			PrintDataClient(Client);
			return;
		}
	}

	cout << "Client with Account Number (" + AccNumber + ") Not Found!" << endl;
}

int main()
{
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	AskAccountNumber(vClients);

	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
	cin.get();											 // بيستنى منك تضغط Enter عشان يقفل
	return 0;
}