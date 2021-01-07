#include <iostream>
#include <array>
using namespace std;

#define INFO cout << "[" << __FILE__ << "][" << __FUNCTION__ << "][Line " << __LINE__ << "] " << endl;
#define LINE cout << "[Line " << __LINE__ + 1 << "] ";

int main ()
{
	// Declare một mảng đa chiều thì cần cụ thể số phần tử của mảng con, bản chất mảng đa chiều là mảng của mảng
	// int MulArray[][3] = {190,30,103,293,1394,1034}; // Cách này cũng được
	int MulArray[][3] = {{139,301,490},{3894,39,492}}; // Cách này rõ ràng hơn

	// Tên mảng là biến có giá trị là địa chỉ của phần tử đầu tiên của mảng, cũng là địa chỉ mảng con đầu tiên,
	// cũng là địa chỉ phần tử đầu tiên của mảng con đầu tiên, dereference tên mảng cũng như vậy
	LINE;
	cout << MulArray << " equal to " << MulArray[0] << " equal to " << &MulArray[0][0] << " equal to " << *MulArray << endl;
	LINE;
	cout << MulArray+1 << " equal to " << MulArray[1] << " equal to " << &MulArray[1][0] << " equal to " << *(MulArray+1) << endl;

	// Để truy cập các phần tử của mảng con bằng con trỏ, ta làm như dưới
	// MulArray[0] là địa chỉ của mảng con đầu tiên (cũng là địa chỉ của phần tử đầu tiên của mảng con đầu tiên, cũng là địa chỉ của mảng đa chiều mẹ)
	// MulArray[1] là địa chỉ của mảng con tiếp theo (cũng là địa chỉ của phần tử đầu tiên của mảng con tiếp theo)
	// Để truy cập các phần tử tiếp theo của mảng con, ta dereferce địa chỉ của mảng con đó +i như sau: *(MulArray[0]+0), *(MulArray[1]+1)
	// Dereference mảng con đầu tiên
	LINE;
	cout << *MulArray[0] << " or " << *(MulArray[0]+0) << " then " << *(MulArray[0]+1) << " then " << *(MulArray[0]+2) << endl;
	LINE;
	cout << *(*MulArray+0) << " then " << *(*MulArray+1) << " then " << *(*MulArray+2) << endl;
	// Dereference mảng con tiếp theo
	LINE;
	cout << *MulArray[1] << " or " << *(MulArray[1]+0) << " then " << *(MulArray[1]+1) << " then " << *(MulArray[1]+2) << endl;
	LINE;
	cout << *(*(MulArray+1)+0) << " then " << *(*(MulArray+1)+1) << " then " << *(*(MulArray+1)+2) << endl;

	// MulArray+1 sẽ là địa chỉ của mảng con tiếp theo, cũng là địa chỉ của phần tử đầu tiên của mảng con tiếp theo
	// Tương tự, dereference của *(MulArray+1) cũng là địa chỉ mảng con tiếp theo, cũng là địa chỉ phần tử đầu tiên mảng con tiếp theo
	LINE;
	cout << *(MulArray+1) << " equal to " << MulArray+1 << " equal to " << MulArray[1] << " equal to " << &MulArray[1][0] << endl;

	// *(MulArray+1)+i là địa chỉ của phần tử tiếp theo của mảng con tiếp theo
	LINE;
	cout << *(MulArray+1)+0 << " then " << *(MulArray+1)+1 << " then " << *(MulArray+1)+2 << endl;
	// Dereference
	LINE;
	cout << *(*(MulArray+1)+0) << " then " << *(*(MulArray+1)+1) << " then " << *(*(MulArray+1)+2) << endl;

	// Tóm lại, trong mảng 2 chiều thì MulArray[i][j] = *(MulArray[i]+j) = *(*(MulArray+i)+j)
	LINE;
	cout << MulArray[1][1] << " equal to " << *(MulArray[1]+1) << " equal to " << *(*(MulArray+1)+1) << endl;

	return 0;
}