#include <iostream>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

// Có 2 cách giải bài toán tìm 2nd của mảng
// C1: Sorting mảng theo thứ tự giảm dần, printf ra phần tử 2nd
// C2: Đồng thời tìm kiếm phần tử 1st và 2nd

ostream& operator<< (ostream &out, const std::vector<int> &vIn)
{
	for (auto index = vIn.begin(); index != vIn.end(); index++)
	{
		out << *index << ',';
	}

	return out;
}

void memBlockPrinter(const int *vIn, const int &howMany)
{
	for (auto index = 0; index < howMany; index++)
	{
		cout << *(vIn + index) << ',';
	}
}


int main()
{
	int largestElm = INT_MIN;
	int smallerElm = INT_MIN;
	int n = 10;
	int *anRandArray = (int*) calloc(n, sizeof(int));

	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		anRandArray[i] = rand() % 201;
		printf("%d ", anRandArray[i]);
	}
	memBlockPrinter(anRandArray,n);

	int max, second_max;
	max = second_max = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (anRandArray[i] > max)
			{
				second_max = max;
				max = anRandArray[i];
			} else if (anRandArray[i] > second_max && anRandArray[i] < max)
			{
				second_max = anRandArray[i];
			}
	}
	printf("\nmax=%d, second_max=%d", max, second_max);

	cout << endl;

	std::vector<int> v = {10,-33,-190,201,401,491,-581,4,59,1905,-1045,194};
	cout << v << endl;

	auto it = v.begin();
	while(it != v.end())
	{
		if(*it > largestElm) { smallerElm = largestElm; largestElm = *it; }
		else if(*it > smallerElm) { smallerElm = *it; }
		it++;
	}

	cout << largestElm << " and " << smallerElm << endl;

	return 0;
}