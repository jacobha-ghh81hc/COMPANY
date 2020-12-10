#include <iostream>
#include <map>
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

bool howSum(const int &targetSum, std::vector<int> &numbers, std::vector<int> &result)
{
	if(targetSum == 0) return true;
	if(targetSum < 0) return false;

	for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		result.push_back(*it);

		if(howSum(targetSum - *it, numbers, result) != false)
		{
			
			//cout << "TRUE case  " << result;
			cout << result;
			result.pop_back();
		}
		else
		{
			result.pop_back();
			//The parent node will generate a false case when their children are done
			//cout << "false case " << result;
		}
	}
	
    return false;
}


int main ()
{
	//For the allSum problem, the targetSum should not large cause to do the hard optimization
	/*3,4,
	3,2,2,
	4,3,
	2,3,2,
	2,2,3,*/
	vector<int> NUMBERS = {3,4,2};
	std::vector<int> RESULT;
    howSum(7, NUMBERS, RESULT);

	return 0;
}