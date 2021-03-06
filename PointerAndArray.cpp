#include <iostream>
#include <array>
using namespace std;

// Hàm nhận đối số là mảng một chiều int NameOfArray[] hoặc int * APointer
// The sizeof way is the right way if you are dealing with arrays not received as parameters
// An array sent as a parameter to a function is treated as a pointer, so sizeof will return the pointer's size, instead of the array's size
// Thus, inside functions this method does not work
// Instead, always pass an additional parameter size_t size indicating the number of elements in the array
// As the Wikipedia entry makes clear, C's sizeof is not a function; it's an operator
// Thus, it does not require parenthesis around its argument, unless the argument is a type name
// This is easy to remember, since it makes the argument look like a cast expression, which also uses parenthesis
// Formula for computing the address of ptr + i where ptr has type T then the formula for the address is:
// addr(ptr + i) = addr(ptr) + [sizeof(T) * i]

void DoubleThem (int NameOfArray[])
{
	// Chúng ta nên truyền thêm một đối số là số lượng phần tử của mảng sizeof(NameOfArray)/sizeof(NameOfArray[0])
	// để duyệt qua tất cả các phần tử bằng vòng loop
	// Thật sự chỉ cần biết được địa chỉ của phần tử đầu tiên và số lượng phần tử của mảng
	// là có thể thao tác thoải mái với mảng một chiều
	for (int index = 0; index < 10; ++index)
	{
		*(NameOfArray + index) = 2 * *(NameOfArray + index);
	}
	return;
}

// Mảng một chiều trong C có thể làm như bên dưới được, còn trong C++ thì bản chất vẫn vậy nhưng compiler không cho phép một số cái

int main ()
{

	int exp[10] = {2,3,4,5,6,7,9,10,9,1999}; // Mảng một chiều trong C
	array<int,10> expCpp = {2,3,4,5,6,7,9,10,9,1999}; // Mảng một chiều trong C++

	// Tên của mảng một chiều là địa chỉ của phần tử đầu tiên trong mảng
	// Ta có thể declare một con trỏ cùng kiểu dữ liệu như mảng và define trỏ đến mảng một chiều đó
	int * p_exp = exp;
	// int * p_expCpp = expCpp; // C++ không cho phép làm như này
	int * p_expCpp = &expCpp[0]; // C++ như thế này thì OK
	cout << p_exp << " and " << exp << " and " << &exp[0] << endl;

	// Lấy địa chỉ của phần tử thứ i &exp[i] hoặc exp + i
	// Lấy giá trị của phần tử thứ i exp[i] hoặc *(exp + i)
	cout << exp + 1 << " is " << *(exp+1) << endl;

	while(*p_exp != *(exp+9))
	{
		// Ta có thể increment con trỏ nhưng không thể trực tiếp increment tên mảng một chiều (p_exp++ OK, exp++ NOT OK)
		cout << *(p_exp++) << ',';
	}
	// cout phần tử cuối cùng của mảng một chiều
	cout << *p_exp << endl;


	// Gọi hàm truyền vào đối số là mảng một chiều
	DoubleThem(exp);
	for (int index = 0; index < 10; ++index)
	{
		cout << *(exp + index) << ',';
	}
	cout << endl;

	return 0;
}