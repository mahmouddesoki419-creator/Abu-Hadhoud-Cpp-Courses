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


short numberOfDaysInMonth(short Month , short Year)// عدد ايام الشهر 30 او 31 او=> 28و29 لفبراير
{
    short arrNumberDays[12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberDays[Month];//4
}

short dayorderNumber(short Day , short Month , short Year)// return number day 0 to 6 // sun = 0 , mon = 1 ect..
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

void printMonthCalender(short Month , short Year)
{
    if(Month < 1 || Month > 12)
    {
        return ;
    }

    string arrMonths[] = { "" , "Jan" , "feb" , "Mar" , "Apr" , "May" , "Jun" ,
         "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec"};
    
    cout << endl << left << setfill('_') << setw(20) << "_" << setfill(' ') 
    << arrMonths[Month] << setfill('_') << setw(23) << "_" << setfill(' ') << endl ;

    cout << endl << left << setw(7) << "Sun";
    cout << left << setw(7) << "Mon";
    cout << left << setw(7) << "Tue";
    cout << left << setw(7) << "Wed";
    cout << left << setw(7) << "Thu";
    cout << left << setw(7) << "Fri";
    cout << left << setw(5) << "Sat";

    short Day = 1;
    short OrderNumberDaysInMonth = numberOfDaysInMonth(Month , Year);
    short dayOrder = dayorderNumber(Day , Month , Year);// number day sun = 0 , mon = 1 ect...

    cout << endl;
    for(short i = 1; i <= OrderNumberDaysInMonth; i++)
    {
        cout << right << setw((7 * dayOrder) + 2) << i;// 2022 / 9 == 35 is be left thu || so to be right we do+2
    }
    /*/cout << "\n\n";
    cout << dayOrder;/*/
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    printMonthCalender(Month , Year);

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}