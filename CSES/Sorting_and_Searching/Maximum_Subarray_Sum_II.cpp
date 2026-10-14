/*
Maximum Subarray Sum II => 2026-10-07
https://cses.fi/problemset/task/1644
*/

/* clang-format off */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class Key, class Cmp = less<Key>>
using ordered_set = tree<Key, null_type, Cmp, rb_tree_tag,
                         tree_order_statistics_node_update>;

template <class Key, class Value, class Cmp = less<Key>>
using ordered_map = tree<Key, Value, Cmp, rb_tree_tag,
                         tree_order_statistics_node_update>;

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
typedef vector<vi> vvi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
template <typename T> struct max_queue
{
    deque<pair<T, long long>> q; // {valor, índice}; a frente contém o mínimo.
    long long cntAdded = 0, cntRemoved = 0; // Quantos já adicionamos e já retiramos (funciona como índice)

    // size() conta valores da fila, não candidatos do deque.
    bool empty() const { return cntAdded == cntRemoved; }
    long long size() const { return cntAdded - cntRemoved; }

    void push(const T &x)
    {
        // Descarte candidatos maiores que x: eles saem antes dele.
        // Para máximo, troque < por >.
        while (!q.empty() && x > q.back().first) q.pop_back();
        q.push_back({x, cntAdded++});
    }

    // Invariante: os índices em q são crescentes e todos são >= cntRemoved.
    // Base: q está vazia. push() acrescenta cntAdded >= cntRemoved ao fim e só descarta candidatos.
    // pop() retira cntRemoved se presente; os restantes são maiores e preservam a regra após o incremento.
    // Por isso, == basta; a prova usa apenas os índices.
    void pop()
    {
        if (q.front().second == cntRemoved) q.pop_front();
        cntRemoved++;
    }

    T get() const { return q.front().first; }
};

void solve() {
	int n, a, b; cin >> n >> a >> b;
	vi v(n + 1, 0); for (int i = 1; i <= n; i++) cin >> v[i];

	max_queue<int> mq;
	partial_sum(all(v), v.begin());
	for (int i = a; i <= b; i++) mq.push(v[i]);

	int retirar = 0;
	int maxSum = -LINF;
	for (int l = 0; l + a <= n; l++)
	{
		maxSum = max(maxSum, mq.get() - v[l]);
		mq.pop();

		if (l + b + 1 <= n)
			mq.push(v[l + b + 1]);
	}

	cout << maxSum << endl;
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
