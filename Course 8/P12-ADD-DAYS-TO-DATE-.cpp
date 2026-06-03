#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

bool isLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short NumberOfDaysInAMonth(short Month, short Year) // عدد ايام الشهر 30 او 31 او=> 28و29 لفبراير
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    short arrNumberDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberDays[Month - 1]; // 4
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)// بيرجع عددالايام من اول السنه
{
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}



sDate DateAddDays(short Days, sDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day , Date.Month , Date.Year);
    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else// الايام متبقيه عدد الشهر او اصغر تبقي دي الايام 
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
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

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

short ReadAddDays()
{
    cout << "How Many Days to add? ";
    int Add;
    cin >> Add;

    return Add;
}

int main()
{
    sDate Date = ReadFullDate();
    short Days = ReadAddDays();

    Date = DateAddDays(Days, Date);
    cout << "\n\nDate After adding [" << Days << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}