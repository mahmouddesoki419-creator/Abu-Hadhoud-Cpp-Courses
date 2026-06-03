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
    return ((Year % 4 == 0  && Year % 100 != 0) || (Year % 400 == 0));
}

short NumberOfDaysInMonth(short Month , short Year)
{
    if(Month < 1 || Month > 12)// هنا مهمه عشان تمنع لو اتبعت شهر 12 اتولد فيه
    {
        return 0;
    }

    short arrNumberDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberDays[Month - 1];
}

bool isLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool isLastMonthInYear(short Month)
{
    return Month == 12;
}

bool IsDate1BeforeDate2(sDate Date1 , sDate Date2)// هل التاريخ الاول يسبق التاريخ الثاني ؟
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
    Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
    Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

sDate increaseDateByOneDay(sDate Date)
{
    if (isLastDayInMonth(Date))
    {
        if (isLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
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

int GetDifferenceInDays(sDate Date1, sDate Date2 , bool IncludeEndDay = false)
{
    int Days = 0;

    while(IsDate1BeforeDate2(Date1 , Date2))
    {
        Days++;
        Date1 = increaseDateByOneDay(Date1);// الفاكشن ال بتزود  يوم وتعدل بالنتيجه 31-12-1999 // 1 - 1 - 2000
    }

    return IncludeEndDay ? ++Days : Days;
}



short readDay()
{
    cout << "Please enter a Day? ";
    short Day;
    cin >> Day;

    return Day;
}

short readMonth()
{
    cout << "Please enter a Month? ";
    short Month;
    cin >> Month;

    return Month;
}

short readYear()
{
    cout << "please enter a Year? ";
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

sDate GetSystemDate()//30 - 5 - 2026 // current Date
{
    sDate Date;

    time_t t = time(0);// get time now
    tm* now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1; 
    Date.Day = now->tm_mday;  
    
    return Date;
}


int main()
{
    cout << "\nPlease Enter Your Date Of Birth:\n\n";
    sDate Date1 = readFullDate();
    sDate Date2 = GetSystemDate();


    cout << "\n\nYour Age is: " << GetDifferenceInDays(Date1 , Date2 , true) << " Day(s)";



    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}