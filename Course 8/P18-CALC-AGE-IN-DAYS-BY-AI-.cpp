#include <iostream>
#include <limits>

using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

bool isLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    short arrNumberDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberDays[Month - 1];
}

// دالة تحسب إجمالي عدد الأيام للتاريخ منذ عام 1 ميلادي
int GetTotalDaysFromYearOne(sDate Date)
{
    int TotalDays = 0;

    // 1. حساب أيام السنين السابقة بالكامل
    for (int y = 1; y < Date.Year; y++)
    {
        TotalDays += isLeapYear(y) ? 366 : 365;
    }

    // 2. إضافة أيام الشهور الممرورة في السنة الحالية
    for (int m = 1; m < Date.Month; m++)
    {
        TotalDays += NumberOfDaysInMonth(m, Date.Year);
    }

    // 3. إضافة أيام الشهر الحالي
    TotalDays += Date.Day;

    return TotalDays;
}

// الدالة الجديدة لحساب العمر بدقة
int CalculateAgeInDays(sDate DateOfBirth)
{
    sDate CurrentDate = {27, 5, 2026}; // تاريخ اليوم الحالي

    int BirthDateDays = GetTotalDaysFromYearOne(DateOfBirth);
    int CurrentDateDays = GetTotalDaysFromYearOne(CurrentDate);

    // الفارق بين الإجماليين يعطيك العمر باليوم بدقة متناهية
    return CurrentDateDays - BirthDateDays;
}

short readDay()
{
    cout << "Please enter a Day? ";
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
    cout << "\nPlease Enter Your Date Of Birth:\n\n";
    sDate Date1 = readFullDate();

    cout << "\n\nYour Age is: " << CalculateAgeInDays(Date1) << " Day(s)\n";

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}