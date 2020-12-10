#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


int main() {

    int N, count=0;
    cin >> N;
    map <string, int> StudentMap;
    map <string, int>::iterator it;

    do {
        int Qkind, QMark=0;
        string Input, QName;
        getline(cin, Input, '\n');
        stringstream extractInput(Input);
        extractInput >> Qkind >> QName >> QMark;

        switch(Qkind) {
            case 1:
            	it = StudentMap.find(QName);
                if(it != StudentMap.end()) it->second += QMark;
                else StudentMap.insert(make_pair(QName, QMark));
                break;

            case 2:
				StudentMap.erase(QName);
                break;

            case 3:
                it = StudentMap.find(QName);
                if(it != StudentMap.end()) cout << (it->second) << endl;
                else cout << 0 << endl;
                break;
        }

        count++;
    } while(count <= N);

    return 0;
}



