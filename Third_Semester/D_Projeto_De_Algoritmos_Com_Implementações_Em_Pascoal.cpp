#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* clang-format off */
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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Achar maior sequencia que comeca com 2 '1' e termina com 2 '0'
void AcharMaiorSequencia(const string& s, int n)
{
}

/* clang-format on */
void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    vector<pii> ans;

    int i = n - 1;

    bool somarUltimo = 0;
    while (i >= 0)
    {
        somarUltimo = 0;

        // Achar primeira sequência com dois uns
        while (i >= 1 && (s[i] != '1' || s[i - 1] != '1'))
        {
            if (s[i] == '1')
            {
                ans.pb({(n - i - 1), 1});
            }
            i--;
        }

        if (i >= 1 && s[i] == '1' && s[i - 1] == '1')
        {
            ans.pb({(n - i - 1), -1});
            somarUltimo = 1;
        }

        // Achar primeira sequência com dois zeros
        while (i >= 1 && (s[i] != '0' || s[i - 1] != '0'))
        {
            if (s[i] == '0')
            {
                ans.pb({(n - i - 1), -1});
            }
            i--;
        }

        if (i >= 1 && s[i] == '0' && s[i - 1] == '0')
        {
            ans.pb({n - i - 1, 1});
            somarUltimo = 0;
        }

        i--;
    }

    if (!somarUltimo && s[0] == '1')
    {
        ans.pb({n - 1, 1});
    }

    if (somarUltimo)
    {
        ans.pb({n, 1});
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].s == 1)
        {
            cout << "+" << 2 << "^" << ans[i].f << endl;
        }
        else
        {
            cout << "-" << 2 << "^" << ans[i].f << endl;
        }
    }
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
