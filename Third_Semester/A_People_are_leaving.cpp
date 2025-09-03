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

/* clang-format on */

// O representante será a pessoa à direita mais próxima de x
vi id;
int find(int x)
{
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void uni(int x, int y)
{
    x = find(x), y = find(y);
    id[x] = y;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    id = vi(n + 2, -1);
    // Preenche todo o vetor com 0, 1, 2, 3, ...
    iota(id.begin(), id.end(), 0);

    for (int i = 0; i < m; i++)
    {
        char cmd;
        int x;

        cin >> cmd >> x;

        if (cmd == '-')
        {
            // O mais a direita do x, vai passar a ser o mais
            // a direita do proximo. O de trás, que recebia o
            // mais a direita do x, recebe o mais a direito do
            // proximo
            uni(x, x + 1);
        }

        else cout << (find(x) == n + 1 ? -1 : find(x)) << endl;
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
