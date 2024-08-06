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

#define RMV 0
#define ADD 1

void solve()
{
    queue<pii> fila;

    int est;
    cin >> est;

    for (int i = 0; i < est; i++)
    {
        int en, sa;
        cin >> en >> sa;

        fila.push({en, sa});
    }

    int hora = 1;

    while (!fila.empty())
    {
        pii atual = fila.front();
        fila.pop();

        if (hora <= atual.f)
        {
            cout << atual.f << " ";
            hora = atual.f + 1;
            continue;
        }

        if (hora >= atual.f && hora <= atual.s)
        {
            cout << hora << " ";
            hora++;
            continue;
        }

        else
            cout << 0 << " ";
    }
    cout << endl;
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
