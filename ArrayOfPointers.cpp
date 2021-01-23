#include <iostream>
#include <typeinfo>
using namespace std;

#define N 3
#define SPACE cout << "--------------------------------------" << endl;

int main()
{
	char Garen[N] = {0x41,0x42,67};
	cout << Garen[0] << 1[Garen] << 2[Garen] << endl;
	5[Garen] = 73;
	cout << Garen[5] << endl;

	SPACE

	int16_t Mang[N] = {15,34,59};
	cout << sizeof(int16_t) << " and " << sizeof(Mang) << endl;
	cout << &Mang << " equal to " << Mang + 0 << " then " << Mang + 1 << " then " << Mang + 2 << " then " << Mang + 3 << endl;
	cout << *Mang << " equal to " << *(Mang + 0) << " then " << *(Mang + 1) << " then " << *(Mang + 2) << " then " << *(Mang + 3) << endl;

	// Mang là con trỏ có giá trị là địa chỉ của mảng, cũng là địa chỉ phần tử đầu tiên của mảng nhưng datatype là int16_t hay short [N]
	// &Mang là con trỏ có giá trị là địa chỉ của mảng, cũng là địa chỉ phần tử đầu tiên của mảng nhưng datatype là N * int16_t hay short * [N]
	cout << typeid(Mang).name() << " and " << typeid(&Mang).name() << endl;
	// Mang + i nghĩa là increment i*sizeof(int16_t)
	// &Mang + i nghĩa là increment i*sizeof(N * int16_t)
	// *(&Mang + 1) là địa chỉ ô nhớ liền kề sau phần tử cuối cùng của mảng

	cout << (&Mang + 1) << endl;
	cout << *(&Mang + 1) << endl;
	// error: invalid operands of types ‘int16_t (*)[3]’ {aka ‘short int (*)[3]’} and ‘int16_t [3]’ {aka ‘short int [3]’} to binary ‘operator-’
	// int16_t (*)[3] là a pointer to array
	// int16_t [3] là an array
	cout << *(&Mang + 1) - Mang << endl;

	SPACE

	for (int i = 0; i < 3; i++)
	{
		//cout << 0[Mang] << " then " << 1[Mang] << " then " << 2[Mang] << " then trash is " << 3[Mang] << endl;
		cout << i[Mang] << ',';
		cout << *(Mang + i) << ';';
	}
	cout << endl;

	return 0;
}