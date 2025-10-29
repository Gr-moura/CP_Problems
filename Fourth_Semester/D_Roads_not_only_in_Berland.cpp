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

int n;
struct DSU
{
    vi id;
    DSU(int x) : id(x, -1) {}

    int find(int x) { return id[x] <= -1 ? x : id[x] = find(id[x]); }

    void uni(int u, int v)
    {
        u = find(u), v = find(v);

        if (u == v) return;

        if (id[u] > id[v]) swap(u, v);

        if (id[u] == id[v])
        {
            id[v] = u;
            id[u]--;
        }

        else id[v] = u;
    }
};

pii addAresta(DSU &dsu)
{
    set<int> idCopy;
    for (int i = 0; i < n; i++)
    {
        idCopy.insert(dsu.find(i));
        if (idCopy.size() > 1)
        {
            return {*idCopy.begin(), *idCopy.rbegin()};
        }
    }

    return {-1, -1};
}

pii achaCiclo(vector<set<int>> &adj, vector<int> &cores, int vAtual, int pai)
{
    cores[vAtual] = 1;

    for (auto u : adj[vAtual])
    {
        if (u == pai) continue;

        if (cores[u] == 0)
        {
            pii ciclo = achaCiclo(adj, cores, u, vAtual);
            if (ciclo.f != -1)
            {
                return ciclo;
            }
        }

        if (cores[u] == 1) return {u, vAtual};
    }

    cores[vAtual] = 2;
    return {-1, -1};
}

void solve()
{
    cin >> n;

    DSU dsu(n);

    vector<set<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].insert(b);
        adj[b].insert(a);

        dsu.uni(a, b);
    }

    stringstream buffer;
    int qt = 0;

    pii novaAresta;
    do
    {
        novaAresta = addAresta(dsu);
        if (novaAresta == make_pair(-1, -1)) break;

        dsu.uni(novaAresta.f, novaAresta.s);

        vi cores(n, 0);
        pii arestaCiclo = {-1, -1};
        for (int i = 0; i < n; i++)
        {
            if (cores[i] == 0) arestaCiclo = achaCiclo(adj, cores, i, -1);
            if (arestaCiclo.f != -1) break;
        }

        adj[arestaCiclo.f].erase(arestaCiclo.s);
        adj[arestaCiclo.s].erase(arestaCiclo.f);

        qt++;
        buffer << arestaCiclo.f + 1 << " " << arestaCiclo.s + 1 << " " << novaAresta.f + 1 << " " << novaAresta.s + 1
               << endl;

    } while (1);

    cout << qt << endl;
    cout << buffer.str();
}

int32_t main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

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
