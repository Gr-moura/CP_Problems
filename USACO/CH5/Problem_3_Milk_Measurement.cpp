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
#define sz(a) ((int)((a).size()))
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
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
struct entry
{
    int day;
    int cow;
    int diff;
};

void solve()
{
    int n;
    cin >> n;

    vector<entry> diary(n);
    for (int i = 0; i < n; i++)
    {
        int day, diff;
        string cow;

        cin >> day >> cow >> diff;

        if (cow[0] == 'B') diary[i] = {day, 0, diff};
        if (cow[0] == 'E') diary[i] = {day, 1, diff};
        if (cow[0] == 'M') diary[i] = {day, 2, diff};
    }

    sort(all(diary), [](auto a, auto b) { return a.day < b.day; });

    vector<vi> cows(3, vi(n + 1, 7));

    int mudancas = 0;
    for (int i = 1; i <= n; i++)
    {
        int maxProd = -1;
        for (int j = 0; j < 3; j++)
            maxProd = max(maxProd, cows[j][i - 1]);

        set<int> maxCows;
        for (int j = 0; j < 3; j++)
            if (maxProd == cows[j][i - 1]) maxCows.insert(j);

        auto [day, cow, diff] = diary[i - 1];
        for (int j = 0; j < 3; j++)
        {
            if (j == cow) cows[j][i] = cows[j][i - 1] + diff;
            else cows[j][i] = cows[j][i - 1];
        }

        int maxProd2 = -1;
        for (int j = 0; j < 3; j++)
            maxProd2 = max(maxProd2, cows[j][i]);

        set<int> maxCows2;
        for (int j = 0; j < 3; j++)
            if (maxProd2 == cows[j][i]) maxCows2.insert(j);

        if (maxCows != maxCows2) mudancas++;
    }

    cout << mudancas << endl;
}

int32_t main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

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
