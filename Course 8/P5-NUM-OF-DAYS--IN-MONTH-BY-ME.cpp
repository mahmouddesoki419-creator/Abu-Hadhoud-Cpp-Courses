#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

bool IsLeapYear(short Year)
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
    do 
    {
        cout << "Please enter a Month to check? ";
        cin >> Month;
    }while(Month > 12 || Month < 1);

    return Month;
}

short NumberOfDaysInMonth(short Year , short Month)
{

    switch (Month)
    {
    case 1:
        return 31;
    case 2: 
        return (IsLeapYear(Year)) ? 29 : 28;
    case 3: 
        return 31;
    case 4:
        return 30;
    case 5: 
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8: 
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    }
    return 31;
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