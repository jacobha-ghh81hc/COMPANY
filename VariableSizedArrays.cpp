#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main (void)
{
    std::vector<std::vector<int>> parent;
    int n, q, k, i, j, value;
    cin >> n >> q;

    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        std::vector<int> child;

        for (int j = 0; j < k; ++j)
        {
            cin >> value;
            child.push_back(value);
        }
        parent.push_back(child);
    }                                         

    for (int i = 0; i < q; i++)
    { 
        cin >> i >> j;
        cout << parent.at(i).at(j) << endl;
    }
    return 0;
}