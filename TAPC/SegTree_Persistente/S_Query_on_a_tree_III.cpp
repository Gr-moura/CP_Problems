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

struct Vertex
{
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
    {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex *build(int tl, int tr)
{
    if (tl == tr) return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm + 1, tr));
}

Vertex *update(Vertex *v, int tl, int tr, int pos)
{
    if (tl == tr) return new Vertex(v->sum + 1);
    int tm = (tl + tr) / 2;
    if (pos <= tm) return new Vertex(update(v->l, tl, tm, pos), v->r);
    else return new Vertex(v->l, update(v->r, tm + 1, tr, pos));
}

int find_kth(Vertex *vl, Vertex *vr, int tl, int tr, int k)
{
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
    if (left_count >= k) return find_kth(vl->l, vr->l, tl, tm, k);
    return find_kth(vl->r, vr->r, tm + 1, tr, k - left_count);
}

vector<vector<int>> g(MAX);
vi euler;

map<int, pii> subtree;
vi pos(MAX, 0);

int timer = 0;
void dfs(int v, int p)
{
    subtree[v].first = timer++;
    euler.pb(v);

    for (auto u : g[v])
        if (u != p) dfs(u, v);

    subtree[v].second = timer++;
    euler.pb(v);
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);

    vector<pii> labelToIndex(n);
    for (int i = 0; i < n; i++)
    {
        int label;
        cin >> label;

        labelToIndex[i] = {label, i};
    }

    sort(all(labelToIndex));

    for (int i = 0; i < n; i++)
        pos[labelToIndex[i].second] = i;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1);

    int m = euler.size();
    vector<Vertex *> version(m + 1);
    version[0] = build(0, n - 1);

    for (int i = 0; i < m; i++)
    {
        int u = euler[i];
        int valPos = pos[u];

        version[i + 1] = update(version[i], 0, n - 1, valPos);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int v, k;
        cin >> v >> k;
        v--;
        k *= 2;

        int l = subtree[v].first;
        int r = subtree[v].second;

        int idx = find_kth(version[l], version[r + 1], 0, n - 1, k);
        cout << labelToIndex[idx].second + 1 << endl;
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
