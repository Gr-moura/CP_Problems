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
    int n;
    cin >> n;

    vi va(n), vb(n);

    for (auto &i : va)
        cin >> i;

    for (auto &i : vb)
        cin >> i;

    // Para todo elemento em b, existe um menor em a
    // Percorrer elementos de a e de b, se b for menor, swap

    vector<string> ans;

    for (int i = 0; i < n; i++)
    {
        int a = va[i], b = vb[i];
        if (a > b)
        {
            int temp = va[i];
            va[i] = vb[i];
            vb[i] = temp;

            string add = "3 " + to_string(i + 1) + "\n";
            ans.pb(add);
        }
    }

    // Ordenar valores em a
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 1 < n; j++)
        {
            if (va[j] > va[j + 1])
            {
                int temp = va[j];
                va[j] = va[j + 1];
                va[j + 1] = temp;

                string add = "1 " + to_string(j + 1) + "\n";
                ans.pb(add);
            }
        }
    }

    // Ordenar valores em b
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 1 < n; j++)
        {
            if (vb[j] > vb[j + 1])
            {
                int temp = vb[j];
                vb[j] = vb[j + 1];
                vb[j + 1] = temp;

                string add = "2 " + to_string(j + 1) + "\n";
                ans.pb(add);
            }
        }
    }

    cout << ans.size() << endl;
    for (auto s : ans)
        cout << s;
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
