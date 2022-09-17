const int N = 1000006;
int isPrime[N];
vector<int> primes;

void seive(int n)
{
    for (int i = 4; i <= n; i += 2) {
        isPrime[i] = 1;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (isPrime[i] == 0) {
            for (int j = i * i; j <= n; j += 2 * i) {
                isPrime[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2) {
        if (isPrime[i] == 0) {
            primes.push_back(i);
        }
    }
}