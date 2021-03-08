// https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm
// https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

#define N 10

// Để return 1 array thì return một con trỏ pointed đến vùng nhớ mảng đã cấp phát
// Ta phải biết được kích thước vùng nhớ bao nhiêu? N * sizeof(int) cho N phần thử kiểu int
int* arrayGeneration (void)
{
	cout << "Generated array: " << endl;

	// Tại sao phải cấp phát động hoặc xài static?
	// Vì khi hàm được gọi thì sẽ cấp phát vùng nhớ stack nếu không xài static/dynamic memory allocation
	// Kết thúc hàm thì vùng nhớ trên stack bị free, nên không thể return được mảng đã cấp phát
	int *pArray = (int*)malloc(N * sizeof(int));
	//static int  pArray[N];

	srand(time(0));
	for(int rad = 0; rad < N; rad++)
	{
		*(pArray + rad) = rand() % 201;
		cout << *(pArray + rad) << ',';
	}
	cout << endl;

	return pArray;
}

int main()
{
	int prf = 0;
	int *p2Array = nullptr;
	p2Array = arrayGeneration();
	cout << "Returning an array: " << endl;
	while(prf < N)
	{
		cout << *(p2Array + prf) << ',';
		prf++;
	}
	cout << endl;

	cout << "After free memory: " << endl;
	free(p2Array);
	prf = 0;
	while(prf < N)
	{
		cout << *(p2Array + prf) << ',';
		prf++;
	}
	cout << endl;

	return 0;
}