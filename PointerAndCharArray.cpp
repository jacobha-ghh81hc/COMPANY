#include <iostream>
#include <array>
using namespace std;

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

void printingNumberArray (int * APointer, int NOE) // int * APointer cũng được
{
	for(int i = 0; i < NOE; ++i)
	{
		cout << *APointer;
		APointer++;
	}
	cout << endl;
	return;
}


int main ()
{
	// Đây là mảng một chiều kiểu char, declare và define kiểu này thì không cần có ký tự kết thúc chuỗi '\0'
	char website[] = {'H','a','c','k','e','r','r','a','n','k','\0','N','O','T','-','A','-','C','H','A','R','-','A','R','R','A','Y'};
	for(int i = 0; i < sizeof(website)/sizeof(website[0]); ++i)
	{
		cout << *(website + i);
	}
	cout << endl;

	// Đây là mảng một chiều kiểu char, chú ý có thêm một ký tự kêt thúc chuỗi ở cuối cùng '\0'
	char webpage[] = "Hackerrank";
	printingCharArray(webpage);

	int Phone[] = {0,9,7,5,5,6,8,6,0,1}; // C
	array<int,10> PhoneCpp[] = {0,9,7,5,5,6,8,6,0,1}; // C++
	printingNumberArray(Phone,sizeof(Phone)/sizeof(Phone[0]));

	for(int i = 0; i < sizeof(Phone)/sizeof(Phone[0]); ++i)
	{
		cout << *(Phone+i);
		//Phone++; // Tại sao increment tên mảng một chiều kiểu int không được mà kiểu char lại được
				// char thì 1 byte mà increment thực ra là i++ <=> i = i+1, cho nên mảng kiểu char thì increment được
				// int thì 4 byte nên không increment được, có thể thấy Phone+i thì được, còn Phone = Phone + i thì không được
	}
	cout << endl;

	cout << "---------------------------------------------------------------------------------------" << endl;

	char AnNumArray[] = "This is test"; // Được lưu trữ ở vùng nhớ global, có thể thay đổi được
	//const char * AnNumArray = "This is test"; // Là constant, assignment of read only location
	*(AnNumArray+3) = 'K';

	cout << AnNumArray << endl;

	return 0;
}