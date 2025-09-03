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

bool ehPrimo(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> divisores(int n)
{
    vector<int> divs;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    return divs;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vi A; // Tamanho da particula i
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.pb(x);
    }

    vi B(n, 0); // Filtro que parou a particula da posicao i
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
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
