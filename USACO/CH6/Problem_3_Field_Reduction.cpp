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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

void solve()
{
    int n;
    cin >> n;

    pii minX{LINF, 0}, min2X{LINF, 0};
    pii minY{LINF, 0}, min2Y{LINF, 0};
    pii maxX{-LINF, 0}, max2X{-LINF, 0};
    pii maxY{-LINF, 0}, max2Y{-LINF, 0};

    vector<pii> cows;
    vi x, y;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        x.pb(a), y.pb(b);
        cows.eb(a, b);
    }

    sort(all(x)), sort(all(y));
    minX = {x[0], 1}, min2X = {x[1], 1};
    maxX = {x[n - 1], 1}, max2X = {x[n - 2], 1};
    minY = {y[0], 1}, min2Y = {y[1], 1};
    maxY = {y[n - 1], 1}, max2Y = {y[n - 2], 1};

    // Area = (maxX - minY) * (maxY - minY)
    // Basta achar o maior X, Y e o menor X, Y sem aquela vaca

    // Guardar os dois menores x, y e os dois maiores x,y

    int ans = LINF;
    for (int i = 0; i < n; i++)
    {
        int mx = minX.first, my = minY.first;
        int Mx = maxX.first, My = maxY.first;

        if (cows[i].first == mx && minX.second == 1) mx = min2X.first;
        if (cows[i].first == Mx && maxX.second == 1) Mx = max2X.first;

        if (cows[i].second == my && minY.second == 1) my = min2Y.first;
        if (cows[i].second == My && maxY.second == 1) My = max2Y.first;

        ans = min(ans, abs((Mx - mx) * (My - my)));
    }

    cout << ans << endl;
}

int32_t main()
{
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

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
