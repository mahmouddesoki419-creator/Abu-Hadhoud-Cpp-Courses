#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include <limits>

using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

string ReadDateString(string Message)
{
    cout << Message;

    string DateString;
    getline(cin >> ws, DateString);

    return DateString;
}

vector<string> splitString(string DateString , string Delim)//====>  31 / 3 / 2026
{
    vector<string> vDate;

    short pos = 0;
    string sWord;

    //use find() function to get the position of the delimiters
    while((pos = DateString.find(Delim)) != std::string::npos)
    {
        sWord = DateString.substr(0 , pos);//store the word
        if(sWord != "")
        {
            vDate.push_back(sWord);
        }

        DateString.erase(0 , pos + Delim.length());
    }

    if(DateString != "")
    {
        vDate.push_back(DateString);
    }

    return vDate;
}

sDate StringToDate(string DateString)//====>  31 / 3 / 2026
{
    sDate Date;
    vector<string> vDate = splitString(DateString , "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DateToString(sDate Date)
{
    return (to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year));
}


int main()
{
    string DateString = ReadDateString("Please Enter Date dd/mm/yyyy? ");

    sDate Date = StringToDate(DateString);

    cout << "\nDay: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;
    
    cout << "\nYou Entered: " << DateToString(Date);

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}