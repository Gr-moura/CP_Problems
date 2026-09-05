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
const int LINF = LLONG_MAX;
/* clang-format on */

struct point
{
    int x, y;
    point() : x(LINF), y(LINF) {}
    point(int x, int y) : x(x), y(y) {}
    point(int x) : x(x), y(x) {}

    bool empty() { return x == LINF && y == LINF; }

    bool operator==(const point &other) const { return x == other.x && y == other.y; }
    bool operator!=(const point &other) const { return !(*this == other); }
};

int area(point a, point b, point c, point d)
{
    int minX = min({a.x, b.x, c.x, d.x});
    int minY = min({a.y, b.y, c.y, d.y});
    int maxX = max({a.x, b.x, c.x, d.x});
    int maxY = max({a.y, b.y, c.y, d.y});

    return (maxX - minX + 1) * (maxY - minY + 1);
}

void solve()
{
    int n;
    cin >> n;

    vector<point> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        m.eb(x, y);
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    vector<point> x = m;
    sort(all(x), [&](const point &a, const point &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<point> y = m;
    sort(all(y), [&](const point &a, const point &b) {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });

    int ans = area(x[0], x[n - 1], y[0], y[n - 1]);

    point retirado = x[0];
    point a = x[1], b = x.back(), c = y[0], d = y.back();

    if (retirado == y.back()) d = y[y.size() - 2];
    if (retirado == x.back()) b = x[x.size() - 2];
    else
    {
        int minX = min({a.x, b.x, c.x, d.x});
        int minY = min({a.y, b.y, c.y, d.y});
        int maxX = max({a.x, b.x, c.x, d.x});
        int maxY = max({a.y, b.y, c.y, d.y});

        ans = min(ans, (maxX - minX + 2) * (maxY - minY + 1));
        ans = min(ans, (maxX - minX + 1) * (maxY - minY + 2));
    }

    int areaTmp = area(a, b, c, d);
    if (areaTmp >= n) ans = min(ans, areaTmp);

    retirado = x.back();
    a = x[0], b = x[n - 2], c = y[0], d = y.back();

    if (retirado == y[0]) c = y[1];
    if (retirado == y.back()) d = y[y.size() - 2];

    areaTmp = area(a, b, c, d);
    if (areaTmp >= n) ans = min(ans, areaTmp);
    else
    {
        int minX = min({a.x, b.x, c.x, d.x});
        int minY = min({a.y, b.y, c.y, d.y});
        int maxX = max({a.x, b.x, c.x, d.x});
        int maxY = max({a.y, b.y, c.y, d.y});

        ans = min(ans, (maxX - minX + 2) * (maxY - minY + 1));
        ans = min(ans, (maxX - minX + 1) * (maxY - minY + 2));
    }

    retirado = y[0];
    a = x[0], b = x.back(), c = y[1], d = y.back();
    if (retirado == x[0]) a = x[1];
    if (retirado == x.back()) b = x[x.size() - 2];

    areaTmp = area(a, b, c, d);
    if (areaTmp >= n) ans = min(ans, areaTmp);
    else
    {
        int minX = min({a.x, b.x, c.x, d.x});
        int minY = min({a.y, b.y, c.y, d.y});
        int maxX = max({a.x, b.x, c.x, d.x});
        int maxY = max({a.y, b.y, c.y, d.y});

        ans = min(ans, (maxX - minX + 2) * (maxY - minY + 1));
        ans = min(ans, (maxX - minX + 1) * (maxY - minY + 2));
    }

    retirado = y.back();
    a = x[0], b = x.back(), c = y[0], d = y[y.size() - 2];
    if (retirado == x[0]) a = x[1];
    if (retirado == x.back()) b = x[x.size() - 2];

    areaTmp = area(a, b, c, d);
    if (areaTmp >= n) ans = min(ans, areaTmp);
    else
    {
        int minX = min({a.x, b.x, c.x, d.x});
        int minY = min({a.y, b.y, c.y, d.y});
        int maxX = max({a.x, b.x, c.x, d.x});
        int maxY = max({a.y, b.y, c.y, d.y});

        ans = min(ans, (maxX - minX + 2) * (maxY - minY + 1));
        ans = min(ans, (maxX - minX + 1) * (maxY - minY + 2));
    }

    cout << ans << endl;
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
