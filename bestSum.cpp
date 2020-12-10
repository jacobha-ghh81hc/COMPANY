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

bool howSum(const int &targetSum, std::vector<int> &numbers, std::vector<int> &result, std::map<int,std::vector<int>> &memo)
{
	map<int,std::vector<int>>::iterator YesOrNo = memo.find(targetSum);
	if(YesOrNo != memo.end()) result = YesOrNo->second;
	if(targetSum == 0) return true;
	if(targetSum < 0) return false;

	for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		result.push_back(*it);

		if(howSum(targetSum - *it, numbers, result, memo) != false)
		{
			
			//cout << "TRUE case  " << result;
			cout << result;
			//memo.insert(pair<int,std::vector<int>>(targetSum,result));
			result.pop_back();
		}
		else
		{
			result.pop_back();
			//memo.insert(pair<int,std::vector<int>>(targetSum,result));
			//The parent node will generate a false case when their children are done
			//cout << "false case " << result;
		}
	}
	
    return false;
}


int main ()
{
	/*3,4,
	3,2,2,
	4,3,
	2,3,2,
	2,2,3,*/
	vector<int> NUMBERS = {3,4,2};
	std::vector<int> RESULT;
	std::map<int,std::vector<int>> MEMO;
    howSum(7, NUMBERS, RESULT, MEMO);

	return 0;
}