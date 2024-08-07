#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0)->sync_with_stdio(0);
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
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

bool val_ms(pii p)
{
    return p.f >= 0 && p.s >= 0 && p.f < linhas && p.s < colunas && M[p.f][p.s] != '#' && dist[p.f][p.s] == INF;
}

bool val(pii p, int dis_anterior)
{
    return p.f >= 0 && p.s >= 0 && p.f < linhas && p.s < colunas && M[p.f][p.s] != '#' &&
           dis_anterior + 1 < dist[p.f][p.s] && !vis[p.f][p.s];
}

void BFS_MS(queue<pii> ms)
{
    while (!ms.empty())
    {
        pii atual = ms.front();
        ms.pop();

        for (auto viz : mov)
        {
            viz.f += atual.f, viz.s += atual.s;

            if (val_ms(viz))
            {
                dist[viz.f][viz.s] = dist[atual.f][atual.s] + 1;
                ms.push(viz);
            }
        }
    }
}

int BFS(pii fonte)
{
    memset(vis, 0, sizeof(vis));

    dist[fonte.f][fonte.s] = 0;
    vis[fonte.f][fonte.s] = 1;

    queue<pii> q;
    q.push(fonte);

    while (!q.empty())
    {
        pii atual = q.front();
        q.pop();

        if (atual.f == 0 || atual.f == linhas - 1 || atual.s == 0 || atual.s == colunas - 1)
            return dist[atual.f][atual.s];

        for (auto viz : mov)
        {
            viz.f += atual.f, viz.s += atual.s;

            if (val(viz, dist[atual.f][atual.s]))
            {
                dist[viz.f][viz.s] = dist[atual.f][atual.s] + 1;
                q.push(viz);
                vis[viz.f][viz.s] = 1;
            }
        }
    }

    return -1;
}

void solve()
{
    memset(dist, INF, sizeof(dist));
    queue<pii> ms;
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
            {
                ms.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    BFS_MS(ms);

    // for (int i = 0; i < linhas; i++)
    // {
    //     for (int j = 0; j < colunas; j++)
    //     {
    //         if (M[i][j] == '#')
    //             cout << "# ";
    //
    //         else
    //             cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = BFS(start);

    if (ans == -1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << ans + 1 << endl;
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
