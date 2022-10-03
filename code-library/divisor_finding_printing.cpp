const int N = 200005;
vector<int> divs[N];

void find_factors(int n)
{
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                divs[i].push_back(j);
                if (j != i / j) divs[i].push_back(i / j);
            }
        }
        sort(divs[i].begin(), divs[i].end());
    }
}

void print_factors(int n)
{
    cout << n << ": [ ";
    for (auto x : divs[n]) {
        cout << x << " ";
    }
    cout << "]";
}