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

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
vector<vector<int>> divs(MAX);

void preencherDivs(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j != 0) continue;

            divs[i].pb(j);
            if (j * j != i) divs[i].pb(i / j);
        }
    }
}

// Você consegue um gcd x do split se você for 3x ou >= 4x
void solve()
{
    int n, k;
    cin >> n >> k;

    // Difference array de 0 até n - 1
    vi da(n, 0);
    vi qt(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        da[0]++;

        if (n != 1) da[a / 4 + 1]--;

        for (auto j : divs[a])
            if (j > a / 4) qt[j]++;
    }

    partial_sum(all(da), da.begin());

    for (int i = 0; i < n; i++)
    {
        qt[i] += da[i];
    }

    for (int i = n; i >= 0; i--)
    {
        if (qt[i] >= n - k)
        {
            cout << i << endl;
            return;
        }
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
    cout.tie(0);

    int t = 1;
    cin >> t;

    preencherDivs(MAX);

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
