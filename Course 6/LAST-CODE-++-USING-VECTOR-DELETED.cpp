#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void loadDataFromFileToVector(string FileName , vector<string> &vFileContent)
{
	fstream file;
	file.open(FileName , ios::in); // in عشان احنا انقرا الفايل وانعبيه للفيكتور 

	if(file.is_open())
	{
		string line;
		while (getline(file , line))
		{
			vFileContent.push_back(line);//انضيف لاين لاين للفكتور
		}
		file.close();
	}
}

void saveVectorToFile(string FileName , vector<string> vFileContent)
{
fstream file;
file.open(FileName , ios::out);// لازم out  عشان امحي الفايل و اضيف عناصر الفيكتور معبي 

if(file.is_open())
{
	for(string line : vFileContent)
	{
		if(line != "")
		{
			file << line << endl;
		}
	}
	file.close();
}
}

void DeleteRecordFromFile(string FileName , vector<string>& RecordToDelete)
{
	vector<string> vFileContent;
	loadDataFromFileToVector(FileName , vFileContent);

	for(string &line : vFileContent)//تمر عل يعناصر الملف
	{
		for(string ItemToDelete : RecordToDelete)// تمر علي عناصر المطلوب حذفها
		{
			if(line == ItemToDelete)
			{
				line = "";//تفريغ السطر اذا وجد تطابق 
				break;// نخرج من الحلقه الداخليه لتسريع الاداء
			}
		}
	}
	saveVectorToFile(FileName , vFileContent);
}

void printFileContent(string FileName)
{
	fstream file;
	file.open(FileName , ios::in);

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
cout << "File List Before delete: \n";
printFileContent("FirstFile.txt");

vector<string> vWatchesDelete{"Casio 2" , "Casio 3"};

DeleteRecordFromFile("FirstFile.txt" , vWatchesDelete);

cout << "\n\nFile List After delete: \n";
printFileContent("FirstFile.txt");


return 0;
}
