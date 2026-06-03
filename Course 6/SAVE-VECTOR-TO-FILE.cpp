#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void SaveVectorToFile(string NameFile , vector<string>& vFileContent)//هنا مبعتناش & عشان احنا بنبعت نسخه داتا فيكتور ل الفايل 
{
	fstream File;
	File.open(NameFile, ios::out);

	if(File.is_open())
	{
		for(const string &line : vFileContent) // const عشان يضمن ان مفيش اي تعديل لاي داتا لفيكتور عشان حاطين & للفيكتور ومينفعش نعدل هنا اينعكس برا وايبوظ الدينا
		{
			if(line != "")
			{
				File << line << endl;// هنا ممينفعش نقول cout عشان هي بتطبع للتاميرنال فقط 
			}
		}
		File.close();
	}
}


int main()
{
vector<string>vFileContent { "Ahmed" , "Mahmoud" , "Younes" , "Sara"};

SaveVectorToFile("FirstFile.txt" , vFileContent);

cout << vFileContent.at(0) << endl;

return 0;
}
