#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

bool isLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short numberOfDaysInMonth(short Month, short Year) // عدد ايام الشهر 30 او 31 او=> 28و29 لفبراير
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    short arrNumberDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberDays[Month - 1]; // 4
}

short numberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (int i = 1; i < Month; i++)
    {
        TotalDays += numberOfDaysInMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}

struct sData
{
    short Day;
    short Month;
    short Year;
};

sData GetDataFromDayOrderInYear(short TotalDays, short Year)
{
    sData Data;
    short RemainingDays = TotalDays;
    short MonthDays = 0;

    Data.Year = Year;
    Data.Month = 1;

    while(true)//هنا الشرط ايفضل شغال لحد ما يخش في else ويعطي بريك
    {
        MonthDays = numberOfDaysInMonth(Data.Month , Year);//73//=== month1 = 73 - 31 = 42/m2/ 42 - 28 = 14// m3/ 14 

        if(RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Data.Month++;
        }
        else 
        {
            Data.Day = RemainingDays;
            break;
        }
    }

    return Data;
}

short ReadDay()
{
    cout << "Please enter a Day? ";
    short Day;
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    cout << "Please enter a month? ";
    short Month;
    cin >> Month;
    return Month;
}

short ReadYear()
{
    cout << "Please enter a year to check? ";
    short year;
    cin >> year;

    return year;
}


int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    short TotalDays = numberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
    cout << "\nNumber of Days from the begining of the year is " << TotalDays;

    sData Data;
    Data = GetDataFromDayOrderInYear(TotalDays , Year);
    cout << "\n\nData for [" << TotalDays << "] is: ";
    cout << Data.Day << "/" << Data.Month << "/" << Data.Year;

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}