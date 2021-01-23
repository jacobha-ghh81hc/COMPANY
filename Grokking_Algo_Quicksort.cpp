#include <iostream>
#include <array>
using namespace std;

// The main confusion here is that sizeof is not a function, but an operator in C/C++
// If called from the same scope where the array was created, sizeof knows of its size
// When you pass the array as a parameter, however, that size information is lost
// Only a reference to the array position in memory is received by the function, so it is treated as a pointer, to all purposes
// So sizeof, when called from inside the function, only sees a pointer, and returns the pointer's size
// These rules do not apply to sizeof because it is not actually a function and the scope is kept

int* GrokkingAlgo_Quicksort (int *APointer2Array, int lengthOfArray)
{
	//if (lengthOfArray < 2) return APointer2Array;

	int pivot = *(APointer2Array + lengthOfArray/2);
	cout << pivot << " This is pivot" << endl;

	int *lessArray = new int[lengthOfArray];
	int *moreArray = new int[lengthOfArray];
	int lessIndex = 0;
	int moreIndex = 0;

	for (int index = 0; index < lengthOfArray; ++index)
	{
		if (*(APointer2Array + index) <= pivot)
		{
			*(lessArray + lessIndex) = *(APointer2Array + index);
			lessIndex++;
		}
		else
		{
			*(moreArray + moreIndex) =  *(APointer2Array + index);
			moreIndex++;
		}
	}

	for (int pIndex = 0; pIndex < lengthOfArray; pIndex++)
	{
		cout << *(lessArray + pIndex) << ',';
	}
	cout << endl;

	for (int pIndex = 0; pIndex < lengthOfArray; pIndex++)
	{
		cout << *(moreArray + pIndex) << ',';
	}
	cout << endl;

	//GrokkingAlgo_Quicksort(lessArray, sizeof lessArray / sizeof *lessArray);
	//GrokkingAlgo_Quicksort(moreArray, sizeof moreArray / sizeof *moreArray);
	return APointer2Array;
}

int main ()
{
	int AnArray[10] = {193,1949,585,391,1465,500,1948,23,91,48};
	cout << "Length of AnArray method 1: " << sizeof AnArray / sizeof *AnArray << endl;
	cout << "Length of AnArray method 2: " << *(&AnArray + 1) - AnArray << " or " << (&AnArray)[1] - AnArray << " or " << 1[&AnArray] - AnArray << endl;
	
	cout << "The next address after these AnArray blocks: " << *(&AnArray + 1) << " or " << (&AnArray)[1] << " or " << 1[&AnArray] << endl;

	cout << "First element: " << &AnArray[0] << " or " << AnArray << " AND last element: " << &AnArray[9] << " or " << AnArray + 9 << endl;
	cout << "First element: " << AnArray[0] << " or " << *AnArray << " AND last element: " << AnArray[9] << " or " << *(AnArray + 9) << endl;

	cout << "After the last element of AnArray: " << AnArray + 10 << " or " << &AnArray[10] << " is " << *(AnArray + 10) << " or " << AnArray[10] << endl;
	cout << "Next position : " << AnArray + 11 << " is " << AnArray[11] << endl;

	// GrokkingAlgo_Quicksort(AnArray, sizeof AnArray / sizeof *AnArray);

	// for (int pIndex = 0; pIndex < sizeof AnArray / sizeof *AnArray; pIndex++)
	// {
	// 	cout << *(AnArray + pIndex) << ',';
	// }
	// cout << endl;

	return 0;
}