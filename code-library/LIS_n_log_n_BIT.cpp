#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int inf = 2e8;
const int N = 500005;
int bit[N];

void init(int n)
{
    for (int i = 0; i <= n; i++) {
        bit[i] = 0;
    }
}

int query(int r)
{
    int res = 0;
    for ( ; r >= 0; r = (r & (r + 1)) - 1) {
        res = max(res, bit[r]);
    }
    return res;
}

void add(int idx, int n, int val)
{
    for ( ; idx <= n; idx = idx | (idx + 1)) {
        bit[idx] = max(bit[idx], val);
    }
}

int lisBIT(vector<int>& seq, vector<int>& ans)
{
    int n = seq.size();
    init(n);
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        int k = query(seq[i] - 1);
        ans[i] = k + 1;
        add(seq[i], n, ans[i]);
        maxLength = max(maxLength, ans[i]);
    }
    return maxLength;
}

int lisBIT_reverse(vector<int>& seq, vector<int>& ans)
{
    int n = seq.size();
    init(n);
    int maxLength = 0;
    for (int i = n - 1; i >= 0; i--) {
        int k = query(n - seq[i]);
        ans[i] = k + 1;
        add(n - seq[i] + 1, n, ans[i]);
        maxLength = max(maxLength, ans[i]);
    }
    return maxLength;
}

int main()
{
    vector<int> seq{8, 1, 9, 8, 3, 4, 6, 1, 5, 2};
    vector<int> ans(seq.size());
    cout << lisBIT(seq, ans) << "\n";
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

usual
-----
4
8 1 9 8 3 4 6 1 5 2
1 1 2 2 2 3 4 1 4 2

reverse
-------
4
8 1 9 8 3 4 6 1 5 2
2 4 1 1 3 2 1 2 1 1


**/
