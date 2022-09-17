#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<typename temp>using ordered_multiset = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
 
void multiSetErase(ordered_multiset<int> &t, int v) {
    int rank = t.order_of_key(v); //Number of elements that are less than v in t
    ordered_multiset<int>::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
 
const int N = 200005;
const ll mod = 1000000007;
 
void testcase()
{
    int n, m; cin >> n >> m;
    ordered_multiset<int> st;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.insert(x);
    }
    while (m--) {
        int x; cin >> x;
        int k = st.order_of_key(x + 1);
        if (k == 0) cout << "-1\n";
        else {
            int y = *st.find_by_order(k - 1);
            cout << y << "\n";
            multiSetErase(st, y);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        //cout << "Case " << tc << ": ";
        testcase();
    }
    return 0;
}
 
/**
 
 
 
**/