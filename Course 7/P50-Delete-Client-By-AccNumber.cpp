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
	bool MarkForDelete = false;



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

sClient ConvertLineToRecord(string Line, string Separator = "#//#")// fill a structure
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
		cout << "Warning: Skipping invalid line: " << Line << endl;// تخطي السطر غير صالح
	}
	return Client;
}

string ConvertRecordToline(sClient Client , string Separator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccoundNumber + Separator;
	stClientRecord += Client.PinCode + Separator;
	stClientRecord += Client.ClientName + Separator;
	stClientRecord += Client.Phone + Separator;
	stClientRecord += to_string(Client.Balance);

	return stClientRecord;
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
			Client = ConvertLineToRecord(line); // هنا بنجر اللاين ل ستراكشرز
			vClients.push_back(Client);			// هنا بنضيف الستراكشرز بتاعت كل لاين = ستراكشر واحد // الي فيكتور يجمع سطور الفايل
		}

		MyFile.close();
	}

	return vClients;
}

void PrintClientCard(sClient dataClient)
{
	cout << "\nThe Following are the Client details:\n";
	cout << "Account Number: " << dataClient.AccoundNumber << endl;
	cout << "PinCode: " << dataClient.PinCode << endl;
	cout << "ClientName: " << dataClient.ClientName << endl;
	cout << "Phone: " << dataClient.Phone << endl;
	cout << "Balance: " << dataClient.Balance << endl;
}

bool FindClientByAccountNumber(string AccountNumber , vector<sClient> vClient , sClient &Client)
{

	for(sClient C : vClient)
	{
		if(C.AccoundNumber == AccountNumber)
		{
			Client = C;// client  == لاين الكلاينت 1 و 2 و 3  بتاع الملف 
			return true;
		}
	}

	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccNumber , vector<sClient>& vClient)
{
	for(sClient& C : vClient)
	{
		if(C.AccoundNumber == AccNumber)
		{
			C.MarkForDelete = true;
			return true; 
		}
	}

	return false;
}

vector<sClient> SaveClientsDataToFile(string FileName , vector<sClient> vClient )
{

fstream MyFile;
MyFile.open(FileName , ios::out);//OverWrite

string DataLine;

if(MyFile.is_open())
{

	for(sClient C : vClient)
	{
		if(C.MarkForDelete == false)
		{//we only write records that are not marked to delete.
			DataLine = ConvertRecordToline(C);  

			MyFile << DataLine << endl;
		}
	}

	MyFile.close();
}

return vClient;
}

bool DeleteClientByAccountNumber(string AccNumber , vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if(FindClientByAccountNumber(AccNumber , vClients , Client))// لو لقينا لرقم ايدي true
	{
		PrintClientCard(Client);// ف ايطبع الستراكشر 

		cout << "\n\nAre you Sure do you want delete this Client? y/n ?";
		cin >>Answer;
		if(Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccNumber , vClients);
			SaveClientsDataToFile(ClientsFileName , vClients);

			//refersh Clients 
			vClients = LoadClientsDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}

	return false;
}

string ReadClientAccountNumber()
{
	string AccNumber = "";

	cout << "Please Enter AccountNumber ? ";
	cin >> AccNumber;
	return AccNumber;
}

int main()
{
	vector<sClient> vClient = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();


	DeleteClientByAccountNumber(AccountNumber , vClient);




	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
	cin.get();											 // بيستنى منك تضغط Enter عشان يقفل
	return 0;
}