#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct stEmployee
{

    string firstName = "";
    string lastName = "";
    float Salary;

};

int main()
{
vector<stEmployee> vEmployee;

stEmployee TempEmployee;

TempEmployee.firstName = "Mahmoud";
TempEmployee.lastName = "Eldesoky";
TempEmployee.Salary = 3000;
vEmployee.push_back(TempEmployee);

TempEmployee.firstName = "Ucef";
TempEmployee.lastName = "Maher";
TempEmployee.Salary = 2030;
vEmployee.push_back(TempEmployee);

TempEmployee.firstName = "Aya";
TempEmployee.lastName = "Omran";
TempEmployee.Salary = 10200;
vEmployee.push_back(TempEmployee);

cout << "Employees Vector: \n\n";

//Ranged lOOP
for(stEmployee &Employees : vEmployee)
{
    cout << "First Name: " << Employees.firstName << endl;
    cout << "Last Name : " << Employees.lastName << endl;
    cout << "Salary    : $" << Employees.Salary << endl;
    cout << "\n";
}

    return 0;
}