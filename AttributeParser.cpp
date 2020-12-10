#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
	int N, Q;
	do {
		cin >> N >> Q;
		cin.ignore();
	} while ((N<1||N>20) && (Q<1||Q>20));

	struct HRML {
		string _tagS;
		string _attributeS;
		string _valueS;
		string _endS;
	} HRMLsource[N];

	int count=0;

	do {
		string Spart;
		getline(cin,Spart,'\n');

		if((Spart.substr(0,1) == "<") && (Spart.substr(0,2) != "</")) {
			char rm;
			Spart.erase(Spart.begin());
			Spart.erase(Spart.end()-1);
			stringstream ss(Spart);
			ss >> HRMLsource[count]._tagS >>  HRMLsource[count]._attributeS >> rm >>  HRMLsource[count]._valueS;
			HRMLsource[count]._valueS.erase(HRMLsource[count]._valueS.begin());
			HRMLsource[count]._valueS.erase(HRMLsource[count]._valueS.end()-1);
		}
		else { 
			stringstream ss(Spart);
			ss >> HRMLsource[count]._endS;
		}

		count++;
	} while (count < N);

	struct HRMLQuery {
		string _tagQ;
		string _attributeQ;
	} HRMLqueries[Q];

	count=0;
	
	do {
		string Qpart;
		getline(cin,Qpart,'\n');

		HRMLqueries[count]._attributeQ = Qpart.substr(Qpart.find('~')+1);
		if(Qpart.find('.') != string::npos)
			HRMLqueries[count]._tagQ = Qpart.substr(Qpart.rfind('.')+1, Qpart.find('~') - Qpart.rfind('.')-1);
		else
			HRMLqueries[count]._tagQ = Qpart.substr(0, Qpart.find('~'));
		count++;
	} while (count < Q);

	// cout << "This is tag source: " << endl;
	// cout << HRMLsource[0]._tagS << "	" << HRMLsource[1]._tagS << endl;
	// cout << HRMLsource[0]._attributeS << "	" << HRMLsource[1]._attributeS << endl;
	// cout << HRMLsource[0]._valueS << "	" << HRMLsource[1]._valueS << endl;
	// cout << HRMLsource[2]._endS << "	" << HRMLsource[3]._endS << endl;
	// cout << "This is queries: " << endl;
	// cout << HRMLqueries[0]._tagQ << "	" << HRMLqueries[0]._attributeQ << endl;
	// cout << HRMLqueries[1]._tagQ << "	" << HRMLqueries[1]._attributeQ << endl;

	for (int i=0; i<Q; i++) {
		for (int j=0; j < N/2; j++) {
			if(HRMLqueries[i]._tagQ.compare(HRMLsource[j]._tagS) == 0) {
				if(HRMLqueries[i]._attributeQ.compare(HRMLsource[j]._attributeS) == 0) {
					cout << HRMLsource[j]._valueS << endl;
				}
				else {
					cout << "Not Found!" << endl;
				}
			}
			else if(j>=N/2) cout << "Not Found!" << endl;
		}
	}

    return 0;
}
