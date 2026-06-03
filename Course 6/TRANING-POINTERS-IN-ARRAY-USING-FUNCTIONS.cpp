#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
using namespace std;

void FillArray(int *ptr , int &arrLength)
{
	arrLength = 5;

	ptr[0] = 10;
	ptr[1] = 20;
	ptr[2] = 300;
	ptr[3] = 40;
	ptr[4] = 50;
}

void PrintAddressesInArrayUsingPtr(int *ptr , int arrLength)
{

for(int i = 0; i < arrLength; i++)
{
cout << ptr + i << endl; // || ptr[i] او طباعه العناوين ب دي
}

}

void PrintElementsInArray(int *ptr , int arrLength)
{

for(int i = 0; i < arrLength; i++)
{
cout << ptr[i] << endl; // || *(ptr + 1) او طباعه العناصر ب دي
}

}

int SumElementsInArray(int *ptr , int arrLength)
{
	int sum = 0;
	for(int i = 0; i < arrLength; i++)
	{
	sum += *(ptr + i); 
	}
	return sum;
}

int MaxElementInArray(int *ptr , int arrLength)
{
	int maxElement = *ptr;

	for(int i = 0; i < arrLength; i++)
	{
		if(ptr[i] > maxElement)
		{
			maxElement = ptr[i];
		}
	}
	return maxElement;
}

int main() 
{ 

	int arr[5] , arrLength = 0; 	
	int *ptr = arr;
	
	FillArray(ptr , arrLength);

	cout << "Addresses Element in Array\n";
	PrintAddressesInArrayUsingPtr(ptr , arrLength);

	cout << "\nValues Elements In Array\n";
	PrintElementsInArray(ptr , arrLength);

	cout << "\nSum All Elements In Array : " << SumElementsInArray(ptr , arrLength);

	cout << "\nMax Element In Array : " << MaxElementInArray(ptr , arrLength);

return 0;
}
