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
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
// SegTree Beats
//
// query(a, b) - {{min(v[a..b]), max(v[a..b])}, sum(v[a..b])}
// updatemin(a, b, x) faz com que v[i] <- min(v[i], x),
// para i em [a, b]
// updatemax faz o mesmo com max, e updatesum soma x
// em todo mundo do intervalo [a, b]
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log^2 (n)) amortizado
// (se nao usar updatesum, fica log(n) amortizado)

#define f first
#define s second

namespace beats
{
struct node
{
    int tam;
    ll sum, maxVal;

    node(ll x = 0)
    {
        sum = x;
        maxVal = x;
    }

    node(const node &l, const node &r)
    {
        sum = l.sum + r.sum;
        maxVal = max(l.maxVal, r.maxVal);
    }
};

node seg[4 * MAX];
int n, *v;

node build(int p = 1, int l = 0, int r = n - 1)
{
    if (l == r) return seg[p] = {v[l]};
    int m = (l + r) / 2;
    return seg[p] = {build(2 * p, l, m), build(2 * p + 1, m + 1, r)};
}

void build(int n2, int *v2)
{
    n = n2, v = v2;
    build();
}

void updateMod(int a, int b, ll x, int p = 1, int l = 0, int r = n - 1)
{
    // Não precisamos fazer mod, já que, ou está fora do range, ou já está em [0, x - 1]
    if (b < l or r < a or seg[p].maxVal < x) return;

    if (l == r)
    {
        seg[p].maxVal %= x;
        seg[p].sum %= x;
        return;
    }

    int m = (l + r) / 2;

    updateMod(a, b, x, 2 * p, l, m);
    updateMod(a, b, x, 2 * p + 1, m + 1, r);

    seg[p] = node(seg[2 * p], seg[2 * p + 1]);
}

void updateSet(int i, ll x, int p = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        seg[p].sum = x;
        seg[p].maxVal = x;
        return;
    }

    int m = (l + r) / 2;

    if (i <= m) updateSet(i, x, 2 * p, l, m);
    else updateSet(i, x, 2 * p + 1, m + 1, r);

    seg[p] = node(seg[2 * p], seg[2 * p + 1]);
}

// Retorna a soma no intervalo [a, b]
ll query(int a, int b, int p = 1, int l = 0, int r = n - 1)
{
    if (b < l || r < a) return 0;
    if (a <= l && r <= b) return seg[p].sum;

    int m = (l + r) / 2;
    return query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r);
}

}; // namespace beats

void solve()
{
    int n, m;
    cin >> n >> m;

    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    beats::build(n, v);

    for (int i = 0; i < m; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;

            cout << beats::query(l, r) << endl;
        }

        else if (type == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;

            beats::updateMod(l, r, x);
        }

        else if (type == 3)
        {
            int k, x;
            cin >> k >> x;
            k--;

            beats::updateSet(k, x);
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
