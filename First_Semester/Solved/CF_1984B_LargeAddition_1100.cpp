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
    string str;
    cin >> str;

    if (str[0] != '1')
    {
        cout << "NO" << endl;
        return;
    }

    // Como 5 + 5 / 9 + 9 sempre faz o próximo ter soma + 1
    // O limite do aceitável dos outros é o de unidades + 1;
    vi unidades = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vi outros = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 1; i < str.size(); i++)
    {
        int c = str[i] - '0';

        if (i < sz(str) - 1)
        {

            int passou = 0;
            for (auto j : outros)
            {

                if (c == j)
                {
                    passou = 1;
                    break;
                }
            }
            if (passou == 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            int passou = 0;
            for (auto j : unidades)
            {
                if (c == j)
                {
                    passou = 1;
                    break;
                }
            }
            if (passou == 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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
