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

struct stPeriod
{
    sDate StartDate;
    sDate EndDate;
};

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? 
        true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool isDate1EqualDate2(sDate Date1 , sDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == 
        Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool isDate1AfterDate2(sDate Date1 , sDate Date2)
{
    return (!IsDate1BeforeDate2(Date1 , Date2) && !isDate1EqualDate2(Date1 , Date2));
}


enum enDateCompare{ Before = -1 , Equal = 0 , After = 1 };

enDateCompare CompareDates(sDate Date1 , sDate Date2)
{
    if(IsDate1BeforeDate2(Date1 , Date2)) return enDateCompare::Before;
    if(isDate1EqualDate2(Date1 , Date2)) return enDateCompare::Equal;
    
    return enDateCompare::After;
}


bool isOverlapPeriods(stPeriod Period1 , stPeriod Period2)
{
    if(CompareDates(Period2.EndDate , Period1.StartDate) == enDateCompare::Before
    ||CompareDates(Period2.StartDate , Period1.EndDate) == enDateCompare::After)
        return false;
    else 
        return true;
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

stPeriod readPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = readFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = readFullDate();
    
    return Period;
}


int main()
{
    cout << "\nEnter Period 1:";
    stPeriod Period1 = readPeriod();
    cout << "\nEnter Period 2:";
    stPeriod Period2 = readPeriod();


    if(isOverlapPeriods(Period1 , Period2)) 
        cout << "\n\nYes, periods Overlap.";
    else 
        cout << "\n\nNo, Periods Not Overlap.";


    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}