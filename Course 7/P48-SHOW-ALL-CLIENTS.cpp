#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>// ضرورية لاستخدام numeric_limits

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

vector<string> SplitString(string s , string Delim)
{
	vector<string> vRecordClients;
	short pos = 0;
	string sWord;


	while((pos = s.find(Delim)) != std::string::npos)
	{
		sWord = s.substr(0 , pos);

		if(sWord != "")
		{
			vRecordClients.push_back(sWord);
			
		}
		s.erase(0 , pos + Delim.length());
	}

	if(s != "")
	{
		vRecordClients.push_back(s);
	}

	return vRecordClients;
}

sClient ConvertLineToRecord(string line , string separator = "#//#")
{
	sClient Client;
	vector<string> vClientData;
	
	vClientData = SplitString(line , separator);

	if (vClientData.size() >= 5)
	{
		Client.AccoundNumber = vClientData.at(0);
		Client.PinCode = vClientData.at(1);
		Client.ClientName = vClientData.at(2);
		Client.Phone = vClientData.at(3);
		Client.Balance = stod(vClientData.at(4));//cast string
	}
	else 
	{
		cout << "Warning: Skipping invalid line: " << line << endl;
	}

	 return Client;
}

vector<sClient> LoadClientsDataFromFile(string FileName )
{
	vector<sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName , ios::in);//Read mode

	if(MyFile.is_open())
	{
		string line;
		sClient Client;

		while(getline(MyFile , line))
		{

			if(line != "")
		{
			Client = ConvertLineToRecord(line);
			vClients.push_back(Client);
		}

		}

		MyFile.close();
	}
	return vClients;
}

void PrintClientRecord(sClient Client)
{
	cout << "| " << left << setw(15) << Client.AccoundNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.ClientName;
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(12) << Client.Balance;
}

void PrintAllClientsData(vector<sClient> vecClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vecClients.size() << ") Client(s).";
	
	cout << endl << left << setfill('_') << setw(100) << "_" << endl << setfill(' ');

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	
	cout << endl << left << setfill('_') << setw(100) << "_" << endl << setfill(' ');

	for(sClient Client : vecClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout << left << setfill('_') << setw(100) << "_" << endl << setfill(' ');
}

int main()
{
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	PrintAllClientsData(vClients);


	




	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
	cin.get();											 // بيستنى منك تضغط Enter عشان يقفل
	return 0;
}