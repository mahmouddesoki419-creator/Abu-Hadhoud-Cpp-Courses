
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



sDate increaseDateByOneDay(sDate Date)
{
    if(isLastDayInMonth(Date))
    {
        if(isLastMonthInYear(Date.Month))
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

sDate increaseDateByXDays(sDate Date , short Days)
{
    for(int i = 1; i <= Days; i++)
    {
        Date = increaseDateByOneDay(Date);
    }

    return Date;
}

sDate increaseDateByOneWeek(sDate Date)
{
    for(int i = 1; i <= 7; i++)
    {
        Date = increaseDateByOneDay(Date);
    }

    return Date;
}

sDate increaseDateByXWeeks(sDate Date , short Weeks)
{
    for(int i = 1; i <= Weeks; i++)
    {
        Date = increaseDateByOneWeek(Date);
    }

    return Date;
}

sDate increaseDateByOneMonth(sDate Date)
{
    if(Date.Month == 12)
    {
        Date.Month == 1;
        Date.Year++;
    }
    else 
    {
        Date.Month++;
    }
    /*/last check day in date should not exceed max days in the
    current month
    example if date is 31/1/2022 increasing one month should
    not be 31/2/2022, it should
    be 28/2/2022/*/
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month , Date.Year);

    if( Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

sDate increaseDateByFiveMonths(sDate Date , short Months)
{
    for(int i = 1; i <= Months; i++)
    {
        Date = increaseDateByOneMonth(Date);
    }

    return Date;
}

sDate increaseDateByOneYear(sDate Date)
{
    Date.Year++;// 29 - 2 - 2000 //
    return Date;
}

sDate increaseDateByXYears(sDate Date , short Years)
{
    for(int i = 1; i <= Years; i++)
    {
        Date = increaseDateByOneYear(Date);
    }

    return Date;
}

sDate increaseDateByXYearsFaster(sDate Date , short Years)
{
    Date.Year += Years;
    return Date;
}

sDate increaseDateByOneDecade(sDate Date)
{
    Date.Year += 10;
    return Date;
}

sDate increaseDateByXDecades(sDate Date , short Decade)
{
    for(int i = 1; i <= Decade * 10; i++)
    {
        Date = increaseDateByOneYear(Date);
    }

    return Date;
}

sDate increaseDateByXDecadesFaster(sDate Date , short Decade)
{
    Date.Year += Decade * 10;
    return Date;
}

sDate increaseDateByOneCentury(sDate Date)
{
    Date.Year += 100;
    return Date;
}

sDate increaseDateByOneMillennium(sDate Date)
{
    Date.Year += 1000;
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
    
    Date1 = increaseDateByOneDay(Date1);
    cout << "\n01- Adding one day is: " 
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = increaseDateByXDays(Date1 , 10);
    cout << "\n02- Adding 10 days is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = increaseDateByOneWeek(Date1);
    cout << "\n03- Adding One Week is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
       
    Date1 = increaseDateByXWeeks(Date1 , 10);
    cout << "\n04- Adding 10 Weeks is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = increaseDateByOneMonth(Date1);
    cout << "\n05- Adding One Month is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 

    Date1 = increaseDateByFiveMonths(Date1 , 5);
    cout << "\n06- Adding 5 Months is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = increaseDateByOneYear(Date1);
    cout << "\n07- Adding One Year is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = increaseDateByXYears(Date1 , 10);
    cout << "\n08- Adding 10 Years is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = increaseDateByXYearsFaster(Date1 , 10);
    cout << "\n09- Adding 10 Years (Faster) is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = increaseDateByOneDecade(Date1);
    cout << "\n10- Adding One Decade is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = increaseDateByXDecades(Date1 , 10);
    cout << "\n11- Adding 10 Decades is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = increaseDateByXDecades(Date1 , 10);
    cout << "\n12- Adding 10 Decades (Faster) is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = increaseDateByOneCentury(Date1);
    cout << "\n13- Adding One Century is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = increaseDateByOneMillennium(Date1);
    cout << "\n14- Adding One Millennium is: "
    << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;



    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}