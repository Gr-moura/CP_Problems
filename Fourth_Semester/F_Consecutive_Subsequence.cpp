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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

// num, tamSequencia, pos
map<int, pair<vector<int>, int>> m;
void solve()
{
    int n;
    cin >> n;

    pii ms{1, 1};
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        m[a].f.pb(i + 1), m[a].s = 1;
        if (m.contains(a - 1)) m[a].s = m[a - 1].s + 1;

        if (m[a].s > ms.s) ms.f = a, ms.s = m[a].s;
    }

    // A maior sequencia termina em ms.f e tem tamanho ms.s
    cout << ms.s << endl;
    if (ms.s == 1)
    {
        cout << 1 << endl;
        return;
    }

    int numAtual = ms.f - ms.s + 1;
    int indexAtual = m[numAtual].f[0];
    int i = 0;
    while (i < ms.s)
    {
        cout << indexAtual << " ";
        if (++i >= ms.s) break;

        numAtual++;
        int j = 0;
        while (m[numAtual].f[j] < indexAtual)
            j++;
        indexAtual = m[numAtual].f[j];
    }

    cout << endl;
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
