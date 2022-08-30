

ll ceil(ll a, ll b)
{
    ll d = a / b;
    if (a % b) d++;
    return d;
}


std::vector<int> V;
// (fill V with values)
std::sort(V.begin(), V.end());

int numValsLessThan5 = std::lower_bound(V.begin(), V.end(), 5) - V.begin();
int numValsLessThanOrEqualTo5 = std::upper_bound(V.begin(), V.end(), 5) - V.begin();


// taking unique values
sort(v.begin(), v.end());
auto it = unique(v.begin(), v.end());  
v.resize(distance(v.begin(), it)); 

// std::mt19937 (since C++11) class is a very efficient pseudo-random number generator and is defined in a random header file.
mt19937 rnd(time(NULL)); // declaration
int get_a_random_number = rnd(); // use
shuffle(ans.begin(), ans.end(), rnd); // random shuffle

// sort with inline compare function (lambda)
array<int, 10> vec = { 1,1,2,3,4,5,6,7,8,9 };
sort(vec.begin(), vec.end(), [](int a, int b) {
    return a > b;
});

int n = 5, m = -5;
bitset<8> b(n);
bitset<8> b1(m);
cout << "Binary of 5:" << b << endl; // 
cout << "Binary of -5:" << b1 << endl;

Output:
Binary of 5:00000101
Binary of -5:11111011


~0 = 111111111111...111