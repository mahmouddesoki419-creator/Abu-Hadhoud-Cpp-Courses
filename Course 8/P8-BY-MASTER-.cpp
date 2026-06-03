#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

bool isLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short numberOfDaysInMonth(short Month, short Year) // عدد ايام الشهر 30 او 31 او=> 28و29 لفبراير
{
    if(Month < 1 || Month > 12)
    {
        return 0;
    }

    short arrNumberDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberDays[Month - 1]; // 4
}

short DayOfWeekOrder(short Day, short Month, short Year) // return number day 0 to 6 // sun = 0 , mon = 1 ect..
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string MonthShortName(short MonthNumber)
{
    string arrMonths[12] = {"Jan", "feb", "Mar",
                            "Apr", "May", "Jun",
                            "Jul", "Aug", "Sep",
                            "Oct", "Nov", "Dec"};

    return arrMonths[MonthNumber - 1];
}

void printMonthCalender(short Month, short Year)
{
    int NumberOfDays;

    // Index of the day from 0 to 6
    int current = DayOfWeekOrder(1, Month, Year);
    NumberOfDays = numberOfDaysInMonth(Month, Year);

    // print the current Month name
    printf("\n  ___________________%s__________________\n\n",
           MonthShortName(Month).c_str());

    //print the columns
    printf("  Sun  Mon  tue  Wed  Thu  Fri  Sat\n");

    // print approprite spaces
    int i; 
    for(i = 0; i < current; i++)// طالما عرفت i مش انحط فاريبال 
        printf("     ");

    for(int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d" , j);//زي ال setw(5)

        if(++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    cout << "\n __________________________________________\n\n";
}

short ReadYear()
{
    cout << "\nPlease enter a year to check? ";
    short year;
    cin >> year;

    return year;
}

short ReadMonth()
{
    short Month;
    cout << "Please enter a Month to check? ";
    cin >> Month;
    return Month;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    printMonthCalender(Month, Year);

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}