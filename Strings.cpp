#include <iostream>
#include <string>
using namespace std;

int main() {

	string a, b;
	getline(cin,a,'\n');
	getline(cin,b,'\n');

	cout << a.length() << ' ' << b.length() << endl;
	cout << a+b << endl;
	string d = a;
	cout << a.replace(0,1,b,0,1) << ' ' << b.replace(0,1,d,0,1) << endl;
  
    return 0;
}