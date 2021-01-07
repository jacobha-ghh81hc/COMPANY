#include <iostream>
#include <array>
#include <utility>

using namespace std;

#define N 10

ostream& operator<< (ostream &os, const array<int,N> &v)
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		os << *i << ',';
	}
	cout << endl;
	return os;
}

/*Time complexity O(n^2)
Space complexity O(1)*/

void selectionSortMin (array<int,N> &unsortedArray)
{
	int minIndex = 0;

	for (int i = 0; i < unsortedArray.size() - 1; ++i)
	{
		minIndex = i;
		for(int j = i + 1; j < unsortedArray.size(); ++j)
		{
			if(unsortedArray.at(minIndex) > unsortedArray.at(j))
			{
				minIndex = j;
			}
		}
		swap(unsortedArray.at(minIndex), unsortedArray.at(i));
	}
}

void selectionSortMax (array<int,N> &unsortedArray)
{
	int maxIndex = 0;

	for (int i = unsortedArray.size() - 1; i >= 0; --i)
	{
		maxIndex = i;
		for(int j = i - 1; j > 0; --j)
		{
			if(unsortedArray.at(maxIndex) < unsortedArray.at(j))
			{
				maxIndex = j;
			}
		}
		swap(unsortedArray.at(maxIndex), unsortedArray.at(i));
	}
}


int main ()
{
	array<int,N> A = {3, 99, 7, 24, 52, 9, 18, 7, 1, 1809};
	selectionSortMin(A);
	cout << A;
	selectionSortMax(A);
	cout << A;
	return 0;
}