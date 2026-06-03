#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

string NumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }

    if (Number >= 1 && Number <= 19) // 11
    {
        string arr[] = {"",
                        "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        return arr[Number] + " ";
    }

    if (Number >= 20 && Number <= 99)//77
    {
        string arr[] = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
             return arr[Number / 10] + " " + NumberToText(Number % 10);//4
    }

    if(Number >= 100 && Number <= 199)//154
    {
        return "One Hundred " + NumberToText(Number % 100);//كدا هنا الريجيرشن رجع 54 fifty from tens || four from ones
    }

    if(Number >= 200 && Number <= 999)//896
    {
        return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100); // 96 
    }

    if(Number >= 1000 && Number <= 1999)//1309
    {
        return  "One Thousand " + NumberToText(Number % 1000);// 309
    }

    if(Number >= 2000 & Number <= 999999)//2000
    {
        return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
    }

    if(Number >= 1000000 && Number <= 1999999)//million//1873701// one Milion Eight seventy three thousand seven hundreds one
    {
        return "One Million " + NumberToText(Number % 1000000);
    }

    if(Number >= 2000000 && Number <= 999999999)//8453498//999999999
    {
        return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    }

    if(Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number % 1000000000);
    }

    else
    {
        return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number / 1000000000);
    } 
}

int ReadNumber()
{
    int num;

    cout << "Enter a Number? ";
    cin >> num;

    return num;
}

int main()
{
    int Number = ReadNumber();

    cout << NumberToText(Number);

    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // بيمسح أي Enter قديمة في الذاكرة
    cin.get();                                           // بيستنى منك تضغط Enter عشان يقفل
    return 0;
}