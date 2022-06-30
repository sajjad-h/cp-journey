#include <bits/stdc++.h>
using namespace std;

struct node
{
    int end;
    int child[26];

    node( )
    {
        end = 0;
        memset(child, -1, sizeof(child));
    }
};

int avail = 0;
node tr[1000005];

void insert(string s)
{
    int cur, i, x;

    cur = 0;
    for (i = 0; i < s.size( ); i++)
    {
        x = s[i] - 'a';
        if (tr[cur].child[x] == -1)
        {
            tr[cur].child[x] = ++avail;
        }
        cur = tr[cur].child[x];
    }

    tr[cur].end++;

    return ;
}

int query(string s)
{
    int cur, i, x;

    cur = 0;
    for (i = 0; i < s.size( ); i++)
    {
        x = s[i] - 'a';
        if (tr[cur].child[x] == -1)
        {
            return 0;
        }
        cur = tr[cur].child[x];
    }

    return tr[cur].end;
}

int main( )
{
    string s;
    
    int m, n;
    
    cin >> m;
    
    while (m--)
	{
		cin >> s;
		insert(s);
	}
	
	cin >> n;
	
	while (n--)
	{
		cin >> s;
		cout << query(s) << endl;
	}

    return 0;
}
