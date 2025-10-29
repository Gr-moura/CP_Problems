/*
ID: gabriel139
LANG: C++
TASK: combo
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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int mod(int x, int b)
{
    if (x < 0) return ((x + b) % b);
    return x % b;
}

void solve()
{
    int n;
    cin >> n;

    vi a(3), b(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> b[i];
        b[i]--;
    }

    map<int, set<int>> posA, posB;
    set<tuple<int, int, int>> ans;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            posA[a[i]].insert(mod(a[i] - j, n));
            posA[a[i]].insert(mod(a[i] + j, n));
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            posB[b[i]].insert(mod((b[i]) - j, n));
            posB[b[i]].insert(mod((b[i]) + j, n));
        }
    }

    for (auto el0 : posA[a[0]])
        for (auto el1 : posA[a[1]])
            for (auto el2 : posA[a[2]])
                ans.emplace(el0, el1, el2);

    for (auto el0 : posB[b[0]])
        for (auto el1 : posB[b[1]])
            for (auto el2 : posB[b[2]])
                ans.emplace(el0, el1, el2);

    cout << ans.size() << endl;
}

int32_t main()
{
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);

    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
