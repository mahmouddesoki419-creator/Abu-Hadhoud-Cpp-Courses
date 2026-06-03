#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

/*/string trimRight(string S)
{
for(short i = S.length() - 1; i >= 0; i--)
{
	if(S[i] != ' ')
	{
		return S.substr(0 , i + 1);//"Mohammed Fadi Ali Maher "
	}//الباراميتر الأول: هو الـ Index (بتبدأ منين).
	//الباراميتر الثاني: هو الـ Count (هتاخد كام حرف).

}
return "";
}/*/


string joinString(vector<string> vS1 , string delim)
{

	string S = "";
	for(string &Word : vS1)
	{
		S += Word + delim;
	}
	return S.substr(0 , S.length() - delim.length());
}

string joinString(string sArr[] , short length , string delim)
{
	string S = "";
	for(short i = 0; i < length; i++) // هنا مينفعش نبعت sArr.length() او sArr.size() عشان كده ايشير الي اول عنصر بالاراي 
	{
		S += sArr[i] + delim;
	}
	return S.substr(0 , S.length() - delim.length());
}

int main()
{

	vector<string> vString = {"Mohammed" ,  "Fadi",  "Ali"  , "Maher"};
	string sArr[] = { "mahmoud" , "youssef" , "ahmed" , "nasser"};

	cout << "Vector After Join: \n";
	cout << joinString(vString , ",") << endl;

	cout << "\n\nArray After join: \n";
	cout << joinString(sArr , 4 , ",");


	system("pause>0");
	return 0;
}