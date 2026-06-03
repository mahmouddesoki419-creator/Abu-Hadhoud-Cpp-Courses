
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



sDate decreaseDateByOneDay(sDate Date)
{
    if(Date.Day == 1)
    {
        if(Date.Month == 1)
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Month , Date.Year);
        }
    }
    else 
    {
        Date.Day--;
    }

    return Date;
}

sDate decreaseDateByXDays( short days , sDate Date)// وعادي لو مشيت بفور لوب عكسها تبدا من 1 لو للرقم 
{
    for(int i = days; i >= 1; i--)
    {
        Date = decreaseDateByOneDay(Date);
    }

    return Date;
}

sDate decreaseDateByOneWeek(sDate Date)
{
    for(int i = 7; i >= 1; i--)
    {
        Date = decreaseDateByOneDay(Date);
    }

    return Date;
}

sDate decreaseDateByXWeeks(short Weeks , sDate Date)
{
    for(int i = Weeks; i >= 1; i--)
    {
        Date = decreaseDateByOneWeek(Date);
    }

    return Date;
}

sDate decreaseDateByOneMonth(sDate Date)
{
    if(Date.Month == 1)
    { 
        Date.Month = 12;
        Date.Year--;
    }
    else 
    {
        Date.Month--;
    }
    /*/last check day in date should not exceed min days in the
    current month
    example if date is 31/5/2022 decreasing one month should
    not be 31/4/2022, it should
    be 30/4/2022/*/
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month , Date.Year);

    if(Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    
    return Date;
}

sDate decreaseDateByXMonths(short Months , sDate Date)
{
    for(int i = Months; i >= 1; i--)
    {
        Date = decreaseDateByOneMonth(Date);
    }

    return Date;
}

sDate decreaseDateByOneYear(sDate Date)
{
    Date.Year--;
    if(Date.Month == 2)
    {
        short NumberOfDays = NumberOfDaysInMonth(Date.Month , Date.Year);
        Date.Day = Date.Day > NumberOfDays ? NumberOfDays : Date.Day;
    }

    return Date; 
}

sDate decreaseDateByXYears(short Years, sDate Date)
{
    for(int i = Years; i >= 1; i--)
    {
        Date = decreaseDateByOneYear(Date);
    }

    return Date;
}

sDate decreaseDateByXYearsFaster(short Years , sDate Date)
{
    Date.Year -= Years;
    if(Date.Month == 2)
    {
        short NumberOfDays = NumberOfDaysInMonth(Date.Month , Date.Year);
        Date.Day = Date.Day > NumberOfDays ? NumberOfDays : Date.Day;
    }

    return  Date;
}

sDate decreaseDateByOneDecade(sDate Date)
{
    Date.Year -= 10;
    if(Date.Month == 2)
    {
        short NumberOfDays = NumberOfDaysInMonth(Date.Month , Date.Year);
        Date.Day = Date.Day > NumberOfDays ? NumberOfDays : Date.Day;
    }

    return Date;
}

sDate decreaseDateByXDecades(short Decades , sDate Date)// 10
{
    for(int i = Decades * 10 ; i >= 1; i--)
    {
        Date = decreaseDateByOneYear(Date);
    }

    return Date; 
}

sDate decreaseDateByXDecadesFaster(short Decades , sDate Date)
{
    Date.Year -= Decades * 10;
    if(Date.Month == 2)
    {
        short NumberOfDays = NumberOfDaysInMonth(Date.Month , Date.Year);
        Date.Day = Date.Day > NumberOfDays ? NumberOfDays : Date.Day;
    }

    return Date;
}

sDate decreaseDateByOneCentury(sDate Date)
{
    Date.Year -= 100;
    if(Date.Month == 2)
    {
        short NumberOfDays = NumberOfDaysInMonth(Date.Month , Date.Year);
        Date.Day = Date.Day > NumberOfDays ? NumberOfDays : Date.Day;
    }

    return Date;
}

sDate decreaseDateByOneMillennium( sDate Date)
{
    Date.Year -= 1000;
    if(Date.Month == 2)
    {
        short NumberOfDays = NumberOfDaysInMonth(Date.Month , Date.Year);
        Date.Day = Date.Day > NumberOfDays ? NumberOfDays : Date.Day;
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


int main()
{
    sDate Date1 = readFullDate();

    cout << "\nDate After: \n";
    
    Date1 = decreaseDateByOneDay(Date1);
    cout << "\n01- Subtructing one day is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByXDays(10 , Date1);
    cout << "\n02- Subtructing 10 days is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByOneWeek(Date1);
    cout << "\n03- Subtructing One week is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = decreaseDateByXWeeks(10 , Date1);
    cout << "\n04- Subtructing 10 weeks is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByOneMonth(Date1);
    cout << "\n05- Subtructing One month is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByXMonths(5 , Date1);
    cout << "\n06- Subtructing 5 months is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByOneYear(Date1);
    cout << "\n07- Subtructing One year is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByXYears(10 , Date1);
    cout << "\n08- Subtructing 10 years is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByXYearsFaster(10 , Date1);
    cout << "\n09- Subtructing 10 years (Faster) is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByOneDecade(Date1);
    cout << "\n10- Subtructing One Decade is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByXDecades(10 , Date1);
    cout << "\n11- Subtructing 10 Decades is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByXDecadesFaster(10 , Date1);
    cout << "\n12- Subtructing 10 Decades (Faster) is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByOneCentury(Date1);
    cout << "\n13- Subtructing One Century is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = decreaseDateByOneMillennium(Date1);
    cout << "\n14- Subtructing One Millennium is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;








    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}