#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
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

short NumbersDaysInMonth(short Month , short Year)
{
    if(Month > 12 || Month < 1)
    {
        return 0;
    }

    short arrNumberDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

    return Month == 2 ? (isLeapYear(Year) ? 29 : 28) : arrNumberDays[Month - 1]; 
}



bool isEndOfWeek(string NameDayWeek)
{
    cout << "\nIs it End of Week? ";
    if(NameDayWeek == "Sat")
    {
        cout << "\nYes end of week.";
        return true;
    }
    else 
        cout << "\nNo not end of week.";

    return false;
}

bool isWeeknd()
{
    time_t t = time(0);
    tm* now = localtime(&t);

    cout << "\n\nIs it Weekend?";
    if(now->tm_wday == 5 || now->tm_wday == 6)
    {
        cout << "\nYes it is a Week end.";
        return true;
    }
    else 
    {
        cout << "\nNo it is Not a Week end.";
    }

    return false;
}

bool isBusinessDay()
{
    time_t t = time(0);
    tm* now = localtime(&t);

    cout << "\n\nIs it Business Day? ";
    if(now->tm_wday == 5 || now->tm_wday == 6)
    {
        cout << "\nNot it is Not a business day.";
        return false;
    }
    else 
    {
        cout << "\nYes it is a business day.";
    }

    return true;
}



short daysUntilEndOfWeek()
{
    time_t t = time(0);
    tm* now = localtime(&t);

    return 6 - now->tm_wday;
}

short daysUntilEndOfMonth(sDate Date)
{
    return NumbersDaysInMonth(Date.Month , Date.Year) - Date.Day;
}

short daysUntilEndOfYear(sDate Date)
{
    short DaysDiff = 0;

    if(isLeapYear(Date.Year))
    {
        DaysDiff = 366;
    }
    else
    {
        DaysDiff = 365;
    }

    for(int i = 1; i < Date.Month; i++)
    {
        DaysDiff -= NumbersDaysInMonth(i , Date.Year);
    }

    DaysDiff -= Date.Day;
    
    return DaysDiff;
}



sDate GetSystemDate()//31 - 5 - 2026
{
    sDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    
    return Date;
}

string OverLoadTheDayOfWeekOrder()
{
    time_t t = time(0);
    tm* now = localtime(&t);

    switch (now->tm_wday)
    {
    case 0:
        return "Sun";
    case 1:
        return "Mon";
    case 2:
        return "Tue";
    case 3:
        return "Wen";
    case 4:
        return "Thr";
    case 5:
        return "Fri";    
    }

    return "Sat";
}

int main()
{
    sDate Date;
    Date = GetSystemDate();
    string NameDayWeek = OverLoadTheDayOfWeekOrder();

    cout << "Today is " << NameDayWeek << " , "
    << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    isEndOfWeek(NameDayWeek);
    isWeeknd();
    isBusinessDay();

    cout << "\n\nDays Until end of week : " << daysUntilEndOfWeek() << " Day(s)" << endl;
    cout << "Days Until end of month : " << daysUntilEndOfMonth(Date) << " Day(s)" << endl;
    cout << "Days Until end of Year : " << daysUntilEndOfYear(Date) << " Day(s)" << endl;
    

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}