#include <iostream>
#include <vector>
using namespace std;

ostream& operator<< (ostream &os, const std::vector<int> &v)
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		os << *i << ',';
	}
	cout << endl;
	return os;
}

int main ()
{
	std::vector<int> v1 = {1,2,3};
	cout << v1;

	std::vector<std::vector<int>> v2 = {{1,2,3}, {4,5,6}, {7,8,9}};

	for(auto it = v2.begin(); it != v2.end(); ++it)
	{
		cout << *it;
	}

	cout << v2.at(1);
	return 0;
}