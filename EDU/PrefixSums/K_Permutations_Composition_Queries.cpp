/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int n, m;
vi somar(vi &X, vi &Y)
{
    vi Z(m);
    for (int i = 0; i < m; i++)
        Z[i] = Y[X[i] - 1];

    return Z;
}

vi inverso(vi &V)
{
    vi V1(m);
    for (int i = 0; i < m; i++)
        V1[V[i] - 1] = i + 1;

    return V1;
}

void solve()
{
    cin >> n >> m;

    vector<vi> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vi> ps(n + 1, vi(m));
    vector<vi> rs(n + 1, vi(m));
    for (int i = 1; i <= m; i++)
        rs[0][i - 1] = ps[0][i - 1] = i;

    for (int i = 1; i <= n; i++)
    {
        ps[i] = somar(ps[i - 1], a[i - 1]);
        rs[i] = inverso(ps[i]);
    }

    int q;
    cin >> q;

    map<pii, int> resposta;
    for (int i = 0; i < q; i++)
    {
        int out = 0;

        int l, r;
        cin >> l >> r;
        l--, r--;

        if (resposta.count({l, r}))
        {
            cout << resposta[{l, r}] << endl;
            continue;
        }

        vi ans = somar(rs[l], ps[r + 1]);
        for (int i = 1; i <= m; i++)
        {
            out += ans[i - 1] * i;
        }

        resposta[{l, r}] = out;

        cout << out << endl;
    }
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
