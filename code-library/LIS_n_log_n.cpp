#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int inf = 2e8;

int lisNlogK(vector<int>& seq, vector<int>& ans)
{
    int n = seq.size();
    vector<int> tail;
    int curLength = 0;
    for (int i = 0; i < n; i++) {
        int k = lower_bound(tail.begin(), tail.end(), seq[i]) - tail.begin();
        if (k == tail.size()) {
            tail.push_back(seq[i]);
            curLength++;
        }
        else {
            tail[k] = min(tail[k], seq[i]);
        }
        ans[i] = k + 1;
    }
    return curLength;
}

int main()
{
    vector<int> seq{8, 1, 9, 8, 3, 4, 6, 1, 5, 2};
    vector<int> ans(seq.size());
    cout << lisNlogK(seq, ans) << "\n";
    for (auto x : seq) {
        cout << x << " ";
    }
    cout << "\n";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

/**

4
8 1 9 8 3 4 6 1 5 2
1 1 2 2 2 3 4 1 4 2

**/
