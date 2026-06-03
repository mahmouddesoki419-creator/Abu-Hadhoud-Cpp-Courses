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

vector<string> SplitString(string sLine , string Delim)
{
	vector<string> vClientRecord;
	short pos = 0;
	string sWord = "";

	while((pos = sLine.find(Delim)) != std::string::npos)//B709#//#1234#//#ahmed maher#//#012928434#//#12000
	{
		sWord = sLine.substr(0 , pos);
		if(sWord != "")
		{
			vClientRecord.push_back(sWord);
		} 
		sLine.erase(0  , pos + Delim.length());
	}

	if(sLine != "")
	{
		vClientRecord.push_back(sLine);
	}

	return vClientRecord;
}

sClient ConvertLineToRecord(string Line , string Separator = "#//#")
{
	sClient Client;
	vector<string> vClientData;

	vClientData = SplitString(Line , Separator);

	if(vClientData.size() >= 5)
	{
		Client.AccoundNumber = vClientData.at(0);
		Client.PinCode = vClientData.at(1);
		Client.ClientName = vClientData.at(2);
		Client.Phone = vClientData.at(3);
		Client.Balance = stod(vClientData.at(4));
	}
	else 
	{
		cout <<"Warning: Skipping invalid line: " << Line << endl;
	}
	return Client;
}

vector<sClient> LoadClientsDataFromFile(string FileName)
{
	vector<sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName , ios::in);

	if(MyFile.is_open())
	{
		string line;
		sClient Client;

		while(getline(MyFile , line ))
		{
			Client = ConvertLineToRecord(line);// هنا بنجز اللاين ل ستراكشرز 
			vClients.push_back(Client);// هنا بنضيف الستراكشرز بتاعت كل لاين = ستراكشر واحد // الي فيكتور يجمع سطور الفايل  
		}

		MyFile.close();
	}

	return vClients;

}

void PrintRecordClient(sClient Client)
{
	cout << "| " << left << setw(15) << Client.AccoundNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.ClientName;
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(12) << Client.Balance;
}

void PrintAllClientsData(vector<sClient> vClient)
{
	cout << "\n\t\t\t\t\tList Client (" << vClient.size() << ") Clisnt(s).";

	cout << endl << left << setfill('_') << setw(100) << "_" << endl << setfill(' ');
	
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";

	cout << endl << left << setfill('_') << setw(100) << "_" << endl << setfill(' ');

	for(sClient Client : vClient)
	{
		PrintRecordClient(Client);
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