#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0)->sync_with_stdio(0);
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
// #define int long long
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

int linhas, colunas;

vector<pii> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char M[MAX][MAX];
int dist[MAX][MAX];
bool vis[MAX][MAX];

bool val(pii u)
{
    return u.f >= 0 && u.s >= 0 && u.f < linhas && u.s < colunas && M[u.f][u.s] != '#' && !vis[u.f][u.s];
}

void BFS_MS(vector<pii> ms)
{
    memset(vis, 0, sizeof vis);
    memset(dist, INF, sizeof dist);

    queue<pii> q;

    for (auto s : ms)
    {
        q.push(s);
        vis[s.f][s.s] = 1;
        dist[s.f][s.s] = 0;
    }

    while (!q.empty())
    {
        pii v = q.front();
        q.pop();

        for (auto u : mov)
        {
            u.f += v.f, u.s += v.s;

            if (val(u))
            {
                dist[u.f][u.s] = dist[v.f][v.s] + 1;
                vis[u.f][u.s] = 1;
                q.push(u);
            }
        }
    }
}

int BFS(pii s)
{
    memset(vis, 0, sizeof vis);

    queue<pii> q;
    q.push(s), vis[s.f][s.s] = 1, dist[s.f][s.s] = 0;

    while (!q.empty())
    {
        pii v = q.front();
        q.pop();

        if (v.f == 0 || v.f == linhas - 1 || v.s == 0 || v.s == colunas - 1)
            return dist[v.f][v.s] + 1;

        for (auto u : mov)
        {
            u.f += v.f, u.s += v.s;

            if (val(u) && dist[v.f][v.s] + 1 < dist[u.f][u.s])
            {

                q.push(u), vis[u.f][u.s] = 1;
                dist[u.f][u.s] = dist[v.f][v.s] + 1;
            }
        }
    }

    return -1;
}

void solve()
{
    vector<pii> ms;
    pii start;

    cin >> colunas >> linhas;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cin >> M[i][j];

            if (M[i][j] == '@')
                start = {i, j};

            else if (M[i][j] == '*')
                ms.pb({i, j});
        }
    }

    BFS_MS(ms);

    // for (int i = 0; i < linhas; i++)
    // {
    //     for (int j = 0; j < colunas; j++)
    //     {
    //         if (M[i][j] == '#')
    //             cout << "#";
    //         else
    //             cout << dist[i][j];
    //     }
    //
    //     cout << endl;
    // }

    int ans = BFS(start);

    if (ans == -1)
    {
        cout << "IMPOSSIBLE\n";
        return;
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
