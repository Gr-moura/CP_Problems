/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
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

bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; i++) if (a % i == 0) return 0; return 1; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

/* clang-format on */
struct dsu
{
    vector<int> id, sz;
    int inacessiveis;

    dsu(int n) : id(n), sz(n, 1), inacessiveis(n * (n - 1) / 2) { iota(id.begin(), id.end(), 0); }

    int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }
    int getInac() { return inacessiveis; }

    void unite(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b) return;

        inacessiveis -= sz[a] * sz[b];

        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b], id[b] = a;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    struct dsu dsu(n);

    vector<pair<bool, pii>> pontes;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        pontes.push_back({1, {a, b}});
    }

    int q;
    cin >> q;
    stack<pii> pontesDestruir;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        a--;

        pontesDestruir.push(pontes[a].s);
        pontes[a].f = 0;
    }

    for (int i = 0; i < m; i++)
    {
        if (pontes[i].f) dsu.unite(pontes[i].s.f, pontes[i].s.s);
    }

    stack<int> ans;
    while (!pontesDestruir.empty())
    {
        int a = pontesDestruir.top().f;
        int b = pontesDestruir.top().s;

        ans.push(dsu.getInac());

        dsu.unite(a, b);
        pontesDestruir.pop();
    }

    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
