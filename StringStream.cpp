#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> parseInts(string str) {
    int outNum;
    char outCh;
    vector<int> outVec;
    stringstream outSs(str);
    do {
        outSs >> outNum >> outCh;
        outVec.push_back(outNum);
    } while(outSs);
    return outVec;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
