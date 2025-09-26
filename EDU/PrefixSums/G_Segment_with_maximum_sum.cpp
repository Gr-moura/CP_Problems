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

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    for (auto &i : a)
        cin >> i;

    int maxSoma = a[0], somaAtual = a[0];
    int maxSomaIndInicio = 0, somaAtualIndInicio = 0;
    int maxSomaIndFim = 0, somaAtualIndFim = 0;
    for (int i = 1; i < n; i++)
    {
        somaAtual += a[i];
        somaAtualIndFim = i;

        // Melhor reiniciar
        if (a[i] > somaAtual)
        {
            somaAtual = a[i];
            somaAtualIndInicio = i;
            somaAtualIndFim = i;
        }

        if (somaAtual > maxSoma)
        {
            maxSoma = somaAtual;
            maxSomaIndInicio = somaAtualIndInicio;
            maxSomaIndFim = somaAtualIndFim;
        }
    }

    cout << maxSomaIndInicio + 1 << " " << maxSomaIndFim + 1 << " " << maxSoma << endl;
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
