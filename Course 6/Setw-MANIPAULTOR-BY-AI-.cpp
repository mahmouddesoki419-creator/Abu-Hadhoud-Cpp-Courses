#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // تحديد عرض كل عمود عشان نستخدمه في كل مكان
    const int col1 = 10;
    const int col2 = 35;
    const int col3 = 10;

    // رسم الخط العلوي
    cout << setfill('-') << setw(col1 + col2 + col3 + 4) << "" << endl;
    cout << setfill(' '); // نرجع الفراغ للطبيعي

    // طباعة الهيدر (العناوين)
    cout << "| " << left << setw(col1) << "code" 
         << "| " << left << setw(col2) << "Name" 
         << "| " << left << setw(col3) << "Mark" << " |" << endl;

    // رسم خط فاصل
    cout << setfill('-') << setw(col1 + col2 + col3 + 4) << "" << endl;
    cout << setfill(' ');

    // طباعة الصفوف
    cout << "| " << left << setw(col1) << "C101" 
         << "| " << left << setw(col2) << "introduction to programming 1" 
         << "| " << left << setw(col3) << "95" << " |" << endl;

    cout << "| " << left << setw(col1) << "C102" 
         << "| " << left << setw(col2) << "Computer Hardware" 
         << "| " << left << setw(col3) << "70" << " |" << endl;

    cout << "| " << left << setw(col1) << "C10356" 
         << "| " << left << setw(col2) << "Network" 
         << "| " << left << setw(col3) << "80" << " |" << endl;

    // رسم الخط السفلي
    cout << setfill('-') << setw(col1 + col2 + col3 + 4) << "" << endl;

    system("pause");
    return 0;
}