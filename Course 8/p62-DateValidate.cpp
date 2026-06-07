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


bool isDateValidate(sDate Date)
{
    if(Date.Year < 1) return false;
    if(Date.Month > 12) return false;
    if(Date.Day <= numberOfDaysInMonth(Date.Month , Date.Year)) return true;
    return false;
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

int main()
{
    sDate Date1 = readFullDate();

    if(isDateValidate(Date1))
        cout << "\nYes, Date is a Validate.";
    else 
        cout << "\nNo, Date is a Not Validate.";



    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}