#include <algorithm>
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
#define lb(vect, x) lower_bound(all(vect), x) - vect.begin()
#define ub(vect, x) upper_bound(all(vect), x) - vect.begin()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    int qtsacos, qtcomp, qtmax;
    cin >> qtsacos >> qtcomp >> qtmax;
    vi sacos(qtsacos);

    int total = 0;

    for (int i = 0; i < qtsacos; i++)
    {
        cin >> sacos[i];
        total += sacos[i];
    }

    int mintempo = 1, maxtempo = (total + qtmax - 1) / qtmax;
    while (mintempo < maxtempo)
    {
        int segundos = (mintempo + maxtempo) / 2;
        int comeu, k = 0;

        for (int i = 0; i < qtcomp; i++)
        {
            comeu = segundos * qtmax;

            while (k < sacos.size() && comeu >= sacos[k])
            {
                comeu -= sacos[k];
                k++;
            }
        }

        if (k == sacos.size()) // Tempo foi suficiente
            maxtempo = segundos;

        else
            mintempo = segundos + 1;
    }

    cout << mintempo << endl;
}

int32_t main()
{
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
