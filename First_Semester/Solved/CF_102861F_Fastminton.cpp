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

// win = above 5 and dif >= 2 or points == 10

void solve()
{
    vector<int> pontos(2, 0);
    vector<int> matches(2, 0);

    string game;
    cin >> game;

    // left = 0, right = 1
    int last = 0;
    int outro = 1;

    for (int i = 0; i < game.size(); i++)
    {
        if (game[i] == 'S')
            pontos[last]++;

        else if (game[i] == 'R')
        {
            last++, outro++;
            last %= 2, outro %= 2;

            pontos[last]++;
        }

        else
        {
            if (i + 1 == game.size())
            {
                cout << matches[0];

                if (last == 0)
                    cout << " (winner)";

                cout << " - " << matches[1];

                if (last == 1)
                    cout << " (winner)";

                cout << endl;
            }

            else
            {
                cout << matches[0] << " (" << pontos[0];

                if (last == 0)
                    cout << "*";

                cout << ") - " << matches[1] << " (" << pontos[1];

                if (last == 1)
                    cout << "*";
                cout << ")\n";
            }
        }

        if ((pontos[last] >= 5 && pontos[last] - pontos[outro] >= 2) or pontos[last] >= 10)
        {
            pontos[0] = 0, pontos[1] = 0;
            matches[last]++;
        }
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
