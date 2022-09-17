#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 200005;
const ll mod = 1000000007;
const int base = 1000*1000*1000;

string minBetween(string a, string b) {
    int la = (int) a.size();
    int lb = (int) b.size();
    if (la < lb) return a;
    else if (la > lb) return b;
    for (int i = 0; i < la; i++) {
        if (a[i] == b[i]) continue;
        else if (a[i] < b[i]) return a;
        else return b;
    }
    assert(false);
}

vector<int> stringToDigits(string s) {
    vector<int> a;
    for (int i=(int)s.length(); i>0; i-=9)
        if (i < 9)
            a.push_back (atoi (s.substr (0, i).c_str()));
        else
            a.push_back (atoi (s.substr (i-9, 9).c_str()));
    return a;
}

string digitsToString(vector<int> a)
{
    string ans = "";
    if (a.empty()) {
        ans.push_back('0');
    }
    else {
        int fl = 1;
        for (int i = (int) a.size() - 1; i >= 0; i--) {
            vector<int> ds;
            while (a[i]) {
                ds.push_back(a[i] % 10);
                a[i] /= 10;
            }
            while (ds.size() < 9) ds.push_back(0);
            reverse(ds.begin(), ds.end());
            for (auto x : ds) {
                if (fl && x == 0) continue;
                else ans.push_back(x + '0'), fl = 0;
            }
        }
    }
    return ans;
}

string Sum(string sa, string sb) {
    vector<int> a = stringToDigits(sa);
    vector<int> b = stringToDigits(sb);
    int carry = 0;
    for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if (carry)  a[i] -= base;
    }
    string ans = digitsToString(a);
    return ans;
}

void testcase() {
    int l;
    cin >> l;
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i <= 2*l; i++) {
        ans.push_back('9');
    }
    int mid = l / 2;
    if (s[mid] == '0') {
        while (mid < l && s[mid] == '0') {
            mid++;
        }
        if (mid != l) {
            ans = minBetween(ans, Sum(s.substr(0, mid), s.substr(mid, l - mid)));
        }
        mid--;
        while (mid >= 1 && s[mid] == '0') {
            mid--;
        }
        if (mid >= 1) {
            ans = minBetween(ans, Sum(s.substr(0, mid), s.substr(mid, l - mid)));
        }
    } else {
        ans = minBetween(ans, Sum(s.substr(0, mid), s.substr(mid, l - mid)));
        if (mid - 1 > 0 && s[mid - 1] != '0') {
            ans = minBetween(ans, Sum(s.substr(0, mid - 1), s.substr(mid - 1, l - mid + 1)));
        }
        if (mid + 1 < l && s[mid + 1] != '0') {
            ans = minBetween(ans, Sum(s.substr(0, mid + 1), s.substr(mid + 1, l - mid - 1)));
        }
    }
    cout << ans << "\n";
}

int main() {
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
