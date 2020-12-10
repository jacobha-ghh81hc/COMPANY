#include <iostream>
#include <map>
using namespace std;

long int fib(const int &N_, map<int,long int> &M_) {
	auto it = M_.find(N_);
	if (it!= M_.end()) return it->second;
	if (N_ <= 2) return 1;
	M_.insert(pair<int, long int>(N_,fib(N_ - 1, M_) + fib(N_ - 2, M_)));
	return M_.at(N_);
}

int main ()
{
	int N;
	cin >> N;
	map<int, long int> M;

	cout << "So Fibonacci thu " << N << ": ";
	cout << fib(N, M) << endl;

	return 0;
}