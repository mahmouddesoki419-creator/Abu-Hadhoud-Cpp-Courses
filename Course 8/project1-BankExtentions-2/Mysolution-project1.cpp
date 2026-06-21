#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

//دايما الستركشرز و الاينمز اول حاجه 
struct stCurrentUser
{
    string UserName;
    string Password;
    short Permission = 0;
};

struct stUsers
{
    string UserName;
    string Password;
    short Permissions = 0;
};

struct stClients
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
    
};

//=================================================//
enum enMainMenueOptions
{
    eListClient = 1 , eAddClient = 2 , eDeleteClient = 3 , eUpdateClient = 4, 
    eFindClient = 5 , eTransactions = 6 , eManageUsers = 7 , eLogOut = 8 
};

enum enTransactionsOptions
{
    enDeposit = 1 , enWithdraw = 2 , 
    enTotalBalance = 3 , enMainMenu = 4
};

enum enManageUsersOptions
{
    enListUsers = 1, enAddNewUser = 2, enDeleteUser = 3,
    enUpdateUser = 4, enFindUser = 5, enMainMenue = 6 
};

enum enPermissions
{
    enFullAccess = -1, enShowClientList = 1, enAddClient = 2, enDeleteClient = 4,
    enUpdateClient = 8, enFindClient = 16, enTransactions = 32,
    enManageUsers = 64
};


const string FileUsersName = "Users.txt";
const string FileClientsName = "Clients.txt";

stCurrentUser CurrentUser;

// الـ Forward Declarations (الـ Prototypes) بتاعت الفانكشنز
void showMainMenue();
void loginScreen();
void showTransactionsMenue();


vector<string> splitString(string line , string Delim)//===>   Admin#//#1234#//#-1

{
    vector<string> vString;

    short pos = 0;
    string sWord;// define a string variable  

    while((pos = line.find(Delim)) != string::npos)
    {
        sWord = line.substr(0 , pos);// store the word   

        if(sWord != "")
        {
            vString.push_back(sWord);
        }
        line.erase(0 , pos + Delim.length()); /* erase() until positon and move to next word. */
    }

    if(line != "")
    {
        vString.push_back(line);
    }

    return vString;
}

stUsers convertLineToRecordUsers(string line , string Separator = "#//#")
{
    stUsers User;
    vector<string> vUserDate;

    vUserDate = splitString(line , Separator);

    if(vUserDate.size() < 3)
    {
        return User;
    }

    User.UserName = vUserDate[0];
    User.Password = vUserDate[1];
    User.Permissions = stoi(vUserDate[2]);

    return User;
}

stClients convertLineToRecordClients(string line , string Separator = "#//#")
{
    stClients Client;
    vector<string> vClientsDate;

    vClientsDate = splitString(line , Separator);

    Client.AccountNumber = vClientsDate[0];
    Client.PinCode = vClientsDate[1];
    Client.Name = vClientsDate[2];
    Client.Phone = vClientsDate[3];
    Client.AccountBalance = stoi(vClientsDate[4]);

    return Client;
}

//Cheack user exsits
bool isUserExsits(string UserName , string Password , string FileUsersName , stCurrentUser& CurrentUser)
{   
    fstream MyFile;
    MyFile.open(FileUsersName , ios::in);

    
    if(MyFile.is_open())
    {
        string Line;
        stUsers UserFromFile;

        while(getline(MyFile , Line))
        {
            UserFromFile = convertLineToRecordUsers(Line);
            if(UserFromFile.UserName == UserName && UserFromFile.Password == Password)
            {
                // هنا شحن اليوزر المدخل الحالي وتعريف صلاحياته لاستخدامه لحل دوال الاوبشنز
                CurrentUser.UserName = UserFromFile.UserName;
                CurrentUser.Password = UserFromFile.Password;
                CurrentUser.Permission = UserFromFile.Permissions;

                MyFile.close();
                return true;
            }
        }
        
        MyFile.close();
    }

    return false;

}



vector<stClients> loadClientsDataFromFile(string FileName)
{
    vector<stClients> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if(MyFile.is_open())
    {
        string line;
        stClients Client;

        while(getline(MyFile, line))
        {
            Client = convertLineToRecordClients(line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

void printClientRecord(stClients Clients)
{
    cout << "| " << setw(15) << left << Clients.AccountNumber;
    cout << "| " << setw(10) << left << Clients.PinCode;
    cout << "| " << setw(40) << left << Clients.Name;
    cout << "| " << left << setw(12) << Clients.Phone;
    cout << "| " << setw(12) << left << Clients.AccountBalance;
}

//Show all Clients Screen
void showAllClientsScreen()
{
    vector<stClients> vClients =  loadClientsDataFromFile(FileClientsName);
    
    
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if(vClients.size() == 0)
    {
        cout << "\t\t\tNo Clients Available In the system!";
    } 
    else 
    {
        for(stClients Client: vClients)
        {
            printClientRecord(Client);
            cout << endl;
        }
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;


}



bool clientExistsByAccountNumber(string AccountNumber , string FileName)
{
    vector<stClients> vClients;

    fstream MyFile;
    MyFile.open(FileName , ios::in);

    if(MyFile.is_open())
    {
        string line;
        stClients Client;

        while(getline(MyFile , line))
        {
            Client = convertLineToRecordClients(line);
            if(Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return false;
}

stClients readNewClient()
{
    stClients Client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);

    while(clientExistsByAccountNumber(Client.AccountNumber , FileClientsName))// داله الفحص عن الكلاينت موجود
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin >> ws, Client.Name);

    cout << "Enter Phone? ";
    getline(cin >> ws, Client.Phone);

    cout << "Enter Account Balance? ";
    cin >> Client.AccountBalance;

    return Client;
}

string convertRecordToLine(stClients Client , string Separator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.Name + Separator;
    stClientRecord += Client.Phone + Separator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

void addDataLineToFile(string FileName , string ClientDate)
{
    fstream MyFile;
    MyFile.open(FileName , ios::out | ios::app);

    if(MyFile.is_open())
    {
        MyFile << ClientDate << endl;
        
        MyFile.close();
    }

}

void addNewClient()
{
    stClients Client;
    Client = readNewClient();
    addDataLineToFile(FileClientsName , convertRecordToLine(Client));
}

void addNewClients()
{
    char AddMore = 'y';
    do
    {
        cout << "Adding New clients:\n\n";
        addNewClient();

        cout << "\nClient Added Successfully, do you want to Add more Clinets? Y/n? ";
        cin >> AddMore;

    }while(tolower(AddMore) == 'y');

}

//Add New Client
void showAddNewClientScreen()
{
    cout << left << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
    cout << "\tAdd New Clients Screen\n";
    cout << left << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    addNewClients();
}


//////////////
string readClientAccountNumber()
{
    string AccountNumber = "";

    cout << "Please Enter AccountNumber? ";
    cin >> AccountNumber;

    return AccountNumber;
}
//////////////

bool findClientByAccountNumber(string AccountNumber , vector<stClients> vClients , stClients& Client)
{
    for(stClients C : vClients)
    {
        if(C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
}

void printClientCard(stClients Client)
{
    cout << "\nThe Following are the Client details:\n";
    cout << left << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
    
    cout << "Account Number: " << Client.AccountNumber;
    cout << "\nPin Code      : " << Client.PinCode;
    cout << "\nName          : " << Client.Name;
    cout << "\nPhone         : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance << endl;
    cout << left << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
}

bool markClientForDeletedByAccountNumber(string AccountNumber , vector<stClients>& vClients)
{
    for(stClients& C : vClients)
    {
        if(C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }

    return false;
}

vector<stClients> saveClientsDataToFile(string FileName , vector<stClients> vClients)
{
    fstream MyFile;
    MyFile.open(FileName , ios::out);

    string DataLine;
    if(MyFile.is_open());
    {
        for(stClients C : vClients)
        {
            if(C.MarkForDelete == false)
            {
                DataLine = convertRecordToLine(C);
                MyFile << DataLine << endl; 
            }
        }
        MyFile.close();
    }

    return vClients;
}

bool deleteClientByAccountNumber(string AccountNumber , vector<stClients>& vClients)
{
    stClients Client;
    char Answer = 'n';

    if(findClientByAccountNumber(AccountNumber , vClients , Client))
    {
        printClientCard(Client);
        cout << "\n\nAre you sure you want delete this Client ? Y/n? ";
        cin >> Answer;

        if(tolower(Answer) == 'y')
        {
            markClientForDeletedByAccountNumber(AccountNumber , vClients);
            saveClientsDataToFile(FileClientsName , vClients);// مش لازم نبعت & للفيكتور عشان كلو متعدل ووجدنا كلاينت نحذفه 

            //Refresh Clients 
            vClients = loadClientsDataFromFile(FileClientsName);
            cout << "\n\nClient Deleted Successfully.";
            return true;
        }

    }
    else 
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is not found!";
    }
    return false;
}

//Delete Client
void showDeleteClientScreen()
{
    cout << left << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
    cout << "\tDelete Client Screen\n";
    cout << left << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    vector<stClients> vClients = loadClientsDataFromFile(FileClientsName);
    string AccountNumber = readClientAccountNumber();

    deleteClientByAccountNumber(AccountNumber , vClients);
}


stClients changeClientRecord(string AccountNumber)
{
    stClients Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter Pin Code? ";
    getline(cin >> ws, Client.PinCode);
    
    cout << "\nEnter Name? ";
    getline(cin >> ws, Client.Name);

    cout << "\nEnter Phone? ";
    getline(cin >> ws, Client.Phone);

    cout << "\nEnter Account Balance? ";
    cin >> Client.AccountBalance;

    return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber , vector<stClients>& vClients)
{
    stClients Client;
    char Answer = 'n';

    if(findClientByAccountNumber(AccountNumber , vClients , Client))
    {
        printClientCard(Client);
        cout << "\n\nAre you sure you want to Update this client? Y/n? ";
        cin >> Answer;

        if(tolower(Answer) == 'y')
        {
            for(stClients &C : vClients)
            {
                if(C.AccountNumber == AccountNumber)
                {
                    C = changeClientRecord(AccountNumber);
                    break;
                }
            }

            vClients = saveClientsDataToFile(FileClientsName , vClients);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else 
    {
        cout << "\n\nNot Found Client by this Account Number (" << AccountNumber << ")!!";
    }
    return false;
}

//Update Client
void showUpdateClientScreen()
{
    cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
    cout << "\tUpdate Client Screen\n";
    cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
    
    vector<stClients> vClients = loadClientsDataFromFile(FileClientsName);
    string AccountNumber = readClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber , vClients);
}

//find Client
void showFindClientScreen()
{
    cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
    cout << "\tFind Client Screen\n";
    cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;

    vector<stClients> vClients = loadClientsDataFromFile(FileClientsName);
    stClients Client;
    string AccountNumber = readClientAccountNumber();

    if(findClientByAccountNumber(AccountNumber , vClients , Client))
        printClientCard(Client);
    else 
        cout << "\nClient with Account Number[" << AccountNumber << "] is not Found!";
    
}

//==========================================//Transatcions code

bool depositBalanceToClientByAccountNumber(string AccountNumber , double Amount , vector<stClients>& vClients)
{
    char Answer = 'y';
    
    cout << "\nAre you sure you want perform this transaction? Y/n? ";
    cin >> Answer;
    
    if(tolower(Answer) == 'y')
    {
        for(stClients& C : vClients)
        {
            if(C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                saveClientsDataToFile(FileClientsName , vClients);
                cout << "\n\nDone Successfully, new balance is: " << C.AccountBalance;
                
                return true;
            }
        }
    }

    return false;
}

//Deposit 
void showDepositScreen()
{   
    cout << setfill('-') << setw(43) << "=" << setfill(' ') << endl;
    cout << "\tDeposit Screen\n";
    cout << setfill('-') << setw(43) << "=" << setfill(' ') << endl;

    vector<stClients> vClients = loadClientsDataFromFile(FileClientsName);
    stClients Client;
    string AccountNumber = readClientAccountNumber();

    while(!findClientByAccountNumber(AccountNumber , vClients , Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.";
        AccountNumber = readClientAccountNumber();
    }

    printClientCard(Client);

    cout << "\nPlease enter deposit amount? ";
    double amount;
    cin >> amount;

    depositBalanceToClientByAccountNumber(AccountNumber , amount , vClients);
}


//Withdraw
void showWithdrawScreen()
{
    cout << setfill('-') << setw(43) << "=" << setfill(' ') << endl;
    cout << "\tWithdraw Screen\n";
    cout << setfill('-') << setw(43) << "=" << setfill(' ') << endl;

    string AccountNumber = readClientAccountNumber();
    vector<stClients> vCliets = loadClientsDataFromFile(FileClientsName);
    stClients Client;

    while(!findClientByAccountNumber(AccountNumber , vCliets , Client))
    {
        cout << "\nClient wiht this Account Number [" << AccountNumber << "] is not Found!";
        AccountNumber = readClientAccountNumber();
    }

    for(stClients& C : vCliets)
    {
        if(C.AccountNumber == AccountNumber)
        {
            printClientCard(Client);
        }
    }

    cout << "\nPlease enter Withdraw amount? ";
    double amount;
    cin >> amount;

    while(amount > Client.AccountBalance)
    {
        cout << "\nAmont Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> amount;
    }

    depositBalanceToClientByAccountNumber(AccountNumber , amount * -1 , vCliets);
}


void printClientRecordBalanceLine(stClients Client)
{
    cout << "| " << left << setw(25) << Client.AccountNumber;
    cout << "| " << setw(40) << Client.Name;
    cout << "| " << setw(30) << Client.AccountBalance;// or ++ cout << endl; and cancel in screen function

}

//Total Balance
void showTotalBalanceScreen()
{
    vector<stClients> vClients = loadClientsDataFromFile(FileClientsName);

    cout << "\n\t\t\t\t\tBalance List(" << vClients.size() << ") Client(s).\n\n";
    cout << left << setfill('-') << setw(140) << "-" << setfill(' ') << endl;
    cout << "| " << left << setw(25) << "Account Number";
    cout << "| " << setw(40) << "Client Name";
    cout << "| " << setw(30) << "Balance" << endl;
    cout << left << setfill('-') << setw(140) << "-" << setfill(' ') << endl;

    int TotalBalance = 0;

    if(vClients.size() == 0)
    {
        cout << "\t\t\t\tNo Clients Available In System!";
    }
    else 
    {
        for(stClients C : vClients)
        {
            printClientRecordBalanceLine(C);
            TotalBalance += C.AccountBalance;
            cout << endl;
        }
    }
    cout << left << setfill('-') << setw(140) << "-" << setfill(' ') << endl;

    cout << "\n\t\t\t\t\tTotal Balance = " << TotalBalance;

}



void printUserRecordToList(stUsers User)
{
    cout << endl << "| " << left << setw(40) << User.UserName;
    cout << "| " << setw(30) << User.Password;
    cout << "| " << setw(30) << User.Permissions;
}

vector<stUsers> loadUsersDataFromFile(string FileName)
{
    vector<stUsers> vUsers;

    fstream MyFile;
    MyFile.open(FileName , ios::in);//read mode

    if(MyFile.is_open())
    {
        string DataLine;
        stUsers User;

        while(getline(MyFile , DataLine))
        {
            User = convertLineToRecordUsers(DataLine);
            vUsers.push_back(User);
        }

        MyFile.close();
    }

    return vUsers;
}

//List Users Screen
void showListUsersScreen()
{
    vector<stUsers> vUsers = loadUsersDataFromFile(FileUsersName);
    
    cout << "\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s)\n";
    cout << endl << left << setfill('-') << setw(140) << "-" << setfill(' ') << endl;
    cout << endl << "| " << left << setw(40) << "User Name";
    cout << "| " << setw(30) << "Passward";
    cout << "| " << setw(30) << "Permissions" << endl;
    cout << endl << left << setfill('-') << setw(140) << "-" << setfill(' ') << endl;
    
    for(stUsers U : vUsers)
    {
        printUserRecordToList(U);
        cout << endl;
    }
    cout << endl << left << setfill('-') << setw(140) << "-" << setfill(' ') << endl;


}



bool findUser(string UserNameData , string fileName)
{
    //vector<stUsers> vUsers = loadUsersDataFromFile(FileUsersName);

    fstream MyFile;

    MyFile.open(fileName , ios::in);//read mode

    if(MyFile.is_open())
    {
        string DataLine;
        stUsers User;
        while(getline(MyFile , DataLine))
        {
            User = convertLineToRecordUsers(DataLine);
            if(User.UserName == UserNameData)
            {
                MyFile.close();
                return true;
            }

        }
        MyFile.close();
    }

    return false;
}

bool isPermissionsUserFullAccess()
{
    
    cout << "\nDo you want to give all access? Y/n? ";
    char Answer;
    cin >> Answer;
    if(tolower(Answer) == 'y')
    {
        return true;
    }
     
    return false;
}

//global funtion
short addAccessPermissionsToUser()
{
    cout << "\nDo you want give access to:";

    short PermissionNumber = 0;
    char Answer;

    cout << "\n\nShow Client list? Y/n? ";
    cin >> Answer;
    if(tolower(Answer) == 'y')
    {
        PermissionNumber |= enPermissions::enShowClientList; 
    }

    cout << "\nAdd New Client? Y/n? ";
    cin >> Answer;
    if(tolower(Answer) == 'y')
    {
        PermissionNumber |= enPermissions::enAddClient;
    }

    cout << "\nDelete Client? Y/n? ";
    cin >> Answer;
    if(tolower(Answer) == 'y')
    {
        PermissionNumber |= enPermissions::enDeleteClient;
    }

    cout << "\nUpdate Client? Y/n? ";
    cin >> Answer;
    if(tolower(Answer) == 'y')
    {
        PermissionNumber |= enPermissions::enUpdateClient;
    }

    cout << "\nFind Client? Y/n? ";
    cin >> Answer;
    if(tolower(Answer) == 'y')
    {
        PermissionNumber |= enPermissions::enFindClient;
    }

    cout << "\nTransactions? Y/n? ";
    cin >> Answer;
    if(tolower(Answer) == 'y')
    {
        PermissionNumber |= enPermissions::enTransactions;
    }

    cout << "\nManage Users? Y/n? ";
    cin >> Answer;
    if(tolower(Answer) == 'y')
    {
        PermissionNumber |= enPermissions::enManageUsers;
    }

    return PermissionNumber;
}

stUsers readAddNewUser(string UserName , string Password)
{
    stUsers User;

    cout << "\nEnter Username: ";
    getline(cin >> ws, UserName);
    while(findUser(UserName , FileUsersName))
    {
        cout << "\n\nUser with [" << UserName << "] already exists, Enter another UserName? ";
        getline(cin >> ws, UserName);
    }

    cout << "Enter Password: ";
    getline(cin >> ws, Password);


    //شحن (اسم وباسورد) اليوزر طالما مش موجود بالفايل
    User.UserName = UserName;
    User.Password = Password;
    if(isPermissionsUserFullAccess())
    {
        User.Permissions = -1;
        return User;
    }

    User.Permissions = addAccessPermissionsToUser();
    return User;
}

string converRecordToLine_Users(stUsers User , string Separator = "#//#")
{
    string DataLineUser = "";

    DataLineUser += User.UserName + Separator;
    DataLineUser += User.Password + Separator;
    DataLineUser += to_string(User.Permissions);

    return DataLineUser;
}

void addDataLineToFile_Users(string FileName , string DataLine_User)
{
    fstream MyFile;

    MyFile.open(FileName , ios::out | ios::app); // save user data to file 

    if(MyFile.is_open())
    {
        MyFile << DataLine_User << endl;
        MyFile.close();
    }

}

void AddNewUsers()
{
    char AddMore = 'n';
    stUsers User;
    string UserName;
    string Password;

    do 
    {
        cout << "\nAdding New User:\n\n";
        User = readAddNewUser(UserName , Password);

        addDataLineToFile_Users(FileUsersName , converRecordToLine_Users(User));//save and print data user to file

        cout << "\nUser Added Successfully, do you want to add more Users? Y/n? ";
        cin >> AddMore;
    }while(tolower(AddMore) == 'y');

}
//Add new Users
void showAddUsersScreen()
{
    cout << endl << left << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
    cout << "\tAdd New User Screen";
    cout << endl << left << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
    
    AddNewUsers();
}


//IIIIIIIIIIIIglobal function
string readUsername()
{
    string UserName = "";

    cout << "\nPlease enter Username? ";
    getline(cin >> ws, UserName);

    while(!findUser(UserName , FileUsersName))
    {
        cout << "\n\nUser With Username [" << UserName << "], is Not Found!!";
        cout << "\nPlease enter another Username? "; 
        getline(cin >> ws, UserName);
    }

    return UserName;
}
///IIIIIIIIIII

/////---------global function
void printUserRecordDetails(stUsers User)
{
    cout << "\nThe Following are the User details:\n";
    cout << setfill('-') << setw(43) << "-" << setfill(' ') << endl;
    cout << "Username: " << User.UserName <<  endl;
    cout << "Password: " << User.Password << endl;
    cout << "Permissions: " << to_string(User.Permissions) << endl;
    cout << setfill('-') << setw(43) << "-" << setfill(' ') << endl;
}
////----------


bool deleteUserFromFileByUserName(string FileName , string userName , vector<stUsers>& vUsers)
{

    char Approve = 'n';

    for(const stUsers& User : vUsers)
    {
        if(User.UserName == userName)
        {
            printUserRecordDetails(User);
            break;
        }
    }

    //تاكيد الحذف من اليوزر
    cout << "\nAre you sure you want  delete this user? Y/n? ";
    cin >> Approve;

    if(tolower(Approve) == 'y')
    {
    fstream MyFile;
    MyFile.open(FileName, ios::out);
        
    string Line = "";

    if(MyFile.is_open())
    {
        for(const stUsers& User : vUsers)
        {
            if(User.UserName != userName)
            {
                Line = converRecordToLine_Users(User);
                MyFile << Line << endl; 
            }
        }
        MyFile.close();

        vUsers = loadUsersDataFromFile(FileName);//هنا خلينا اليفكتور متزامن مع التحديث حيث لو استخدمته تاني بفاكشن ديليت يوزرز ايكون اخر ابديت ليه 
        cout << "\nUser Deleted Successfully.";
        return true;
    }
    }
    else 
    {
        cout << "\nDeletion Cancelled.";
    }

    return false;
}

void DeleteUsers()
{
    string UserName;

    vector<stUsers> vUsers = loadUsersDataFromFile(FileUsersName);

    UserName = readUsername();
    deleteUserFromFileByUserName(FileUsersName , UserName , vUsers);
    
}
//Delete user
void showDeleteUsersScreen()
{
    cout << setfill('-') << setw(40) << "-" << setfill(' ');
    cout << "\n\tDelete Users Screen\n";
    cout << setfill('-') << setw(40) << "-" << setfill(' ');

    DeleteUsers();
}


stUsers readUpdateUser(stUsers& User)
{
    cout << "\nEnter Password? ";
    getline(cin >> ws, User.Password);

    cout << "\nDo you want to give full access? Y/n? ";
    char Approve = 'n';
    cin >> Approve;

    if(tolower(Approve) == 'y')
    {
        User.Permissions = -1;
        return User;
    }

    User.Permissions = addAccessPermissionsToUser();// شحن رقم البريمشن 
    return User;
}

bool updateUserFromFileByUserName(string FileName , string userName , vector<stUsers>& vUsers)
{
    char Approve = 'y';

    for(const stUsers& User : vUsers)
    {
        if(User.UserName == userName)
        {
            printUserRecordDetails(User);
            break;
        }
    }

    cout << "\n\nAre you sure you want update this user? Y/n? ";
    cin >> Approve;

    if(tolower(Approve) == 'y')
    {   
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//تنظيف البافر من انتر ال cin 

        fstream MyFile;
        MyFile.open(FileName , ios::out);
        
        string Line = "";

        if(MyFile.is_open())
        {
            for(stUsers& User : vUsers)
            {
                if(User.UserName == userName)
                {
                    readUpdateUser(User);
                    Line = converRecordToLine_Users(User);

                    MyFile << Line << endl;
                }
                else 
                {
                    Line = converRecordToLine_Users(User);
                    MyFile << Line << endl;
                }
            }
            MyFile.close();
            vUsers = loadUsersDataFromFile(FileName);
            cout << "\nUpdate Completed.";
            return true;
        }
    }
    else 
    {
        cout << "\nUpdated Canceled.";
    }

    return false;
}

void updateUser()
{
    string UserName;

    vector<stUsers> vUsers = loadUsersDataFromFile(FileUsersName);

    UserName = readUsername();

    updateUserFromFileByUserName(FileUsersName , UserName , vUsers);
}
//Update user 
void showUpdateUsersScreen()
{
    cout << setfill('-') << setw(40) << "-" << setfill(' ');
    cout << "\n\tUpdate Users Screen\n";
    cout << setfill('-') << setw(40) << "-" << setfill(' ');

    updateUser();

}


void findUser(string FileName)
{
    string UserName = readUsername();
    vector<stUsers> vUsers = loadUsersDataFromFile(FileUsersName);
    stUsers User1;

    for(stUsers User : vUsers)
    {
        if(User.UserName == UserName)
        {
            printUserRecordDetails(User);
            break;
        }
    }
}

//find user
void showFindUserScreen()
{
    cout << setfill('-') << setw(43) << "-" << setfill(' ') << endl;
    cout << "\tFind User Screen\n";
    cout << setfill('-') << setw(43) << "-" << setfill(' ') << endl;

    findUser(FileUsersName);
}

//---go back to options Menue
void goBackToMainMenue()
{
    cout << "\n\nPress any Key to go back to main Menue...";
    system("pause>0");
    showMainMenue();
}

void goBackToTransactionsMenue()
{
    cout << "\n\nPress any Key to go back to Transactions Menue...";
    system("pause>0");
}

void goBackToManageUsersMenue()
{
    cout << "\n\nPress any Key go back to Manage Users Menue...";
    system("pause>0");
}
//---

/// Accessing the option
short readMainMenueOptions()
{
    cout << "Choose What do you want to do? [1 to 8]? ";
    short Choice;
    cin >> Choice;

    return Choice;
}

short readTransactionsMainOptions()
{
    short Choice = 0;
    cout << "Choose what do you want to do? [1 To 4]? ";
    cin >> Choice;

    return Choice;
}

short readManageUsersOptions()
{
    cout << "\nChoose what do you want to do? [1 to 6]? ";
    short Choice;
    cin >> Choice;

    return Choice;
}
///


void performTransactionsOptions(enTransactionsOptions TransactionsMenuOption)
{
    switch (TransactionsMenuOption)
    {

    case enTransactionsOptions::enDeposit:
    {
        system("cls");
        showDepositScreen();
        goBackToTransactionsMenue();
        break;
    }

    case enTransactionsOptions::enWithdraw:
    {
        system("cls");
        showWithdrawScreen();
        goBackToTransactionsMenue();
        break;
    }

    case enTransactionsOptions::enTotalBalance:
    {
        system("cls");
        showTotalBalanceScreen();
        goBackToTransactionsMenue();
        break;
    }
    case enTransactionsOptions::enMainMenu:
    {
        break;
    }
    
    }
}

void showTransactionsMenue()
{
    bool Running = true;
    short Choice = 0;

    while(Running)
    {
    system("cls");
    cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
    cout << "\tShow Transactions Menu\n";
    cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
    cout << "[1] Deposit.";
    cout << "\n[2] Withdraw.";
    cout << "\n[3] Total Balances.";
    cout << "\n[4] Main menu.\n";
    cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
    
    Choice = readTransactionsMainOptions();

    enTransactionsOptions Option = (enTransactionsOptions) Choice;

    if(Option == enTransactionsOptions::enMainMenu)
    {
        Running = false;
    }
    else 
    {
        performTransactionsOptions(Option);
    }

    }
}

 

void performManageUsersMenue(enManageUsersOptions ManageUsersOptions)
{
    switch (ManageUsersOptions)
    {

    case enManageUsersOptions::enListUsers:
    {
        system("cls");
        showListUsersScreen();
        goBackToManageUsersMenue();
        break;
    }
    
    case enManageUsersOptions::enAddNewUser:
    {
        system("cls");
        showAddUsersScreen();
        goBackToManageUsersMenue();
        break;
    }
    
    case enManageUsersOptions::enDeleteUser:
    {
        system("cls");
        showDeleteUsersScreen();
        goBackToManageUsersMenue();
        break;
    }
    
    case enManageUsersOptions::enUpdateUser:
    {
        system("cls");
        showUpdateUsersScreen();
        goBackToManageUsersMenue();
        break;   
    }
    
    case enManageUsersOptions::enFindUser:
    {
        system("cls");
        showFindUserScreen();
        goBackToManageUsersMenue();
        break;
    }

    case enManageUsersOptions::enMainMenue:
    {
        break;
    }
    
    }
}

//manage users
void showManageUsersMenue()
{
    bool Running = true;
    short Choice = 0;

    while(Running)
    {
        system("cls");

        cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
        cout << "\t\tManage Users Menue Screen\n";
        cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
        cout << "\t[1] List Users.";
        cout << "\n\t[2] Add New User.";
        cout << "\n\t[3] Delete User.";
        cout << "\n\t[4] Update User.";
        cout << "\n\t[5] Find User.";
        cout << "\n\t[6] Main Menue.\n";
        cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;

        Choice = readManageUsersOptions();
        enManageUsersOptions Option = (enManageUsersOptions) Choice;
        if(Option == enManageUsersOptions::enMainMenue)
        {
            Running = false;
        }
        else 
        {
            performManageUsersMenue((enManageUsersOptions) Option);
        }

    }
}

void printAccessDenied()
{
    cout << "\n---------------------------\n";
    cout << "Access Denied,\n";
    cout << "You dont have Permission To Do this,\n";
    cout << "Please Contact Your Admin.";
    cout << "\n---------------------------\n";   
}

bool checkAccessPermission(enPermissions permissionUser)
{
    if(CurrentUser.Permission == enPermissions::enFullAccess) 
    {
        return true; //لو المستخدم مدير فل اكسيس بنعديه علطول 
    }

    if((CurrentUser.Permission & permissionUser) == permissionUser) // لو بيرمشن اليوزر 17 بيت وايس & 1 == 1
    {                                                       // طالما قيمه متساويه يبقي يوزر definition permission
        return true;
    }
    
    return false;
}

void performMainMenueOptions(enMainMenueOptions MainMenueOptions)
{
    switch (MainMenueOptions)
    {
    case enMainMenueOptions::eListClient:
    {
        system("cls");
        if(!checkAccessPermission(enPermissions::enShowClientList))
        {
            printAccessDenied();
            goBackToMainMenue();
            break;
        }
        showAllClientsScreen();
        goBackToMainMenue();
        break;
    }

    case enMainMenueOptions::eAddClient:
    {
        system("cls");
        if(!checkAccessPermission(enPermissions::enAddClient))
        {
            printAccessDenied();
            goBackToMainMenue();
            break;
        }
        showAddNewClientScreen();
        goBackToMainMenue();
        break;
    }

    case enMainMenueOptions::eDeleteClient:
    {
        system("cls");
        if(!checkAccessPermission(enPermissions::enDeleteClient))
        {
            printAccessDenied();
            goBackToMainMenue();
            break;
        }
        showDeleteClientScreen();
        goBackToMainMenue();
        break;
    }

    case enMainMenueOptions::eUpdateClient:
    {
        system("cls");
        if(!checkAccessPermission(enPermissions::enUpdateClient))
        {
            printAccessDenied();
            goBackToMainMenue();
            break;
        }
        showUpdateClientScreen();
        goBackToMainMenue();
        break;

    }

    case enMainMenueOptions::eFindClient:
    {
        system("cls");
        if(!checkAccessPermission(enPermissions::enFindClient))
        {
            printAccessDenied();
            goBackToMainMenue();
            break;
        }
        showFindClientScreen();
        goBackToMainMenue();
        break;

    }
    
    case enMainMenueOptions::eTransactions:
    {
        system("cls");
        if(!checkAccessPermission(enPermissions::enTransactions))
        {
            printAccessDenied();
            goBackToMainMenue();
            break;
        }
        showTransactionsMenue();
        goBackToMainMenue();
        break;
    }
    
    case enMainMenueOptions::eManageUsers:
    {
        system("cls");
        if(!checkAccessPermission(enPermissions::enManageUsers))
        {
            printAccessDenied();
            goBackToMainMenue();
            break;
        }
        showManageUsersMenue();
        goBackToMainMenue();
        break;
    }

    case enMainMenueOptions::eLogOut:
    {
        loginScreen();        
    }
    }

}
//mainMenue
void showMainMenue()
{



    system("cls");
    cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
    cout << "\t\tMain Menue Screen" << endl;
    cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
    cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";
    cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;

    performMainMenueOptions((enMainMenueOptions)readMainMenueOptions());
}

//login
void loginScreen()
{
    
    string UsrName = "";
    string Password = "";
    bool isFirstTry = true;

    do 
    {
        system("cls");

        cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;
        cout << "\tLogin Screen" << endl;
        cout << left << setfill('=') << setw(43) << "=" << setfill(' ') << endl;

        if(!isFirstTry)
        {
            cout << "\nInvalid Username/Password!";
        }
        
        cout << "\nEnter Username? ";
        getline(cin >> ws, UsrName);

        cout << "Enter Password? ";
        getline(cin >> ws, Password);

        isFirstTry = false;

    }while(!isUserExsits( UsrName, Password , FileUsersName , CurrentUser));

    showMainMenue();
}

int main()

{
    loginScreen();

    cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
	cin.get();											 // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}