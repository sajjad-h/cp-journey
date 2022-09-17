

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

// Convert integer to String
stringstream convert;
convert << number;
string s = convert.str();

// Convert integer to string
string a = to_string(l);

// Convert string to integer
ll to_integer(string sa)
{
    ll res = 0;
    for (auto ch : sa) {
        res = res * 10 + (ch - '0');
    }
    return res;
}


/**

# searching a pair in a set 

Suppose we have a range (1, 8).
We want to split it at 3 such that (1, 3) and (4, 8).

**/
int x, n; cin >> x >> n;
vector<int> a(n);
for (auto &x : a) cin >> x;
set< pair<int, int> > st;
st.insert({1, x});
map<int, int> mp;
mp[x]++;
for (auto x : a) {
    auto it = st.lower_bound({x, INT_MAX}); it--;
    auto [u, v] = *it;
    mp[v - u + 1]--;
    if (mp[v - u + 1] == 0) mp.erase(v - u + 1);
    st.erase({u, v});
    st.insert({u, x});
    st.insert({x + 1, v});
    mp[x - u + 1]++;
    mp[v - x]++;
    cout << (*mp.rbegin()).first << " ";
}
cout << "\n";

