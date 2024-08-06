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

const int MAX = 110;

vector<pii> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char M[MAX][MAX];
bool vis[MAX][MAX];

int linhas, colunas;

bool val(int i, int j)
{
    return i >= 0 && j >= 0 && i < linhas && j < colunas && !vis[i][j] && M[i][j] == 'H';
}

void BFS(pii fonte)
{
    vis[fonte.f][fonte.s] = 1;

    queue<pii> q;
    q.push(fonte);

    pii ans;

    while (!q.empty())
    {
        pii atual = q.front();
        ans = atual;
        q.pop();

        for (auto add : mov)
        {
            if (val(atual.f + add.f, atual.s + add.s))
            {
                q.push({atual.f + add.f, atual.s + add.s});
                vis[atual.f + add.f][atual.s + add.s] = 1;
            }
        }
    }

    cout << ans.f + 1 << " " << ans.s + 1 << endl;
}

void solve()
{
    cin >> linhas >> colunas;

    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            cin >> M[i][j];

    pii fonte;
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            if (M[i][j] == 'o')
                fonte = {i, j};

    BFS(fonte);
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
