// Problem: https://codeforces.com/contest/1591/problem/D
// Ordered Set (PBDS), inversion counting

#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

template<typename temp>using ordered_multiset = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

void multiSetErase(ordered_multiset<int> &t, int v) {
    int rank = t.order_of_key(v); //Number of elements that are less than v in t
    ordered_multiset<int>::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}

#define   ll    long long int

int n;
const int N = 500005;
int ara[N];
ordered_set<int> st;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> mp;
        int yes = 0;
        for (int i = 0; i < n; i++) {
            cin >> ara[i];
            mp[ara[i]]++;
            if (mp[ara[i]] > 1) {
                yes = 1;
            }
        }
        if (yes) {
            cout << "YES\n";
            continue;
        }
        ll s = 0;
        ordered_set<int> st;
        for (int i = 0; i < n; i++) {
            ll cnt = st.size() - st.order_of_key(ara[i]);
            s += cnt;
            st.insert(ara[i]);
        }
        if (s % 2 == 0) cout << "YES\n";
        else            cout << "NO\n";
    }
    return 0;
}
