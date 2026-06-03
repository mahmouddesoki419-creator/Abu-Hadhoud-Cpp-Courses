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

short ReadDay()
{
    cout << "Please enter a Day? ";
    short Day;
    cin >> Day;

    return Day;
}

short dayOrderNumber(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayName(short dayNumber)
{
    string arrNamesDays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "sat"};
    return arrNamesDays[dayNumber];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    short order = dayOrderNumber(Day, Month, Year);

    cout << "\nDate     : " << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order: " << order;
    cout << "\nDay Name : " << DayName(order);

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}