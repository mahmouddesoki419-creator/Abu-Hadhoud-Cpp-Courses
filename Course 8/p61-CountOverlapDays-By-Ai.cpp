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



short isLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    if (Month == 2)
    {
        return isLeapYear(Year) ? 29 : 28;
    }

    short arr31Days[7] = {1, 3, 5, 7, 8, 10, 12};

    for (short i = 0; i < 7; i++)
    {
        if (Month == arr31Days[i])
        {
            return 31;
        }
    }
    return 30;
}

bool isLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool isLastMonthInYear(short Month)
{
    return Month == 12;
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
    if(IsDate1BeforeDate2(Date1 , Date2)) return enDateCompare:: Before;
    if(isDate1EqualDate2(Date1 , Date2)) return enDateCompare:: Equal;

    return enDateCompare:: After;
}


bool IsOverlapPeriods(sDate Date1Start, sDate Date1End , sDate Date2Start , sDate Date2End)
{
    if(CompareDates(Date1End , Date2Start) == enDateCompare::Before) return false;
    if(CompareDates(Date2End , Date1Start) == enDateCompare::Before) return false;

    else return true;
}

bool isDateWithinInPeriod(stPeriod period , sDate Date)
{
    // using reverse logic // Reverse Negation
    return !(CompareDates(Date , period.StartDate) == enDateCompare ::Before

        || 

            CompareDates(Date , period.EndDate) == enDateCompare :: After);


// المنطق المباشر باستخدام && (بدون نفي)
/*/return (CompareDates(Date, period.StartDate) != enDateCompare::Before 
     && CompareDates(Date, period.EndDate) != enDateCompare::After);/*/
}



sDate GetMaxDate(sDate Date1 , sDate Date2)
{
    return (CompareDates(Date1 , Date2) == enDateCompare::After) ? Date1 : Date2;
}

sDate GetMinDate(sDate Date1 , sDate Date2)
{
    return (CompareDates(Date1 , Date2) == enDateCompare::Before) ? Date1 : Date2;
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

int overLapDaysCount(stPeriod Period1 , stPeriod Period2)
{
    if(!IsOverlapPeriods(Period1.StartDate , Period1.EndDate , Period2.StartDate , Period2.EndDate))
    {
        return 0;
    }

    sDate OverlapStartDate = GetMaxDate(Period1.StartDate , Period2.StartDate);
    sDate OverLapEndDate = GetMinDate(Period1.EndDate , Period2.EndDate); 

    return GetDifferenceInDays(OverlapStartDate , OverLapEndDate , true);
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

    cout << "\n\nOverlap Days Count Is: " << overLapDaysCount(Period1 , Period2);


    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}