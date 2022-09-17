#include <bits/stdc++.h>
using namespace std;

#define    ll     long long int

const int N = 200005;
int tri[20*N][2];
int nodeCnt;

void Init(int n)
{
    nodeCnt = 0;
    for (int i = 0; i <= 20*n; i++) {
        tri[i][0] = 0;
        tri[i][1] = 0;
    }
}

void Insert(int x)
{
    int cur = 0;
    for (int i = 16; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (tri[cur][b] == 0) tri[cur][b] = ++nodeCnt;
        cur = tri[cur][b];
    }
}

int MinQuery(int x)
{
    int ans = 0, cur = 0;
    for (int i = 16; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (tri[cur][b]) cur = tri[cur][b];
        else             ans |= (1<<i), cur = tri[cur][1 - b];
    }
    return ans;
}

int MaxQuery(int x)
{
    int ans = 0, cur = 0;
    for (int i = 16; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (tri[cur][1 - b]) ans |= (1<<i), cur = tri[cur][1 - b];
        else                 cur = tri[cur][b];
    }
    return ans;
}

void testcase()
{
    int l, r; cin >> l >> r;
    vector<int> a(r - l + 1);
    Init(r - l + 1);
    for (int i = 0; i < r - l + 1; i++) {
        cin >> a[i];
        Insert(a[i]);
    }
    for (int i = 0; i < r - l + 1; i++) {
        int x = a[i] ^ l;
        int a = MinQuery(x);
        int b = MaxQuery(x);
        if (a == l && b == r) {
            cout << x << "\n";
            return ;
        }
    }
}

int main()
{
    int t = 1; cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}

