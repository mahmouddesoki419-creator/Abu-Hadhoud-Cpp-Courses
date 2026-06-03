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

short CalculateDifferenceBetweenDate1AndDate2(sDate Date1, sDate Date2)
{

    if (Date1.Year == Date2.Year)
    {
        if (Date1.Month == Date2.Month)
        {
            return Date2.Day - Date1.Day;
        }
    }

    short DiffDays = 0;
    if (Date1.Year == Date2.Year)
    {
        if (Date1.Month < Date2.Month) // 10 - 1 - 2000  /// 25 - 3 - 2000// 3 = 31 , 2 = 29 , 1 = 31
        {
            DiffDays += NumberOfDaysInMonth(Date1.Month, Date1.Year) - Date1.Day;

            for (short i = Date1.Month + 1; i < Date2.Month; i++)
            {
                DiffDays += NumberOfDaysInMonth(i , Date2.Year);
            }

            return DiffDays + Date2.Day;
        }
    }


    DiffDays = 0;
    DiffDays += NumberOfDaysInMonth(Date1.Month, Date1.Year) - Date1.Day;

    for (short m = Date1.Month + 1; m <= 12; m++)
    {
        DiffDays += NumberOfDaysInMonth(m, Date1.Year);
    }


    for (short y = Date1.Year + 1; y < Date2.Year; y++) // 28 - 4 - 2000 //   14 - 8 - 2002
    {
        if (isLeapYear(y))
        {
            DiffDays += 366;
        }
        else
        {
            DiffDays += 365;
        }
    }

    for (short m = 1; m < Date2.Month; m++)
    {
        DiffDays += NumberOfDaysInMonth(m, Date2.Year);
    }

    DiffDays += Date2.Day;

    return DiffDays;
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
    sDate Date2 = ReadFullDate();

    short diffDays = CalculateDifferenceBetweenDate1AndDate2(Date1, Date2);

    cout << "\n\nDifference is: " << diffDays;
    cout << "\nDifference (Including End Day) is: " << diffDays + 1;

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}