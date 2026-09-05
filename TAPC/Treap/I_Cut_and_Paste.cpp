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
// Treap Implicita
//
// Todas as operacoes custam
// O(log(n)) com alta probabilidade

mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

template <typename T> struct treap
{
    struct node
    {
        node *l, *r;
        int p, sz;
        T val, sub, lazy;
        bool rev;
        node(T v) : l(NULL), r(NULL), p(rng()), sz(1), val(v), sub(v), lazy(0), rev(0) {}
        void prop()
        {
            if (lazy)
            {
                val += lazy, sub += lazy * sz;
                if (l) l->lazy += lazy;
                if (r) r->lazy += lazy;
            }
            if (rev)
            {
                swap(l, r);
                if (l) l->rev ^= 1;
                if (r) r->rev ^= 1;
            }
            lazy = 0, rev = 0;
        }
        void update()
        {
            sz = 1, sub = val;
            if (l) l->prop(), sz += l->sz, sub += l->sub;
            if (r) r->prop(), sz += r->sz, sub += r->sub;
        }
    };

    node *root;

    treap() { root = NULL; }
    treap(const treap &t) { throw logic_error("Nao copiar a treap!"); }
    ~treap()
    {
        vector<node *> q = {root};
        while (q.size())
        {
            node *x = q.back();
            q.pop_back();
            if (!x) continue;
            q.push_back(x->l), q.push_back(x->r);
            delete x;
        }
    }

    int size(node *x) { return x ? x->sz : 0; }
    int size() { return size(root); }
    void join(node *l, node *r, node *&i)
    { // assume que l < r
        if (!l or !r) return void(i = l ? l : r);
        l->prop(), r->prop();
        if (l->p > r->p) join(l->r, r, l->r), i = l;
        else join(l, r->l, r->l), i = r;
        i->update();
    }
    void split(node *i, node *&l, node *&r, int v, int key = 0)
    {
        if (!i) return void(r = l = NULL);
        i->prop();
        if (key + size(i->l) < v) split(i->r, i->r, r, v, key + size(i->l) + 1), l = i;
        else split(i->l, l, i->l, v, key), r = i;
        i->update();
    }
    void push_back(T v)
    {
        node *i = new node(v);
        join(root, i, root);
    }
    T query(int l, int r)
    {
        node *L, *M, *R;
        split(root, M, R, r + 1), split(M, L, M, l);
        T ans = M->sub;
        join(L, M, M), join(M, R, root);
        return ans;
    }
    void update(int l, int r, T s)
    {
        node *L, *M, *R;
        split(root, M, R, r + 1), split(M, L, M, l);
        M->lazy += s;
        join(L, M, M), join(M, R, root);
    }
    void reverse(int l, int r)
    {
        node *L, *M, *R;
        split(root, M, R, r + 1), split(M, L, M, l);
        M->rev ^= 1;
        join(L, M, M), join(M, R, root);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    treap<char> t;
    for (char c : s)
        t.pb(c);

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        treap<char>::node *L, *M, *R;

        // Cortar [l, r]
        t.split(t.root, M, R, r + 1);
        t.split(M, L, M, l);

        // Juntar meio e colar no fim
        t.join(L, R, t.root);
        t.join(t.root, M, t.root);
    }

    for (int i = 0; i < n; i++)
    {
        char c = t.query(i, i);
        cout << c;
    }

    cout << endl;
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
