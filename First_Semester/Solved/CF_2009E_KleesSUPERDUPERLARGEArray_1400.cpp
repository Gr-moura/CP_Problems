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
    int n, a;
    cin >> n >> a;

    int soma_total = (a + a + n - 1) * n / 2;

    // Queremos achar a soma até i, tal que a soma até i mais um, seja
    // maior do que até i;

    int l = 0, r = n - 1;
    int index, dif_atual, soma_atual;
    while (l < r)
    {
        index = (l + r) / 2;

        soma_atual = (a + a + index - 1) * index / 2;
        int soma_proximo = (a + a + index) * (index + 1) / 2;

        dif_atual = abs((2 * soma_atual - soma_total));
        int dif_prox = abs((2 * soma_proximo - soma_total));

        if (dif_atual > dif_prox)
        {
            l = index + 1;
        }

        else
        {
            r = index;
        }
    }

    index = l;
    soma_atual = (a + a + index - 1) * index / 2;
    dif_atual = abs((2 * soma_atual - soma_total));
    cout << dif_atual << endl;
    return;
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
