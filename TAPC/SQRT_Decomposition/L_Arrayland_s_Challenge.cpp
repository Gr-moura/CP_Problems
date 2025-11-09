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

const int MOD = 1e9 + 7, MAX = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

const int BLOCK_SIZE = 30;
struct Query
{
    int l, r, idx;

    bool operator<(const Query &other) const
    {
        if (l / BLOCK_SIZE == other.l / BLOCK_SIZE) return r < other.r;

        return ((l / BLOCK_SIZE) & 1 ? r > other.r : r < other.r);
    }
};

vi a(MAX);
vector<int> MOs(vector<Query> queries)
{
    vector<int> ans(queries.size());
    sort(all(queries));

    int curL = 0, curR = -1;

    // Guarda os elementos
    multiset<int> elementos;
    multiset<int> diffs;

    auto add = [&](int pos) {
        elementos.insert(a[pos]);
        auto it = elementos.find(a[pos]);
        if (it != elementos.begin())
        {
            auto itPrev = prev(it);
            int dif1 = abs(*it - *itPrev);
            diffs.insert(dif1);
        }

        auto itNext = next(it);
        if (itNext != elementos.end())
        {
            int dif2 = abs(*itNext - *it);
            diffs.insert(dif2);
        }
    };

    auto rmv = [&](int pos) {
        auto it = elementos.find(a[pos]);
        if (it != elementos.begin())
        {
            auto itPrev = prev(it);
            int dif1 = abs(*it - *itPrev);
            diffs.erase(diffs.find(dif1));
        }

        auto itNext = next(it);
        if (itNext != elementos.end())
        {
            int dif2 = abs(*itNext - *it);
            diffs.erase(diffs.find(dif2));
        }

        elementos.erase(it);
    };

    for (auto q : queries)
    {
        while (curL > q.l)
        {
            curL--;
            add(curL);
        }

        while (curR < q.r)
        {
            curR++;
            add(curR);
        }

        while (curL < q.l)
        {
            rmv(curL);
            curL++;
        }

        while (curR > q.r)
        {
            rmv(curR);
            curR--;
        }

        ans[q.idx] = *diffs.begin();
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    // BLOCK_SIZE = ceil(sqrt(n / log2(n)));

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<Query> queries;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        queries.pb({--l, --r, i});
    }

    vi ans = MOs(queries);
    for (auto i : ans)
        cout << i << endl;
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
