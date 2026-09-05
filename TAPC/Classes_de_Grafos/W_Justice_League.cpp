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

void NO() { cout << "N" << endl; }
void YES() { cout << "Y" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

// Verificar se o grafo dado apresenta uma clique e um CI (split graph)

// Um grafo é split sse a igualdade se mantém para sua sequência de graus ordenada d1 >= d2 >= ... >= dn:
// Somatório de todos os di = k(k - 1) + Somatório de i = k + 1 até n de di,
// onde k é o maior índice i tal que di >= i - 1
void solve(int H, int R)
{
    vi deg(H);
    for (int i = 0; i < R; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        deg[u]++;
        deg[v]++;
    }

    sort(all(deg), greater<>());

    int m = 0;
    while (m < H && deg[m] >= m)
        m++;

    int somaGrausClique = 0;
    for (int i = 0; i < m; i++)
        somaGrausClique += deg[i];

    int somaGrausCI = 0;
    for (int i = m; i < H; i++)
        somaGrausCI += deg[i];

    if (somaGrausClique == m * (m - 1) + somaGrausCI) YES();
    else NO();
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

    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0)
    {
        solve(n, m);
        cin >> n >> m;
    }

    return 0;
}
