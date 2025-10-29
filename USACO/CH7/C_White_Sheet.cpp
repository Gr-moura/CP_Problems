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
struct figure
{
    int x1, y1;
    int x2, y2;

    figure(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

bool inside(double x1, double y1, figure b)
{
    if (x1 < b.x1) return false;
    if (y1 < b.y1) return false;

    if (x1 > b.x2) return false;
    if (y1 > b.y2) return false;

    return true;
}

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    figure a(x1, y1, x2, y2);

    cin >> x1 >> y1 >> x2 >> y2;
    figure b(x1, y1, x2, y2);

    cin >> x1 >> y1 >> x2 >> y2;
    figure c(x1, y1, x2, y2);

    // Ver se algum dos pontos no perímetro está contido
    for (double x = a.x1; x <= a.x2; x += 0.5)
    {
        if (!inside(x, a.y1, b) and !inside(x, a.y1, c))
        {
            cout << "YES\n";
            return;
        }

        if (!inside(x, a.y2, b) and !inside(x, a.y2, c))
        {
            cout << "YES\n";
            return;
        }
    }

    for (double y = a.y1; y <= a.y2; y += 0.5)
    {
        if (!inside(a.x1, y, b) and !inside(a.x1, y, c))
        {
            cout << "YES\n";
            return;
        }

        if (!inside(a.x2, y, b) and !inside(a.x2, y, c))
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
