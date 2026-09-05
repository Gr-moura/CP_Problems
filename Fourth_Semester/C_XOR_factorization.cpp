/*
ID: gabriel139
LANG: C++
TASK: test
*/

/* clang-format off */
#include <bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back

// Índice base 0 do primeiro elemento maior ou igual a x em log n
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())

// Índice base 0 do primeiro elemento  estritamente maior que x em log n
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

int maxSumOut = 0, maxSum = 0;
int n, k;
multiset<int> vals;
void backtrack(int depth)
{
    if (depth == k)
    {
        int sum = 0;
        int xorsum = 0;
        for (auto i : vals)
            sum += i, xorsum ^= i;
        if (xorsum == n and sum > maxSum)
        {
            maxSumOut = max(maxSumOut, sum);
            dbg(maxSumOut);

            for (auto i : vals)
                cout << i << " ";
            cout << endl;
            cout << "----" << endl;
        }

        return;
    }

    for (int i = 0; i <= n; i++)
    {
        vals.insert(i);
        backtrack(depth + 1);
        vals.erase(vals.find(i));
    }
}

void solve()
{
    cin >> n >> k;

    if (k % 2 == 1)
    {
        for (int i = 0; i < k; i++)
        {
            cout << n << " ";
        }

        cout << endl;
        return;
    }

    int pop = __builtin_popcountll(n);
    if (k < pop or pop == 1)
    {
        for (int i = 0; i < k - 1; i++)
            cout << n << " ";

        cout << 0 << endl;
        return;
    }

    vi fact;
    for (int i = 0; i <= 32; i++)
        if (n & (1ll << i)) fact.pb(1ll << i);

    int maxSum = n * (k - 1);
    int newSum = n * (k - pop);

    int somaAtual = n - 1;
    int index = 0;

    int xorsum = 0;
    for (int i = 0; i <= 32; i++)
    {
        if (n & (1ll << i))
        {
            newSum += somaAtual;
            xorsum ^= somaAtual;
            if (index + 1 < (int)fact.size()) somaAtual += (fact[index] - fact[++index]);
        }
    }

    if (newSum > maxSum and xorsum == n)
    {

        for (int i = 0; i < k - pop; i++)
            cout << n << " ";

        index = 0;
        somaAtual = n - 1;
        for (int i = 0; i <= 32; i++)
        {
            if (n & (1ll << i))
            {
                cout << somaAtual << " ";
                if (index + 1 < (int)fact.size()) somaAtual += (fact[index] - fact[++index]);
            }
        }

        cout << endl;
    }

    else
    {
        for (int i = 0; i < k - 1; i++)
            cout << n << " ";

        cout << 0 << endl;
    }
}

int32_t main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
