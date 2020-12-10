#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {

	int N;
	cin >> N;
	set<int> intSet;
	set<int>::iterator it;
	int count = 0;
	do {
		string Input;
		int Qkind, Qvalue;
		getline(cin,Input,'\n');
		stringstream extracInput(Input);
		extracInput >> Qkind >> Qvalue;

		switch(Qkind) {
			case 1:
			intSet.insert(Qvalue);
			break;

			case 2:
			intSet.erase(Qvalue);
			break;

			case 3:
			it = intSet.find(Qvalue);
			if(it != intSet.end()) cout << "Yes" << endl;
			else cout << "No" << endl;
			break;
		}

		count++;
	} while(count <= N);

    return 0;
}



