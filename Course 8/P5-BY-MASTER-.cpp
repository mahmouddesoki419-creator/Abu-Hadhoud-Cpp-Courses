#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

bool isLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0 )||(Year % 400 == 0));
}

short ReadYear()
{
    cout << "Please enter a year to check? ";
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

short NumberOfDaysInMonth(short Year , short Month)
{
    if(Month < 1 || Month > 12)
        return 0;

    if(Month == 2)
    {
        return isLeapYear(Year) ? 29 : 28;
    }

    short arr31Days[7] = {1 , 3 , 5 , 7 , 8 , 10 , 12};

    for(short i = 1; i <= 7; i++)
    {
        if(Month == arr[i - 1])
        {
            return 31;
        }
    }
    //if you reach then its 30 days.
    return 30;
}

short NumberOfHoursInMonth(short Year , short Month)
{
    return (NumberOfDaysInMonth(Year , Month)) * 24;
}

int NumberMinutesInMonth(short Year , short Month)
{
    return (NumberOfHoursInMonth(Year , Month)) * 60;
}

int NumberOfSecondsInmonth(short Year , short Month)
{
    return (NumberMinutesInMonth(Year , Month)) * 60;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days       In Month[" << Month << "] is " << NumberOfDaysInMonth(Year , Month);
    cout << "\nNumber of Hours      In Month[" << Month << "] is " << NumberOfHoursInMonth(Year , Month);
    cout << "\nNumber of Minutes    In Month[" << Month << "] is " << NumberMinutesInMonth(Year , Month);
    cout << "\nNumber of Seconds    In Month[" << Month << "] is " << NumberOfSecondsInmonth(Year , Month);
    


    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}