
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

enum enAtmMainMenueOption
{
    eQuickWithdraw = 1 , eNormalWithdraw = 2,
    eDeposit = 3 , eCheckBalance = 4,
    eLogout = 5
};

enum enQuickWithdrawNumber
{
    echoice20 = 1 , echoice50 = 2, echoice100 = 3, echoice200 = 4,
    echoice400 = 5, echoice600 = 6, echoice800 = 7, echoice1000 = 8,
    Exit = 9
};

struct stClient
{
    string AccountNumber; 
    string PinCode;
    string Name;
    string Phone;
    double  AccountBalance;
    bool MarkForDeleted = false;
};
 
const string ClientsFileName = "Clients.txt";
stClient CurrentClient;

void showAtmMainMenueScreen();
void showQuickWithdrawScreen();
void Login();

vector<string> splitStirng(string Line , string Delim)//==> A150#//#1234#//#ahmed maher#//#012928434#//#900.000000
{
    vector<string> vClientData;

    string Word;
    short pos = 0;

    while((pos = Line.find(Delim)) != string::npos)// خلال البوزشن لقي الديليم ايكمل 
    {
        Word = Line.substr(0 , pos);
        if(Word != "")
        {
            vClientData.push_back(Word);
        }

        Line.erase(0 , pos + Delim.length());
    }

    if(Line != "")
        vClientData.push_back(Line);

    return vClientData;
}

stClient convertLineToRecord(string line , string Separator = "#//#")
{
    stClient Client;
    vector<string> vClientData;
    vClientData = splitStirng(line , Separator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string To double

    return Client;
}

vector<stClient> loadClientsDataFromFile(string FileName)
{
    vector<stClient> vClients;

    fstream MyFile;
    MyFile.open(FileName , ios::in);

    if(MyFile.is_open())
    {
        string Line;
        stClient Client;

        while(getline(MyFile , Line))
        {
            Client = convertLineToRecord(Line);
            
            vClients.push_back(Client);
        }
        
        MyFile.close();
    }

    return vClients;
}

bool findClientByAccountNumberAndPinCode(string AccountNumber , string PinCode ,  stClient& CurrentClient)
{
    vector<stClient> vClients = loadClientsDataFromFile(ClientsFileName);

    for(const stClient& C : vClients)
    {
        if(C.AccountNumber == AccountNumber && C.PinCode == PinCode)
        {
            CurrentClient = C;
            return true;
        }
    }

    return false;
}

string convertRecordToLine(stClient Client, string Separator = "#//#")
{
    string DataLine = "";

    DataLine += Client.AccountNumber + Separator;
    DataLine += Client.PinCode + Separator;
    DataLine += Client.Name + Separator;
    DataLine += Client.Phone + Separator;
    DataLine += to_string(Client.AccountBalance);

    return DataLine;
}

vector<stClient> saveClientsDataFromFile(string FileName , vector<stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName , ios::out);

    if(MyFile.is_open())
    {
        string line;

        for(stClient Client : vClients)
        {
            if(Client.MarkForDeleted == false)
            {
                line = convertRecordToLine(Client);
                MyFile << line << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

short readMainMenueOption()
{
    cout << "Choose What do you want to do? [1 To 5]? ";
    short Option;
    cin >> Option;

    return Option;
}

void goBackToAtmMainMenue()
{
    cout << "\n\nPress any Key to go back to Main Menue..";
    system("pause>0");
    showAtmMainMenueScreen();
}



short readWithdrawOption()
{
    int Choice;
    cout << "\nChoose What to withdraw from [1] to [8] ? ";
    cin >> Choice;

    return Choice;
}

bool approveTransaction()
{
    char Approve = 'y';

    cout << "\n\nare you sure you want perform this transaction? Y/n? ";
    cin >> Approve;
    if(tolower (Approve) == 'y')
    {
        return true; 
    }
    
    return false;
}

int getQuickWithdrawAmount(enQuickWithdrawNumber Option)
{
    switch (Option)
    {
    case enQuickWithdrawNumber::echoice20: return 20;
    case enQuickWithdrawNumber::echoice50: return 50;
    case enQuickWithdrawNumber::echoice100: return 100;
    case enQuickWithdrawNumber::echoice200: return 200;
    case enQuickWithdrawNumber::echoice400: return 400;
    case enQuickWithdrawNumber::echoice600: return 600;
    case enQuickWithdrawNumber::echoice800: return 800;
    case enQuickWithdrawNumber::echoice1000: return 1000;
    }

    return 0;
}

bool  quickWithdrawOptions(enQuickWithdrawNumber QuickWithdrawNumber , stClient& Client)
{
    if (QuickWithdrawNumber == enQuickWithdrawNumber::Exit)
        return false;
    
    int amount = getQuickWithdrawAmount(QuickWithdrawNumber);
    
    if(amount > Client.AccountBalance)
    {
        cout << "\n\nthe amount exceeds your balance, Make onther choice.\n";
        system("pause");
        return false;
    }

    Client.AccountBalance -= amount;
    cout << "\n\nDone successfully. New Balance is " << Client.AccountBalance << endl;
    return true;
}

void printQuickWithdrawScreen()
{
    system("cls");
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;
    cout << "\t\tQuick Withdraw\n";
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;
    //setw(22): بتضمن إن العمود الأول هياخد مساحة 22 حرف بالظبط، فبالتالي العمود التاني هيبدأ
    // دايماً من نفس المكان في كل السطور.
    cout <<"    " << left << setw(22) << "[1] 20" << "[2] 50"    << endl;
    cout <<"    " << left << setw(22) << "[3] 100" << "[4] 200"  << endl;
    cout <<"    " << left << setw(22) << "[5] 400" << "[6] 600"  << endl;
    cout <<"    " << left << setw(22) << "[7] 800" << "[8] 1000" << endl;
    cout <<"    " << left << "[9] Exit\n";
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;

}
//Quick Screen
void showQuickWithdrawScreen()
{
    vector<stClient> vClients = loadClientsDataFromFile(ClientsFileName);
    bool IsWithdrawDone = false;

    for(stClient& Client : vClients)
    {
        if(Client.AccountNumber == CurrentClient.AccountNumber)
        {
            do 
            {
                printQuickWithdrawScreen();
                cout << "Your Balance is " << Client.AccountBalance;

                short choice = readWithdrawOption();
                if(choice == 9) break;

                if(approveTransaction())
                {
                    IsWithdrawDone = quickWithdrawOptions((enQuickWithdrawNumber) choice , Client);
                }
                else 
                {
                    cout << "\n\nThe express withdrawal process has been cancelled.";
                    break;
                }

            }while(!IsWithdrawDone);

            break;
        }
    }
    
    saveClientsDataFromFile(ClientsFileName , vClients);
}


int readWithdrawAmount(stClient Client)
{
    int Number;
    do 
    {
        cout << "\nEnter an amount multiple of 5's ? ";
        cin >> Number;

        if(Number > Client.AccountBalance)
        {
            cout << "Amount exceeds your balance, your balance is: " << Client.AccountBalance << endl;
        }
        else if(Number % 5 != 0)
        {
            cout << "Amount must be a multiple of 5!" << endl;
        }

    }while(Number % 5 != 0 || Number > Client.AccountBalance);
    
    return Number;
}
//Normal withdraw
void showNormalWithdrawScreen()
{
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;
    cout << "\t\tNormal Withdraw Screen\n";
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;

    vector<stClient> vClients = loadClientsDataFromFile(ClientsFileName);
    for(stClient& Client : vClients)
    {
        if(Client.AccountNumber == CurrentClient.AccountNumber)
        {
            int amount =  readWithdrawAmount(Client);
            if(approveTransaction())
            {
                Client.AccountBalance -= amount;
                cout << "\n\nDone Successfully. New Balance is: " << Client.AccountBalance;
                break;
            }
            else 
            {
                cout << "\n\nThe withdrawal Process has been Cancelled."; 
                break;
            }
        }
    }
    
    saveClientsDataFromFile(ClientsFileName , vClients);
}


int readPositiveDepositAmount()
{
    int amount;
    do 
    {
        cout << "\nEnter a Positive Deposit Amount? ";
        cin >> amount;

    }while(amount <= 0);

    return amount;
}

void depositAmountToAccountBalance(int Amount , vector<stClient>& vClients)
{
    for(stClient& Client : vClients)
    {
        if(Client.AccountNumber == CurrentClient.AccountNumber)
        {
            Client.AccountBalance += Amount;
            cout << "\n\nDone Successfully, New Balance is " << Client.AccountBalance;
            break;
        }
    }
    
    saveClientsDataFromFile(ClientsFileName , vClients);
}

//Deposit Screen
void showDepositScreen()
{
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;
    cout << "\t\t Deposit Screen\n";
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;

    vector<stClient> vClients = loadClientsDataFromFile(ClientsFileName);
    int Amount = readPositiveDepositAmount();

    if(approveTransaction())
    {
        depositAmountToAccountBalance(Amount , vClients);
    }
    else 
    {
        cout << "\n\nThe Deposit amount Process has been Cancelled.";
    }
}

//Show Balance Screen
void showCheckBalanceScreen()
{
    double dBalance;

    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;
    cout << "\tCheck Balance Screen\n";
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;

    vector<stClient> vClients = loadClientsDataFromFile(ClientsFileName);
    for(const stClient& Client : vClients)
    {
        if(Client.AccountNumber == CurrentClient.AccountNumber)
        {
            dBalance = Client.AccountBalance;
            break;
        }
    }
    
    cout << "\nYour Balance is " << dBalance;
}


void performAtmMainMenue(enAtmMainMenueOption AtmMainMenueOption)
{
    switch (AtmMainMenueOption)
    {
    case enAtmMainMenueOption::eQuickWithdraw:
    {
        system("cls");
        showQuickWithdrawScreen();
        goBackToAtmMainMenue();
        break;
    }
    case enAtmMainMenueOption::eNormalWithdraw:
    {
        system("cls");
        showNormalWithdrawScreen();
        goBackToAtmMainMenue();
        break;
    }
    case enAtmMainMenueOption::eDeposit:
    {
        system("cls");
        showDepositScreen();
        goBackToAtmMainMenue();
        break;
    }
    case enAtmMainMenueOption::eCheckBalance:
    {
        system("cls");
        showCheckBalanceScreen();
        goBackToAtmMainMenue();
        break;
    }
    case enAtmMainMenueOption::eLogout:
    {
        Login();
    }
    }
}

void showAtmMainMenueScreen() 
{
    system("cls");
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;
    cout << "\t\tATM Main menue Screen\n";
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;
    cout << "\t[1]Quick Withdraw.";
    cout << "\n\t[2]Normal Withdraw.";
    cout << "\n\t[3]Deposit.";
    cout << "\n\t[4]Check Balance.";
    cout << "\n\t[5]Logout.\n";
    cout << setfill('=') << setw(53) << "=" << setfill(' ') << endl;

    performAtmMainMenue((enAtmMainMenueOption)readMainMenueOption());
}

bool loadClientInfo(string AccountNumber , string PinCode)
{
    if(findClientByAccountNumberAndPinCode(AccountNumber , PinCode, CurrentClient))
        return true;
    else 
        return false;
}

void Login()
{
    bool LoginFaild = false;
    string AccountNumber , PinCode;
    do 
    {
        system("cls");
        cout << setfill('-') << setw(43) << "-" << setfill(' ') << endl;
        cout << "\tLogin Screen\n";
        cout << setfill('-') << setw(43) << "-" << setfill(' ') << endl;

        if(LoginFaild)
        {
            cout << "Invlaid AccountNumber / PinCode!\n";
        }

        cout << "Enter Account Number? ";
        cin >> AccountNumber;
        cout << "Enter Pin? ";
        cin >> PinCode;

        LoginFaild = !loadClientInfo(AccountNumber , PinCode);

    }while(LoginFaild);

    showAtmMainMenueScreen();
}

int main()

{
    Login();

    cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
	cin.get();											 // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}
