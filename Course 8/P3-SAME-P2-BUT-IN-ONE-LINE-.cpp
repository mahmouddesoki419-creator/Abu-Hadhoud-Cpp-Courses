#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

short ReadYear()
{
    cout << "Write A year to cheack Leap Year or Not: ";
    short year;
    cin >> year;

    return year;
}

bool IsLeapYear(short Year)
{
   return ((Year % 4  == 0 && Year % 100 != 0) || (Year % 400 == 0));      
}

int main()
{
    short Year = ReadYear();
    if(IsLeapYear(Year))
        cout << "\nYes, Year [" << Year << "] is a Leap Year.\n";
    else 
        cout << "\nNo, Year [" << Year << "] is Not a Leap Year.\n";


    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}