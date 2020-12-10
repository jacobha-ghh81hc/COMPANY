#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool canSum (const long int &targetSum, vector<int> &numbers, map<int,bool> &memo)
{
	map<int,bool>::iterator YesOrNo = memo.find(targetSum);
	if(YesOrNo != memo.end()) return YesOrNo->second;
	if(targetSum == 0) return true;
	if(targetSum < 0) return false;

	for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		if(canSum(targetSum - *it, numbers, memo) == true)
		{
			memo.insert(pair<int,bool>(targetSum,true));
			return true;
		}
	}

	memo.insert(pair<int,bool>(targetSum,false));
	return false;
}


int main ()
{
	vector<int> NUMBERS = {7, 14};
	long int TARGETSUM = 994;
	map<int,bool> MEMO;
	cout << "Could be geting the target sum: " << boolalpha << canSum(300, NUMBERS, MEMO) << endl;
	cout << "Could be geting the target sum: " << canSum(401, NUMBERS, MEMO) << endl;
	cout << "Could be geting the target sum: " << canSum(497, NUMBERS, MEMO) << endl;
	cout << "Could be geting the target sum: " << canSum(483, NUMBERS, MEMO) << endl;

	return 0;

}