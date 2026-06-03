#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void loadDateFromFileToVector(string FileName , vector<string>& vFileVector)
{
	fstream file;
	file.open(FileName , ios::in);
	if(file.is_open())
	{
		string line;
		while(getline(file , line))
		{
			vFileVector.push_back(line);
		}
		file.close();
	}
}

void saveVectorToFile(string FileName , vector<string> vFileContent)// هنا فقط بنعدل علي الفايل بحذف الفراغات
{
	fstream file; 
	file.open(FileName , ios::out);

	if(file.is_open())
	{
		for(string line : vFileContent)
		{
			if(line != "") // طالما السطر لا يساوي فراغ اكتبو
			{
			file << line << endl;
			}
		}
	file.close();
	}
}

void DeleteRecordFromFile(string FileName , string Record)
{
vector<string> vFilecontent;

loadDateFromFileToVector(FileName , vFilecontent);

for(string &line : vFilecontent)//هنا ضروري استخدام الريفرنس لتعديل علي السطور النسخه الاصليه 
{
	if(line == Record)
	{
		line = "";//empty string
	}
}
saveVectorToFile(FileName , vFilecontent);
}

void printfileContent(string FileName)
{
	vector<string> vFileContent ;
	fstream file;
	file.open(FileName ,ios::in);//read mode

	if(file.is_open())
	{
		string line;
		while(getline(file , line))
		{
			cout << line << endl;
		}
		file.close();
	}
}

int main()
{
cout << "File Content Before Delete: \n";
printfileContent("FirstFile.txt");

DeleteRecordFromFile("FirstFile.txt" , "ali");

cout << "\n\nFile Content After Delete: \n";
printfileContent("FirstFile.txt");

return 0;
}
