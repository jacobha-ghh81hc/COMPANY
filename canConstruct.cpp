#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool canConstruct (const string &targetString, std::vector<string> &wordBank, std::map<string, bool> &memo)
{
	auto i = memo.find(targetString);
	if(i != memo.end()) return i->second;
	if(targetString.empty()) return true;

	for(std::vector<string>::iterator it = wordBank.begin(); it != wordBank.end(); ++it)
	{
		size_t pos = targetString.find(*it);
		if(pos == 0)
		{
			if(canConstruct(targetString.substr(it->length()), wordBank, memo) != false)
				{
					memo.insert(pair<string,bool>(targetString,true));
					return true;
				}
		}
	}

	memo.insert(pair<string,bool>(targetString,false));
	return false;
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
	std::map<string, bool> MEMO;
	std::vector<string> T1 = {"ab", "abc", "cd", "def", "abcd"};
	std::vector<string> T2 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	std::vector<string> T3 = {"a", "p", "ent", "enter", "ot", "o", "t"};
	std::vector<string> T4 = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	cout << boolalpha << canConstruct("abcdef", T1, MEMO) << endl; //true
	cout << boolalpha << canConstruct("skateboard", T2, MEMO) << endl; //false
	cout << boolalpha << canConstruct("enterapotentpot", T3, MEMO) << endl; //true
	cout << boolalpha << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", T4, MEMO) << endl; //false

	return 0;
}