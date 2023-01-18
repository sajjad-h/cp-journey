/**
 * Link: https://cses.fi/problemset/task/1190/
*/

#include <bits/stdc++.h>
using namespace std;

#define             ll          long long int

struct data
{
    ll presum, sufsum, maxsum, fulsum;
};

const int N = 200005;
ll a[N];
data seg[4 * N];

void build(int node, int s, int e)
{
    if (s == e)
    {
        seg[node] = { a[s], a[s], a[s], a[s] };
        return ;
    }

    int mid, left, right;
    mid = (s + e) / 2;
    left = 2 * node;
    right = left + 1;

    build(left, s, mid);
    build(right, mid + 1, e);

    seg[node].presum = max( seg[left].presum, seg[left].fulsum + seg[right].presum );
    seg[node].sufsum = max( seg[right].sufsum, seg[right].fulsum + seg[left].sufsum );
    seg[node].maxsum = max( seg[left].maxsum, max( seg[right].maxsum, seg[left].sufsum + seg[right].presum ));
    seg[node].fulsum = seg[left].fulsum + seg[right].fulsum;

    max( seg[left].fulsum + seg[right].presum, seg[right].fulsum + seg[left].sufsum );

    return ;
}

data Merge(data left, data right)
{
    data tm;
    tm.presum = max( left.presum, left.fulsum + right.presum );
    tm.sufsum = max( right.sufsum, right.fulsum + left.sufsum );
    tm.maxsum = max( left.maxsum, max( right.maxsum, left.sufsum + right.presum ));
    tm.fulsum = left.fulsum + right.fulsum;
    return tm;
}
data query(int node, int s, int e, int l, int r)
{
    if (l <= s && e <= r)       return seg[node];

    int mid, left, right;
    mid = (s + e) / 2;
    left = 2 * node;
    right = left + 1;

    if (r <= mid)       return query(left, s, mid, l, r);
    else if (l > mid)   return query(right, mid + 1, e, l, r);
    else
    {
        return Merge(query(left, s, mid, l, r), query(right, mid + 1, e, l, r));
    }
}
void update(int node, int s, int e, int i, ll x)
{
    if (s == e)
    {
        a[s] = x;
        seg[node] = { x, x, x, x };
        return ;
    }

    int mid, left, right;
    mid = (s + e) / 2;
    left = 2 * node;
    right = left + 1;

    if (i <= mid)       update(left, s, mid, i, x);
    else                update(right, mid + 1, e, i, x);

    seg[node].presum = max( seg[left].presum, seg[left].fulsum + seg[right].presum );
    seg[node].sufsum = max( seg[right].sufsum, seg[right].fulsum + seg[left].sufsum );
    seg[node].maxsum = max( seg[left].maxsum, max( seg[right].maxsum, seg[left].sufsum + seg[right].presum ));
    seg[node].fulsum = seg[left].fulsum + seg[right].fulsum;

    return ;
}

int main( )
{
    int n, i, j, q, l, r, op;
    ll x;
    data tm;

    scanf("%d %d", &n, &q);

    for (i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    build(1, 1, n);

    while (q--)
    {
        scanf("%d %lld", &i, &x);
        update(1, 1, n, i, x);
        printf("%lld\n", max(0LL, query(1, 1, n, 1, n).maxsum));
    }
    return 0;
}
