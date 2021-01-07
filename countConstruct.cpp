#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int canConstruct (const string &targetString, std::vector<string> &wordBank, std::map<string, int> &memo)
{
	auto i = memo.find(targetString);
	if(i != memo.end()) return i->second;
	if(targetString.empty()) return 1;

	int totalCount = 0;

	for(std::vector<string>::iterator it = wordBank.begin(); it != wordBank.end(); ++it)
	{
		size_t pos = targetString.find(*it);
		if(pos == 0)
		{
			int numWaysForRest = canConstruct(targetString.substr(it->length()), wordBank, memo);
			totalCount+=numWaysForRest;
		}
	}

	memo.insert(pair<string,int>(targetString,totalCount));
	return totalCount;
}


/* Brute force
Time complexity: O(n^m * m)
Space complexity: O(m^2)
*/

/* Memoize
Time complexity: O(n*m * m)
Space complexity: O(m^2)
*/

int main ()
{
	std::map<string, int> MEMO;
	std::vector<string> T0 = {"purp", "p", "ur", "le", "purpl"};
	std::vector<string> T1 = {"ab", "abc", "cd", "def", "abcd"};
	std::vector<string> T2 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	std::vector<string> T3 = {"a", "p", "ent", "enter", "ot", "o", "t"};
	std::vector<string> T4 = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};

	cout << canConstruct("purple", T0, MEMO) << endl; //2
	cout << canConstruct("abcdef", T1, MEMO) << endl; //1
	cout << canConstruct("skateboard", T2, MEMO) << endl; //0
	cout << canConstruct("enterapotentpot", T3, MEMO) << endl; //4
	cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", T4, MEMO) << endl; //0

	return 0;
}