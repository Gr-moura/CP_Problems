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

vector<vi> mat(110, vi(110));
vector<pii> pos = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int ehpos(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            int maior = 1;
            int mai = -1;
            for (auto k : pos)
            {
                if (i + k.f >= 0 && i + k.f < x && j + k.s >= 0 && j + k.s < y)
                {
                    if (mat[i][j] <= mat[i + k.f][j + k.s])
                    {
                        maior = 0;
                        break;
                    }
                    if (mat[i + k.f][j + k.s] > mai)
                        mai = mat[i + k.f][j + k.s];
                }
            }
            if (maior)
            {
                mat[i][j] = mai;
                return 1;
            }
        }
    }

    return 0;
}
void solve()
{
    int x, y;
    cin >> x >> y;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> mat[i][j];
        }
    }

    while (ehpos(x, y))
        ;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << mat[i][j] << " ";
            mat[i][j] = 0;
        }
        cout << endl;
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
