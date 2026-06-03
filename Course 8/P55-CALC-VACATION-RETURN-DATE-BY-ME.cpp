#pragma warning(disable : 4996)
#include <iostream>
#include <string>
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

short DayOfWeekOrder(short Day , short Month , short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(sDate Date)
{
    return DayOfWeekOrder(Date.Day , Date.Month , Date.Year);
}

string DayShortOfWeek(short DayOfWeekOrder)
{
    string arrDaysNames[] = {"Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat"};

    return arrDaysNames[DayOfWeekOrder];
}




bool isLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short NumberOfDaysInAMonth(short Month , short Year)
{
    if(Month < 1 || Month > 12)
    {
        return 0;
    }

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month,
                                             Date.Year));
}

bool  IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}



sDate CalculateVacationReturnDate(sDate Date , short PeriodDays)
{

    short VacationDays = PeriodDays;

    while(VacationDays != 0)
    {
        if(DayOfWeekOrder(Date) <= 4)
        {
            VacationDays--;
        }

        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}


short readDay()
{
    cout << "\nPlease enter a Day? ";
    short Day;
    cin >> Day;

    return Day;
}

short readMonth()
{
    cout << "Please enter a Month? ";
    short Month;
    cin >>  Month;

    return Month;
}

short readYear()
{
    cout << "Please enter a Year? ";
    short Year;
    cin >> Year;

    return Year;
}

sDate readFullDate()
{
    sDate Date;
    Date.Day = readDay();
    Date.Month = readMonth();
    Date.Year = readYear();

    return Date;
}

short readVacationDays()
{
    cout << "\nPlease enter a Vacation days? ";
    short days;
    cin >> days;

    return days;
}

int main()
{
    cout << "\nVacation Starts:";
    sDate DateVacation = readFullDate();

    short VacationDays = readVacationDays();


    sDate DateEndVac = CalculateVacationReturnDate(DateVacation ,  VacationDays);

    cout << "\n\nReturn Date: " << DayShortOfWeek(DayOfWeekOrder(DateEndVac)) << " , "
    << DateEndVac.Day << "/" << DateEndVac.Month << "/" << DateEndVac.Year;


    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}