#include "Headers.h"
#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0)->sync_with_stdio(0);
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    int k;
    cin >> k;

    // Se um número tem um número par de divisores, ele terminará ligado.
    // Se ele tiver um número ímpar, terminará desligado.
    // Assim, se ele for um quadrado perfeito, terminará desligado.
    // Dessa forma, a quantidade de lâmpadas acesas antes de um número
    // é n - #quadrados perfeitos anteriores
    // k = n - chao(raiz(n))

    unsigned long long l = 1, r = 18e18;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;

        if (mid - (int)sqrtl(mid) < k)
        {
            l = mid;
        }

        else
        {
            r = mid;
        }
    }

    cout << r << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
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
