#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 1000005;

int pi[N];
string s;

// shanto vai's book
void prefixFunction()
{
    int now = -1;
    pi[0] = now;
    int len = s.size();
    for (int i = 1; i < len; i++) {
        while (now != -1 && s[now + 1] != s[i]) {
            now = pi[now];
        }
        if (s[now + 1] == s[i]) pi[i] = ++now;
        else                    pi[i] = now = -1;
    }
}

// cp-algorithms
void prefix_function(string s)
{
    int n = (int) s.size();
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
}

void testcase()
{
    cin >> s;
    prefixFunction();
    int l = s.size();
    int sz = pi[l - 1];
    if (sz == -1) {
        cout << "Just a legend\n";
        return ;
    }
    for (int i = 1; i < l - 1; i++) {
        if (pi[i] == sz) {
            cout << s.substr(0, sz + 1) << "\n";
            return ;
        }
    }
    sz = pi[sz];
    if (sz == -1) {
        cout << "Just a legend\n";
        return ;
    }
    for (int i = 1; i < l - 1; i++) {
        if (pi[i] == sz) {
            cout << s.substr(0, sz + 1) << "\n";
            return ;
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}

/**



**/
