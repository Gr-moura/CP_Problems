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

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 5e4 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

bitset<MAX> state;         // ON/OFF
vector<set<int>> adj(MAX); // Apenas os vizinhos com grau maior que u na hora de inserir
vector<int> ans(MAX); // Soma dos vizinhos que não estão em adj[u] (ou seja, que tinham grau menor na hora de inserir)

void add(int u, int v)
{
    if (adj[u].size() > adj[v].size()) swap(u, v);

    adj[u].insert(v);   // Armazenamos o de maior grau no de menor grau
    ans[v] += state[u]; // Atualizamos a contribuição de v
}

void del(int u, int v)
{
    // Se u estiver em adj[v], então não é considerado em ans[v]
    if (adj[v].count(u))
    {
        adj[v].erase(u);
        ans[u] -= state[v];
    }

    else
    {
        adj[u].erase(v);
        ans[v] -= state[u];
    }
}

int count(int u)
{
    int sum = ans[u];
    for (auto i : adj[u])
        sum += state[i];

    return sum;
}

void online(int u)
{
    state[u] = 1;

    // Se está na adj[u], então u não aparece em ans[i];
    for (auto i : adj[u])
        ans[i]++;
}

void offline(int u)
{
    state[u] = 0;

    // Se está na adj[u], então u não aparece em ans[i];
    for (auto i : adj[u])
        ans[i]--;
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    int o;
    cin >> o;
    for (int i = 0; i < o; i++)
    {
        int temp;
        cin >> temp;

        state[temp] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        add(u, v);
    }

    for (int i = 0; i < q; i++)
    {
        string tipo;
        int u, v;

        cin >> tipo;

        if (tipo == "O")
        {
            cin >> u;
            online(u);
        }

        else if (tipo == "F")
        {
            cin >> u;
            offline(u);
        }

        else if (tipo == "A")
        {
            cin >> u >> v;
            add(u, v);
        }

        else if (tipo == "D")
        {
            cin >> u >> v;
            del(u, v);
        }

        else if (tipo == "C")
        {
            cin >> u;
            cout << count(u) << endl;
        }
    }
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
