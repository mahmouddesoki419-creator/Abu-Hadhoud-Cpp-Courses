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

short NumberOfDaysInMonth(short Year , short Month)
{
    if(Month < 1 || Month > 12)   
    {
        
        return 0;
    }

    int arrNumberDays[12] = {31, 28, 31 , 30, 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
    
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberDays[Month - 1];
}


int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days       In Month[" << Month << "] is " << NumberOfDaysInMonth(Year , Month);
    


    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}