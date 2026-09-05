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

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
vector<vi> g(MAX);
vi pai(MAX);
vi sums(MAX);
vi values(MAX);
int sum = 0ll;
bool BFS(int vInicial)
{
    queue<int> q;
    for (auto u : g[vInicial])
        q.push(u);

    while (!q.empty())
    {
        int topo = q.front();
        q.pop();

        if (sums[topo] >= 0ll)
        {
            values[topo] = sums[topo] - sums[pai[topo]];
            if (values[topo] < 0ll) return false;
            sum += values[topo];

            for (auto u : g[topo])
                q.push(u);

            continue;
        }

        // Deve ser o mínimo da diferença entre o pai e os filhos
        int minimo = g[topo].empty() ? 0ll : LINF;
        for (int u : g[topo])
        {
            minimo = min(minimo, sums[u] - sums[pai[topo]]);
            if (minimo < 0ll) return false;
        }

        sums[topo] = sums[pai[topo]] + minimo;
        sum += minimo;

        for (auto u : g[topo])
            q.push(u);
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int v;
        cin >> v;
        v--;

        g[v].pb(i);
        pai[i] = v;
    }

    for (int i = 0; i < n; i++)
        cin >> sums[i];

    sum += sums[0];

    if (!BFS(0)) sum = -1;
    cout << sum << endl;
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
