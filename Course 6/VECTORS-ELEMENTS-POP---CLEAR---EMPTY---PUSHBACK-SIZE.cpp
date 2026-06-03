#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
using namespace std;

int main()
{
vector<int> vNumbers;

vNumbers.push_back(10);
vNumbers.push_back(20);
vNumbers.push_back(30);
vNumbers.push_back(40);
vNumbers.push_back(50);

cout << "Stack Size = " << vNumbers.size() << endl;

vNumbers.pop_back();
vNumbers.pop_back();
vNumbers.pop_back();

cout << "Stack Size = " << vNumbers.size() << endl;

cout << "Numbers Vector: \n";
for(int i : vNumbers) 
{
cout << i << endl;
}
cout << endl;

if(!vNumbers.empty())

vNumbers.clear();


cout << "Numbers Vector After Clean: \n";
for(int i : vNumbers) 
{
cout << i << endl;
}
cout << endl;

    return 0;
}