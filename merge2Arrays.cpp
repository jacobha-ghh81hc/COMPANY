#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
#define N 10

// https://www.techiedelight.com/find-kth-largest-element-array/
// https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/

int* autoGeneration(void)
{
	int *retArray = (int*)calloc(N, sizeof(int));
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		*(retArray + i) = rand() % 100;
		cout << *(retArray + i) << ',';
	}
	cout << endl;
	return retArray;
}

int main()
{
	int firstArray[N] = {14,24,30,41,56,67,70,83,91,101};
	int secondArray[N] = {1,25,30,41,55,63,70,82,93,106};

	int *mergedArray = (int*)calloc(2*N, sizeof(int));

	int i,j,k;
	i = j = k = 0;
	while(i<N && j<N)
	{
		if(*(firstArray+i) < *(secondArray+j))
		{
			*(mergedArray+k) = *(firstArray+i);
			k++;
			i++;
		}
		else
		{
			*(mergedArray+k) = *(secondArray+j);
			k++;
			j++;
		}
	}

	while(i<N)
	{
		*(mergedArray+k) =  *(firstArray+i);
		i++;
		k++;
	}

	while(j<N)
	{
		*(mergedArray+k) =  *(secondArray+j);
		j++;
		k++;
	}

	for(int l = 0; l<2*N; l++)
	{
		cout << *(mergedArray+l) << ',';
	}
	cout << endl;

	return 0;
}