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

bool MarkForDelete = false;// دي وحيده بنديها قيمه عشان لو عاوزين نحذف كلاينت من الفايل بنخليها ترو

};

vector<string> SplitString(string S1 , string Delim)
{
	vector<string> vClientRecord;

	short pos = 0;
	string sWord;

	while((pos = S1.find(Delim)) != std::string::npos)//B709#//#1234#//#ahmed maher#//#012928434#//#12000.000000
	{
		sWord = S1.substr(0 , pos);
		
		if(sWord != "")
		{

			vClientRecord.push_back(sWord);

		}

		S1.erase(0, pos + Delim.length());
	}

	if(S1 != "")
	{
		vClientRecord.push_back(S1);
	}

	return vClientRecord;
}

sClient ConvertLineToRecord(string lineFile , string Separator = "#//#")
{
	sClient Client;

	vector<string> vClientData;
	vClientData = SplitString(lineFile , Separator);

	if(vClientData.size() >= 5)
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

vector<sClient> LoadClientsDataFromFile(string FileName)// هنا بنفتح الفايل كل مره عشان نضيف السطور الي الفيكتور 
{
	vector<sClient> vClients;

	fstream MyFile;
	MyFile.open(FileName , ios::in);//Read only

	if(MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile , Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}




string ConvertRecordToLine(sClient Client , string Delim = "#//#")
{
	string S1 = "";

	S1 += Client.AccountNumber + Delim;
	S1 += Client.PinCode + Delim;
	S1 += Client.ClientName + Delim;
	S1 += Client.Phone + Delim; 
	S1 += to_string(Client.AccountBalance);// لو عايز الرقم يطلع زي ما دخلته بالظبط، ممكن تستخدم stringstream.

	return S1;
}

bool FindClientByAccountNumber(string AccNumber , const vector<sClient>& vClients , sClient& Client)// عشان تعدل في الاصل 
{
	for(sClient C : vClients)
	{
		if(C.AccountNumber == AccNumber)
		{
			Client = C;
			return true;
		}
	}

	return false;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe Following are the Client Details:\n";

	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPinCode       : " << Client.PinCode;
	cout << "\nClient Name   : " << Client.ClientName;
	cout << "\nPhone         : " << Client.Phone; 
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool MarkClientForDeleteByAccountNumber(string AccNumber , vector<sClient>& vClients)
{
	for(sClient& C : vClients)
	{

		if(C.AccountNumber == AccNumber)
		{
			C.MarkForDelete = true; 
			return true;
		}
	}

	return false;
}

void SaveClientsDataToFile(string FileName , vector<sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName , ios::out);//OverWrite

	string DataLine;

	if(MyFile.is_open())
	{
		for(sClient C : vClients)
		{
			if(C.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}

}

bool DeleteClientByAccountNumber(string AccNumber , vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if(FindClientByAccountNumber(AccNumber , vClients , Client))
	{

		PrintClientCard(Client);

		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if(Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccNumber , vClients);
			SaveClientsDataToFile(FileNameClients , vClients);

			//Refersh Clients
			vClients = LoadClientsDataFromFile(FileNameClients);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else 
	{
		cout << "\nClient With Account Number (" << AccNumber << ") is Not Found!.";
	}
	return false;
}

string ReadAccountNumber()
{
	string AccNumber = "";

	cout << "\nEnter Account Number Client you Want Delete? ";
	cin >> AccNumber;

	return AccNumber;
}

int main()
{
	vector<sClient> vClientsRecords = LoadClientsDataFromFile(FileNameClients);
	string AccountNumber = ReadAccountNumber();

	DeleteClientByAccountNumber(AccountNumber , vClientsRecords);



	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
	cin.get();											 // بيستنى منك تضغط Enter عشان يقفل
	return 0;
}