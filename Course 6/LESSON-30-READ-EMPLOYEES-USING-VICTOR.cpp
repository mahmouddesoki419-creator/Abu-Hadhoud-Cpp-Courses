#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct stEmployee
{

    string firstName = "";
    string lastName = "";
    float Salary;
    int age;

};

void ReadEmployeesVector(vector<stEmployee>&vEmployee)
{
char ReadMore = 'y';
int NumbersEmployees = 0;
stEmployee Employee;

while (ReadMore == 'y' || ReadMore == 'Y')
{
    
    cout << "How Many Employee do yo want add? ";
    cin >> NumbersEmployees;
    
    for(int i = 0; i < NumbersEmployees; i++)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEmployee (" << i + 1 << ") Details: \n";
        cout << "First Name: ";
        getline(cin,Employee.firstName);
        cout << "Last Name: ";
        getline(cin,Employee.lastName);
        cout << "Salary: $";
        cin >> Employee.Salary;
        cout << "Age: ";
        cin >> Employee.age;
        vEmployee.push_back(Employee);
    }
    cout << "\nDo you want to read More Employees? (Y/N) ? ";
    cin >> ReadMore;
}

}

void PrintEmployees_Vector(vector<stEmployee>&vEmployee)
{
    cout << "\n\nSO , Employees Vector you Added:\n";
    short counter = 0;
    for(stEmployee & Employees : vEmployee)
    {
    counter++;
    cout << "----------------------------\n";
    cout << "\nInformations Employee(" << counter << ")\n\n";
    cout << "First Name: " << Employees.firstName << endl;
    cout << "Last Name: " << Employees.lastName << endl;
    cout << "Salary: $" << Employees.Salary << endl;
    cout << "Age: " << Employees.age << endl;
    }
}

int main()
{
vector<stEmployee> vEmployee;
ReadEmployeesVector(vEmployee);
PrintEmployees_Vector(vEmployee);

system("pause");
    return 0;
}