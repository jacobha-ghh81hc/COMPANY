#include <iostream>
#include <map>
#include <string>
using namespace std;

long int gridTraveler (const int &m, const int &n, map<string,long int> &memo)
{
	if((m==1) && (n==1)) return 1;
	if((m==0) || (n==0)) return 0;
	const string KEY = to_string(m) + ',' + to_string(n);
	map<string,long int>::iterator it = memo.find(KEY);
	if(it != memo.end()) return it->second;

	memo.insert(pair<string,long int>(KEY,gridTraveler(m-1,n,memo) + gridTraveler(m,n-1,memo)));
	return memo.at(KEY);
}


int main ()
{
	int M, N;
	cin >> M >> N;
	map<string,long int> MEMO;
	cout << "There are " << gridTraveler(M,N,MEMO) << " ways to go from the Start(Left-Up) to the End(Bottom-Right)!" << endl;

	return 0;
}