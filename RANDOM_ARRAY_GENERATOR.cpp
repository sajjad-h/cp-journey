#include <bits/stdc++.h>
using namespace std;


vector<int> random_array(int N)
{
	//Random Number Generator
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> permutation(N);
    for (int i = 0; i < N; i++) permutation[i] = rand() % 50;
    shuffle(permutation.begin(), permutation.end(), rng);
    return permutation;
}

int main()
{
	freopen("input.txt", "w", stdout);
	srand(time(0));
	int t = 10; cout << t << '\n';
	while (t--) {
		int n = rand() % 10;
		vector<int> v = random_array(n);
		cout << n << '\n';
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

