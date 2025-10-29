/*
ID: gabriel139
LANG: C++
TASK: wormhole
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
int ans = 0;
vector<pii> pos;
vi cores;
vector<bool> vis;
vector<set<int>> adj;
vector<int> par;
vector<int> nextInLine;

bool checkCicle(int vAtual)
{
    if (vAtual == -1) return false;

    cores[vAtual] = 1;
    int v = nextInLine[par[vAtual]];

    if (cores[v] == 0)
        if (checkCicle(v)) return true;

    if (cores[v] == 1) return true;

    cores[vAtual] = 2;
    return false;
}
int vezes = 0;
void backtrack(int jafeitos)
{

    if (jafeitos == n / 2)
    {
        vezes++;
        cores.assign(n, 0);
        for (int ind = 0; ind < n; ind++)
            if (cores[ind] == 0 and checkCicle(ind))
            {
                ans++;
                return;
            }
    }

    for (int i = 0; i < n; i++)
    {
        if (jafeitos == 0 and i >= 1) break;
        if (par[i] != -1) continue;

        for (int j = i + 1; j < n; j++)
        {
            if (par[j] != -1) continue;

            par[i] = j, par[j] = i;

            backtrack(jafeitos + 1);

            par[i] = -1, par[j] = -1;
        }
    }
}

int fat(int x)
{
    if (x <= 1) return 1;
    return x * fat(x - 1);
}
void solve()
{
    cin >> n;
    pos.resize(n);
    adj.assign(n, set<int>());
    vis.assign(n, 0);
    par.assign(n, -1);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        pos[i] = {a, b};
    }

    sort(all(pos), [](pii a, pii b) {
        if (a.s != b.s) return a.s < b.s;
        return a.f < b.f;
    });

    // Um portal sempre está conectado a um outro portal
    // e ao portal à sua frente mais próximo

    // Basta verificar se existe um ciclo nesse grafo direcionado
    nextInLine.assign(n, -1);
    for (int i = 0; i < n - 1; i++)
        if (pos[i].second == pos[i + 1].second) nextInLine[i] = i + 1;

    backtrack(0);
    cout << ans / (fat(n / 2 - 1)) << endl;
}

int32_t main()
{
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);

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
