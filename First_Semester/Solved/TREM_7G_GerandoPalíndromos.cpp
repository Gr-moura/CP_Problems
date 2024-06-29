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

bool ehpala(string s)
{
    int si = sz(s);
    for (int i = 0; i < si; i++)
    {
        if (s[i] != s[si - 1 - i])
            return 0;
    }
    return 1;
}

void solve()
{
    int palavras, tamanho;
    cin >> palavras >> tamanho;

    vector<string> ans;
    string res;

    vector<string> str(palavras);

    for (int i = 0; i < palavras; i++)
    {
        cin >> str[i];
    }

    int eh = 1;

    for (int i = 0; i < palavras - 1; i++)
    {

        for (int j = i + 1; j < palavras; j++)
        {

            eh = 1;

            for (int k = 0; k < tamanho; k++)
            {
                if (str[i][k] != str[j][tamanho - 1 - k])
                {
                    eh = 0;
                    break;
                }
            }

            if (eh)
            {
                ans.pb(str[i]);
                ans.pb(str[j]);
                break;
            }
        }
    }

    if (sz(ans) % 2 == 0)
        for (int i = 0; i < palavras; i++)
        {
            if (ehpala(str[i]))
            {
                ans.pb(str[i]);
                break;
            }
        }

    cout << sz(ans) * tamanho << endl;

    if (sz(ans) % 2 == 0)
    {
        for (int i = 0; i < sz(ans); i += 2)
        {
            res += ans[i];
        }

        for (int i = sz(ans) - 1; i >= 0; i -= 2)
        {
            res += ans[i];
        }
    }

    if (sz(ans) % 2 == 1)
    {
        for (int i = 0; i < sz(ans) - 1; i += 2)
        {
            res += ans[i];
        }

        res += ans.back();

        for (int i = sz(ans) - 2; i >= 0; i -= 2)
        {
            res += ans[i];
        }
    }

    if (!ans.empty())
    {
        cout << res;
        return;
    }
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
