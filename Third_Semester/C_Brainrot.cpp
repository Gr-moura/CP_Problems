#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* clang-format off */
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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

vector<int> id;
vector<int> sz;

int find(int x)
{
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void uni(int x, int y)
{
    x = find(x), y = find(y);

    if (x == y) return;

    if (sz[x] > sz[y]) swap(x, y);
    id[x] = y;
    sz[y] += sz[x];
}

void solve()
{
    int n, m;
    cin >> n >> m;

    id.resize(n);
    iota(id.begin(), id.end(), 0);

    sz.resize(n, 1);

    vector<vector<int>> grupos(m);
    for (int i = 0; i < m; i++)
    {
        int coelhosNoGrupo;
        cin >> coelhosNoGrupo;

        for (int j = 0; j < coelhosNoGrupo; j++)
        {
            int coelho;
            cin >> coelho;
            coelho--;

            grupos[i].pb(coelho);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (grupos[i].size() == 0) continue;

        for (int j = 0; j < grupos[i].size(); j++)
        {
            uni(grupos[i][0], grupos[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << sz[find(i)] << " ";
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
