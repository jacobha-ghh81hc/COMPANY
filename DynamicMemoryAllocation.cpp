#include <iostream>
using namespace std;

//https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/


int main ()
{
	float * p = NULL;

	p = new float;
	*p = 100.332;

	cout << p << " and " << *p << endl;
	delete p;
	cout << p << " and " << *p << endl;

	cout << sizeof(int) << " and " << sizeof(float) << " and " << sizeof(long) << " and " << sizeof(long long) << endl;

	long * p_long = new long[10];

	*p_long = 492;
	*(p_long+1) = 39449;
	*(p_long+2) = 48902;

	for (int i = 0; i < 10; ++i)
	{
		cout << *(p_long+i) << ',';
	}
	cout << endl;

	delete [] p_long;

	for (int i = 0; i < 10; ++i)
	{
		cout << *(p_long+i) << ',';
	}
	cout << endl;

	return 0;
}