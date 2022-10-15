#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const ll base = 131;
const ll mod = 1000000007;

ll bigmod(ll a, ll b, ll mod)
{
    if (b == 0) return 1;
    ll c = bigmod(a, b / 2, mod);
    c = (c * c) % mod;
    if (b & 1) c = (c * a) % mod;
    return c;
}

vector<ll> findHash(vector<string> mat, int row)
{
    vector<ll> colHash;
    int col = mat[0].size();
    for (int j = 0; j < col; j++) {
        ll h = 0;
        for (int i = 0; i < row; i++) {
            h = (base * h + mat[i][j]) % mod;
        }
        colHash.push_back(h);
    }
    return colHash;
}

void rabin_karp(vector<string> txt, vector<string> pat)
{
    int n_row = txt.size();
    int n_col = txt[0].size();
    int m_row = pat.size();
    int m_col = pat[0].size();

    ll dr = bigmod(base, m_row - 1, mod);
    ll dc = bigmod(base, m_col - 1, mod);

    vector<ll> pat_hash = findHash(pat, m_row);
    vector<ll> txt_hash = findHash(txt, m_row);

    ll pat_val = 0;
    for (int i = 0; i < m_col; i++) {
        pat_val = (base * pat_val + pat_hash[i]) % mod;
    }

    for (int i = 0; i <= (n_row - m_row); i++) {
        ll txt_val = 0;
        for (int i = 0; i < m_col; i++) {
            txt_val = (base * txt_val + txt_hash[i]) % mod;
        }
        for (int j = 0; j <= (n_col - m_col); j++) {
            if (txt_val == pat_val) {
                cout << "Pattern found at " << (i + 1) << " " << (j + 1) << "\n";
            }

            txt_val = (txt_val - txt_hash[j] * dc) % mod;
            txt_val = (base * txt_val) % mod;
            txt_val = (txt_val + txt_hash[j + m_col]) % mod;
            if (txt_val < 0) txt_val += mod;
        }

        if (i < (n_row - m_row)) {
            for (int j = 0; j < n_col; j++) {
                txt_hash[j] = (txt_hash[j] - txt[i][j] * dr) % mod;
                txt_hash[j] = (base * txt_hash[j]) % mod;
                txt_hash[j] = (txt_hash[j] + txt[i + m_row][j]) % mod;
                if (txt_hash[j] < 0) txt_hash[j] += mod;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<string> txt{{'G', 'H', 'I', 'P'},
                       {'J', 'K', 'L', 'Q'},
                       {'R', 'G', 'H', 'I'},
                       {'S', 'J', 'K', 'L'}};

    vector<string> pat{{'G', 'H', 'I'},
                       {'J', 'K', 'L'}};

    rabin_karp(txt,pat);
    return 0;
}

/**

Input:
txt[][] = {{G, H, I, P}
           {J, K, L, Q}
           {R, G, H, I}  
           {S, J, K, L}
          }
pat[][] = {{G, H, I},
           {J, K, L}
          }
Output:
Pattern found at ( 1, 1 )
Pattern found at ( 3, 2 )

**/
