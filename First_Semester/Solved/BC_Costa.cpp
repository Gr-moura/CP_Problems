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

const int MAX = 1010;

char M[MAX][MAX];
bool vis[MAX][MAX];

int linhas, colunas, ans = 0;

bool val(pii p)
{
    return p.f >= 0 && p.s >= 0 && p.f < linhas && p.s < colunas && !vis[p.f][p.s];
}

vector<pii> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve()
{
    cin >> linhas >> colunas;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cin >> M[i][j];
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (val({i, j}) && M[i][j] == '.')
            {
                for (auto vizinhos : mov)
                {
                    vizinhos.f += i, vizinhos.s += j;
                    if (val(vizinhos) && M[vizinhos.f][vizinhos.s] == '#')
                    {
                        vis[vizinhos.f][vizinhos.s] = 1;
                        ans++;
                    }
                }
            }

            else if (val({i, j}) && M[i][j] == '#')
            {
                if (i == 0 or j == 0 or i == linhas - 1 or j == colunas - 1)
                {
                    ans++;
                    vis[i][j] = 1;
                }
            }
        }
    }

    cout << ans << endl;
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
