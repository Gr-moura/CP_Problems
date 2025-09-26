/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int unsigned int
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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = pow(2, 32), MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
const int n = pow(2, 24);
vector<int> diff(n, 0);

int a, b;    // даны во входных данных
int cur = 0; // беззнаковое 32-битное число

int nextRand()
{
    cur = cur * a + b; // вычисляется с переполнениями
    return cur >> 8;   // число от 0 до 2^24 - 1.
}

tuple<int, int, int> mQuery()
{
    int adding = nextRand(); // число, которое нужно прибавить
    int l = nextRand();
    int r = nextRand();
    if (l > r) swap(l, r); // получили отрезок [l..r]
    return {l, r, adding};
}

pii qQuery()
{
    int l = nextRand();
    int r = nextRand();
    if (l > r) swap(l, r); // получили отрезок [l..r]
    return {l, r};
}

void solve()
{
    int m, q;
    cin >> m >> q;
    cin >> a >> b;

    for (int i = 0; i < m; i++)
    {
        auto [l, r, d] = mQuery();

        diff[l] += d;
        if (r + 1 < n) diff[r + 1] -= d;
    }

    partial_sum(all(diff), diff.begin());

    vector<int> ps(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ps[i] = (ps[i - 1] + diff[i - 1]) % MOD;
    }

    int ans = 0;
    for (int i = 0; i < q; i++)
    {
        auto [l, r] = qQuery();
        ans += (ps[r + 1] - ps[l]) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}

int32_t main()
{
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
