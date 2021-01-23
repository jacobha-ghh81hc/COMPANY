#include <iostream>
#include <array>
using namespace std;

int main ()
{
	// Tại sao có thể access được phần tử ngoài range của AnArray
	// AnArray là địa chỉ của mảng, cũng là địa chỉ của phần tử đầu tiên của mảng AnArray = &AnArray[0] = &AnArray, *AnArray = AnArray[0]
	// Khi &AnArray được địa chỉ của mảng, thì &AnArray + 1 sẽ padding tới địa chỉ ô nhớ tiếp theo sau phần tử cuối cùng của mảng
	// Vậy tại sao khi dereference *(&AnArray + 1) lại là một địa chỉ mà không phải giá trị của ô nhớ?
	// What the hell are them? &AnArray)[1] or 1[&AnArray]

	int AnArray[10] = {193,1949,585,391,1465,500,1948,23,91,48};
	cout << "Length of AnArray method 1: " << sizeof AnArray / sizeof *AnArray << endl;
	cout << "Length of AnArray method 2: " << *(&AnArray + 1) - AnArray << " or " << (&AnArray)[1] - AnArray << " or " << 1[&AnArray] - AnArray << endl;
	
	cout << "The next address after these AnArray blocks: " << *(&AnArray + 1) << " or " << (&AnArray)[1] << " or " << 1[&AnArray] << endl;
	cout << "After the last element of AnArray: " << AnArray + 10 << " or " << &AnArray[10] << " is " << *(AnArray + 10) << " or " << AnArray[10] << endl;

	cout << "First element: " << &AnArray[0] << " or " << AnArray << " AND last element: " << &AnArray[9] << " or " << AnArray + 9 << endl;
	cout << "First element: " << AnArray[0] << " or " << *AnArray << " AND last element: " << AnArray[9] << " or " << *(AnArray + 9) << endl;

	cout << "Next position : " << AnArray + 11 << " is " << AnArray[11] << endl;
	cout << "Random position : " << AnArray + 110 << " is " << AnArray[110] << endl;

	// What the hell is that? Out of bound of AnArray is still fine?
	AnArray[110] = 9999;
	AnArray[111] = 2222;
	cout << "Change value of the random position: " << AnArray + 110 << " is " << AnArray[110] << endl;
	cout << "Change value of the random position: " << AnArray + 111 << " is " << AnArray[111] << endl;

	cout << AnArray << " and " << &AnArray << endl;
	cout << AnArray + 1 << " and " << &AnArray + 1 << endl;
	cout << *(&AnArray + 1) - AnArray << endl;


	return 0;
}