#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 200005;
const ll mod = 1000000007;
vector<int> ara;
vector<int> v;
vector<int> ind[N];
vector<int> seq;
int n;

int lis()
{
    v.clear();
    v.push_back(ara[0]);
    ind[0].push_back(0);
    for (int i = 1; i < n; i++) {
        int k = lower_bound(v.begin(), v.end(), ara[i]) - v.begin();
        if (k == (int) v.size()) {
            v.push_back(ara[i]);
            ind[k].push_back(i);
        }
        else {
            v[k] = ara[i];
            ind[k].push_back(i);
        }
    }
    return (int)v.size();
}

void constructionOfLIS()
{
    seq.clear();
    int l = (int) v.size();
    int lastIndex = INT_MAX;
    for (int i = l - 1; i >= 0; i--) {
        int k = lower_bound(ind[i].begin(), ind[i].end(), lastIndex) - ind[i].begin();
        lastIndex = ind[i][k - 1];
        seq.push_back(lastIndex);
    }
    reverse(seq.begin(), seq.end());
}

int main()
{
    //ara = vector<int>{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    ara = vector<int>{3, 4, 5, 1, 2, 3, 4, 5, 6, 7};
    n = ara.size();
    cout << lis() << "\n";
    constructionOfLIS();
    for (auto x : seq) {
        cout << ara[x] << " ";
    }
    cout << "\n";
    return 0;
}

/**



**/
