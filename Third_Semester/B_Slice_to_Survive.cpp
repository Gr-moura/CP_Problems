/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; i++) if (a % i == 0) return 0; return 1; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

/* clang-format on */
void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    // Since each cut affects only one dimension, we can handle the row
    // and columns reductions independently. Assim, o número de cortes
    // necessários é igual ao número de cortes necessários para reduzir
    // a dimensão de n para 1, mais o número de cortes necessários para
    // reduzir a dimensão de m para 1.

    // Em cada corte, podemos dividir n em duas partes, a ou n - a + 1

    vector<pii> posAposPrimeiroCorte = {{a, m}, {n, b}, {n - a + 1, m}, {n, m - b + 1}};

    int turnos = n + m;
    for (auto [x, y] : posAposPrimeiroCorte)
    {
        int res = 0;
        while (x > 1)
            x = (x + 1) / 2, res++;

        while (y > 1)
            y = (y + 1) / 2, res++;

        turnos = min(turnos, res);
    }

    cout << 1 + turnos << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
