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

bool isLastDay(sDate Date)
{
    if(Date.Day == NumberOfDaysInMonth(Date.Month , Date.Year))
    {
        return true;
    }

    return false;
}

bool isLastMonth(short month)
{
    return (month == 12);
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

    if(isLastDay(Date1))
        cout << "\nYes, Day is last Day in month.";
    else 
        cout << "\nNO, Day is Not last Day in month.";


    if(isLastMonth(Date1.Month))
        cout << "\nYes, month is last Month in Year.\n\n";
    else 
        cout << "\nNo, month Not last Month in Year.\n\n";

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}