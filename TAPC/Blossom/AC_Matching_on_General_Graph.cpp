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

const int MOD = 1e9 + 7, MAX = 500 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
// Blossom
//
// Matching maximo em grafo geral
//
// O(n^3)
// Se for bipartido, nao precisa da funcao
// 'contract', e roda em O(nm)

vector<int> g[MAX];
int match[MAX]; // match[i] = com quem i esta matchzado ou -1
int n, pai[MAX], base[MAX], vis[MAX];
queue<int> q;

void contract(int u, int v, bool first = 1)
{
    static vector<bool> bloss;
    static int l;
    if (first)
    {
        bloss = vector<bool>(n, 0);
        vector<bool> teve(n, 0);
        int k = u;
        l = v;
        while (1)
        {
            teve[k = base[k]] = 1;
            if (match[k] == -1) break;
            k = pai[match[k]];
        }
        while (!teve[l = base[l]])
            l = pai[match[l]];
    }
    while (base[u] != l)
    {
        bloss[base[u]] = bloss[base[match[u]]] = 1;
        pai[u] = v;
        v = match[u];
        u = pai[match[u]];
    }
    if (!first) return;
    contract(v, u, 0);
    for (int i = 0; i < n; i++)
        if (bloss[base[i]])
        {
            base[i] = l;
            if (!vis[i]) q.push(i);
            vis[i] = 1;
        }
}

int getpath(int s)
{
    for (int i = 0; i < n; i++)
        base[i] = i, pai[i] = -1, vis[i] = 0;
    vis[s] = 1;
    q = queue<int>();
    q.push(s);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i : g[u])
        {
            if (base[i] == base[u] or match[u] == i) continue;
            if (i == s or (match[i] != -1 and pai[match[i]] != -1)) contract(u, i);
            else if (pai[i] == -1)
            {
                pai[i] = u;
                if (match[i] == -1) return i;
                i = match[i];
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return -1;
}

int blossom()
{
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < n; i++)
        if (match[i] == -1)
            for (int j : g[i])
                if (match[j] == -1)
                {
                    match[i] = j;
                    match[j] = i;
                    ans++;
                    break;
                }
    for (int i = 0; i < n; i++)
        if (match[i] == -1)
        {
            int j = getpath(i);
            if (j == -1) continue;
            ans++;
            while (j != -1)
            {
                int p = pai[j], pp = match[p];
                match[p] = j;
                match[j] = p;
                j = pp;
            }
        }
    return ans;
}

void solve()
{
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << blossom() << endl;

    for (int i = 0; i < n; i++)
    {
        if (i < match[i]) cout << i << " " << match[i] << endl;
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
