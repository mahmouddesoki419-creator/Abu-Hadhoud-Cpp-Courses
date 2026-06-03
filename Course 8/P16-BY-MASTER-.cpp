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

short isLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short NumberOfDaysInMonth(short  Month , short Year)
{
    if(Month < 1 || Month > 12)
    {
        return 0;
    }

    if(Month == 2)
    {
        return isLeapYear(Year) ? 29 : 28;
    }

    short arr31Days[7] = {1 , 3 , 5 , 7 , 8 , 10 , 12};
    
    for(short i = 0; i < 7; i++)
    {
        if(Month == arr31Days[i])
        {
            return 31;
        }
    }
    return 30;
}

bool isLastDayInMonth(sDate Date1)
{
    return (Date1.Day == NumberOfDaysInMonth(Date1.Month , Date1.Year));
}

bool isLastMonthInYear(short Month)
{
    return Month == 12;
}

sDate increaseDateByOneDay(sDate Date1)
{
    if(isLastDayInMonth(Date1))
    {
        if(isLastMonthInYear(Date1.Month))
        {
            Date1.Day = 1;
            Date1.Month = 1;
            Date1.Year++;
        }
        else 
        {
            Date1.Day = 1;
            Date1.Month++;
        }

    }
    else 
    {
        Date1.Day++;
    }

    return Date1;
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
    cin >> Month;

    return Month;
}

short readYear()
{
    cout << "Please enter a Year? ";
    short Year;
    cin >> Year;

    return Year;
}

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = readDay();
    Date.Month = readMonth();
    Date.Year = readYear();

    return Date;
}


int main()
{
    sDate Date1 = ReadFullDate();

    Date1 = increaseDateByOneDay(Date1);

    cout << "\n\nDate after adding one day is: ";
    cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}