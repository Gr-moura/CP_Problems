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
    int a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    int u1 = x1 + y1, v1 = x1 - y1;
    int u2 = x2 + y2, v2 = x2 - y2;

    // Temos blocos de tamanho 2a x 2b
    // Ver bloco atual e distância até outro
    u1 = u1 / (2 * a) + (u1 > 0);
    v1 = v1 / (2 * b) + (v1 > 0);
    u2 = u2 / (2 * a) + (u2 > 0);
    v2 = v2 / (2 * b) + (v2 > 0);

    cout << max(abs(v2 - v1), abs(u2 - u1)) << endl;
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
