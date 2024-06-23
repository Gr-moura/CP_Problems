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

    int sz;
    cin >> sz;

    vi nums(sz - 1);

    if (sz == 2)
    {
        int num;
        cin >> num;
        cout << num << endl;
        return;
    }

    string str;
    cin >> str;

    for (int i = 0; i < sz - 1; i++)
    {
        nums[i] = 10 * (str[i] - '0') + str[i + 1] - '0';
    }

    int menor = LINF;
    for (int i = 0; i < sz - 1; i++)
    {
        int atual = nums[i];
        for (int j = 0; j < sz; j++)
        {
            if (j == i or j == i + 1)
                continue;

            if (str[j] - '0' == 0)
            {
                cout << 0 << endl;
                return;
            }

            else if (atual == 1)
                atual = str[j] - '0';

            else if (str[j] - '0' != 1)
                atual += str[j] - '0';
        }

        if (atual < menor)
            menor = atual;
    }

    cout << menor << endl;
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
