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
    int n;
    cin >> n;

    vector<int> divisores;

    string str;
    cin >> str;

    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            divisores.pb(i);
    }

    int sz = divisores.size();

    for (int i = 0; i < sz; i++)
    {
        int atual = divisores[i];

        vector<int> qt_buscada(26);
        vector<int> qt_atual(26);

        for (int j = 0; j < atual; j++)
        {
            qt_buscada[str[j] - 'a']++;
        }

        for (int j = 0; j < n; j++)
        {
            qt_atual[str[j] - 'a']++;

            if ((j + 1) % atual == 0)
            {
                if (qt_buscada != qt_atual)
                    break;

                if (j + 1 != n)
                    for (auto &k : qt_atual)
                        k = 0;
            }
        }

        if (qt_buscada == qt_atual)
        {
            for (int j = 0; j < atual; j++)
            {
                cout << str[j];
            }
            return;
        }
    }

    cout << "*";
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
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
