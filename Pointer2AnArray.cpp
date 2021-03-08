#include <iostream>
using namespace std;

#define SPACE cout << "------------------------------------------" << endl;


void printingCharArray (char ACharArray[]) // char * APointer cũng được
{
	while(*ACharArray != '\0')
	{
		cout << *ACharArray;
		ACharArray++; // Increment tên mảng ký tự thì được, còn tên mảng int thì không được, bản chất 2 thằng là địa chỉ của phần tử đầu tiên của mảng.
	}
	cout << endl;
	return;
}

int main ()
{
	//  error: ISO C++ forbids converting a string constant to ‘char*’ [-Werror=write-strings]
	char *Webpage1st = "Hackerrank.com";
	char Webpage2nd[] = "Hackerrank.net";
	printingCharArray(Webpage1st);
	printingCharArray(Webpage2nd);

	SPACE

	char (*p_Webpage)[15] = &Webpage2nd;
	cout << *p_Webpage << endl;
	cout << Webpage1st << endl;
	cout << Webpage2nd << endl;

	SPACE

	char Phone[] = {70,71,72,73,74,75};
	char (*p_Phone)[6] = &Phone;
	cout << *p_Phone << endl;
	cout << Phone << endl;

	return 0;
}