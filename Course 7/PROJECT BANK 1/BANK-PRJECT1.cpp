#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits> // ضرورية لاستخدام numeric_limits

using namespace std;
string FileNameClients = "Clients.txt";

struct sClients
{
	string AccountNumber;
	string pinCode;
	string Name;
	string Phone;
	double AccountBalance;

	bool MarkDeleted = false;
};



//Show All Clients
vector<string> SplitString(string S1 , string Delim)//A150#//#1234#//#ahmed maher#//#012928434#//#12000.000000
{
	vector<string> vRecordClient;

	short Pos = 0;
	string sWord = "";

	while((Pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0 , Pos);

		if(sWord != "")
		{
			vRecordClient.push_back(sWord);
		}

		S1.erase(0 , Pos + Delim.length());
	}

	if(S1 != "")
	{
		vRecordClient.push_back(S1);	
	}

	return vRecordClient;
}

sClients ConvertLineToRecord(string Line , string separator = "#//#")
{
	sClients Client;
	vector<string> vClientRecords = SplitString(Line , separator);

	Client.AccountNumber = vClientRecords.at(0);
	Client.pinCode = vClientRecords.at(1);
	Client.Name = vClientRecords.at(2);
	Client.Phone = vClientRecords.at(3);
	Client.AccountBalance = stod(vClientRecords.at(4));

	return Client;
}

vector<sClients> LoadClientsDataFromFile(string FileName)
{
	vector<sClients> vClient;

	fstream MyFile;
	MyFile.open(FileName , ios::in);

	sClients Client;
	string Line;

	if(MyFile.is_open())
	{
		while(getline(MyFile , Line))
		{
			if(Line != "")
			{
				Client = ConvertLineToRecord(Line);
				vClient.push_back(Client);
			}
		}

		MyFile.close();
	}

	return vClient;
}

void PrintRecordsClients(sClients& ClientData)
{

	cout << "| " << left << setw(15) << ClientData.AccountNumber;
	cout << "| " << left << setw(10) << ClientData.pinCode;
	cout << "| " << left << setw(40) << ClientData.Name;
	cout << "| " << left << setw(18) << ClientData.Phone;
	cout << "| " << left << setw(15) << ClientData.AccountBalance;

}

void PrintClientsList(vector<sClients>& vClient)
{
	cout << "\n\t\t\t\t\t Client List (" << vClient.size() << ") Client(s).";

	cout << endl << left << setfill('_') << setw(140) << "_" << endl << setfill(' ');

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(18) << "Phone";
	cout << "| " << left << setw(15) << "Account Balance"; 

	cout << endl << left << setfill('_') << setw(140) << "_" << endl << setfill(' ');

	for(sClients &C : vClient)
	{
		PrintRecordsClients(C);
		cout << endl;
	}

	cout << endl << left << setfill('_') << setw(140) << "_" << endl << setfill(' ');
	
}

void ShowClientList()
{
	vector<sClients> vClients = LoadClientsDataFromFile(FileNameClients);
	PrintClientsList(vClients);
}



//Add Client
sClients ReadClient(const vector<sClients>& vClients)// مينفعش ابعت & لوحدها للفيكتور من غير ما اعرف الفيكتور بميموري عند الداله الماخوذ منها او اضافه كونست بالبراميتر
{
	sClients newClient;
	bool AccNumFound = false;

	do 
	{
		cout << "\nEnter Account Number? ";
		getline(cin >> ws , newClient.AccountNumber);// هنا فيه لسه طلب ادخال اكونت نامبر مش موجود بفايل
		AccNumFound = false;
		for(const sClients& C : vClients)
		{
			if(newClient.AccountNumber == C.AccountNumber)
			{
				cout << "Client With [" << newClient.AccountNumber << "] already exists, Enter another Account Number?";
				AccNumFound = true;
				break;
			}			
		}
	}while(AccNumFound == true);

	cout << "Enter PinCode? ";
	getline(cin , newClient.pinCode);

	cout << "Enter name: ";
	getline(cin , newClient.Name);

	cout << "Enter Phone: ";
	getline(cin , newClient.Phone);

	cout << "Enter AccountBalance: ";
	cin >> newClient.AccountBalance;

	cin.ignore();

	return newClient;

}

string convertRecordToLine(sClients Client , string Separator = "#//#")
{
	string strClient = "";

	strClient += Client.AccountNumber + Separator;
	strClient += Client.pinCode + Separator;
	strClient += Client.Name + Separator;
	strClient += Client.Phone + Separator;
	strClient += to_string(Client.AccountBalance);

	return strClient;
}

void AddDataToFile(string FileName , string stDataLineNewClient)
{
	fstream MyFile;
	MyFile.open(FileName , ios::out | ios::app);

	if(MyFile.is_open())
	{
		MyFile << stDataLineNewClient << endl;
		MyFile.close();
	}

}

void AddNewClient()
{
	sClients NewClient;
	vector<sClients> vClients = LoadClientsDataFromFile(FileNameClients);
	NewClient = ReadClient(vClients);
	AddDataToFile( FileNameClients , convertRecordToLine(NewClient));
}

void AddClient()
{
	char AskMore = 'n';

	do
	{
		cout << "\n\nAdding New Client:\n";
		AddNewClient();
		cout << "\nClient Added Successfully, Do you want add more clients ? y/n ? ";
		cin >> AskMore;

	}while (tolower(AskMore) == 'y');

}


//Delete Client 
void PrintHeader()
{	
	cout << endl << left << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
	cout << "\t\tDelete Client Screen";
	cout << endl << left << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
}

void PrintClientDeleted(sClients DeletedClient)
{

 	cout << "The following are the Client details:";
	cout << endl << left << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
	cout << "Account Number: " << DeletedClient.AccountNumber;
	cout << "\nPin Code    : " << DeletedClient.pinCode;
	cout << "\nName        : " << DeletedClient.Name;
	cout << "\nPhone       : " << DeletedClient.Phone;
	cout << "\nAccount Balance: " << DeletedClient.AccountBalance;
	cout << endl << left << setfill('-') << setw(60) << "-" << setfill(' ') << endl;


}

void DeletedClientFromFile(string FileName , vector<sClients>& vClients , sClients& Client)
{
	fstream MyFile;
	MyFile.open(FileName , ios::out);
	
	if(MyFile.is_open())
	{
		for(sClients& C : vClients)
		{
			if(C.MarkDeleted == false)
			{
				MyFile << convertRecordToLine(C) << endl;
			}
		}
		
		MyFile.close();
	}


}

void DeleteClient()
{
	PrintHeader();

	vector<sClients> vClients = LoadClientsDataFromFile(FileNameClients);

	
	cout << "\nEnter Account Number Client you want Delete. ";
	string AccountNumber;
	getline(cin >> ws , AccountNumber);
	
	bool ClientFound = false;
	char AskDel = 'n';

	for(sClients& C : vClients)
	{
		if(C.AccountNumber == AccountNumber)
		{
			ClientFound = true;
			PrintClientDeleted(C);

			cout << "\n\nAre you sure you want delete this Client?  y / n ? ";
			cin >> AskDel;

			if (tolower(AskDel) == 'y')
			{
				C.MarkDeleted = true;
				DeletedClientFromFile(FileNameClients , vClients , C);
				cout << "\nClient Deleted Successfully.\n";
			}

			break;
		}
	}

	if(!ClientFound)
	{
		cout << "\nClient With Account Number [" << AccountNumber << "] Not Found!.\n";
	}	

}



//Read Menue 1 to 6
short ReadNumber1To6()
{
	short number;
	do 
	{
		cout << "Choose what do you want to do ? [1 to 6]? ";
		cin >> number;

	}while(number < 1 || number > 6);

	return number;
}

void PrintListOfChoices()
{
	cout << left << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
	cout << "\t\t\tMain Menue Screen\n";
	cout << left << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
	
	cout << "\t\t[1] show Client List.\n";
	cout << "\t\t[2] Add New Client.\n";
	cout << "\t\t[3] Delete Client.\n";
	cout << "\t\t[4] Update Client Info.\n";
	cout << "\t\t[5] Find Client.\n";
	cout << "\t\t[6]Exit.\n";
	cout << left << setfill('=') << setw(60) << "=" << setfill(' ') << endl;

	ReadNumber1To6();
}

int main()
{
	PrintListOfChoices();

	ShowClientList();
	AddClient();
	DeleteClient();



	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
	cin.get();											 // بيستنى منك تضغط Enter عشان يقفل
	return 0;
}