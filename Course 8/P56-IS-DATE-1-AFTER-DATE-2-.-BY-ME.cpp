#pragma warning(disable : 4996)
#include <iostream>
#include <string>
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


bool isDate1AfterDate2(sDate Date1 , sDate Date2)
{
    // 1. المقارنة بالسنوات أولاً
    if(Date1.Year > Date2.Year) return true;
    if(Date1.Year < Date1.Year) return false;

    // 2. إذا تساوت السنوات، نقارن بالشهور
    if(Date1.Month > Date2.Month) return true;
    if(Date1.Month < Date2.Month) return false;

    // 3. إذا تساوت الشهور أيضاً، الفيصل هو الأيام
    return Date1.Day > Date2.Day;
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
    cin >>  Month;

    return Month;
}

short readYear()
{
    cout << "Please enter a Year? ";
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
    cout << "\nEnter Date1:";
    sDate Date1 = readFullDate();
    cout << "\nEnter Date2:";
    sDate Date2 = readFullDate();
    
    if(isDate1AfterDate2(Date1 , Date2))
        cout << "\n\nYes, Date1 is After Date2";
    else 
        cout << "\n\nNo, Date1 Not After Date2";


    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}