#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

short ReadYear()
{
    cout << "Please Enter a year to check? ";
    short year;
    cin >> year;

    return year;
}

bool IsLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0 )||(Year % 400 == 0));
}

short NumberDaysOfYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInYear(short Year)
{
    return NumberDaysOfYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year)
{
    return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year)  
{
    return NumberOfMinutesInYear(Year) * 60;
}


int main()
{
    short Year = ReadYear();

    cout << "\nNumber of Days      in Year[" << Year << "] is " << NumberDaysOfYear(Year);
    cout << "\nNumber of Hours     in year [" << Year << "] is " << NumberOfHoursInYear(Year);
    cout << "\nNumber of Minutes   in year [" << Year << "] is " <<  NumberOfMinutesInYear(Year);
    cout << "\nNumber of Seconds   in year [" << Year << "] is " <<NumberOfSecondsInYear(Year); 


    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}