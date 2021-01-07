#include <iostream>
#include <vector>

using namespace std;

ostream& operator<< (ostream& os, const std::vector<int> &v)
{
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		os << *it << ',';
	}
	return os;
}

int theXth1st (const std::vector<int> &first, const std::vector<int> &second, const int &Xth)
{
	std::vector<int> temp;

	auto f = first.begin();
	auto s = second.begin();

	while((f != first.end()) && (s != second.end()))
	{
		if(*f < *s)
			{
				temp.push_back(*f);
				f++;
			}
		else
			{
				temp.push_back(*s);
				s++;	
			}
	}

	if(first.size() < second.size()) temp.assign(s,second.end());
	if(first.size() > second.size()) temp.assign(f,first.end());

	cout << temp;

	return temp.at(Xth - 1);
}

/*int theXth2nd (const std::vector<int> &first, const std::vector<int> &second, const int &Xth)
{
	int f = 0, s = 0, smaller = 0;

	while(f < first.size() && s < second.size() && (f+s) < Xth)
	{
		if(first.at(f) < second.at(s)) f++;
		else s++;
	}

	if(f > s) return second.at(s - 1);
	else return first.at(f - 1);

}*/



int main ()
{
	std::vector<int> B = {11,51,52,80,91};
	std::vector<int> C = {33,41,42,70,100,102};

	cout << theXth1st(B,C,3) << endl;
	cout << theXth1st(B,C,5) << endl;
	cout << theXth1st(B,C,7) << endl;
	cout << theXth1st(B,C,10) << endl;

	cout << "----------" << endl;

	/*cout << theXth2nd(B,C,3) << endl;
	cout << theXth2nd(B,C,5) << endl;
	cout << theXth2nd(B,C,7) << endl;
	cout << theXth2nd(B,C,10) << endl;*/

	return 0;
}