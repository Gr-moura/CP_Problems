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

vector<pii> mv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int linhas, colunas;

char M[MAX][MAX];

vector<vi> dist(MAX, vi(MAX, -1));

bool val(int i, int j)
{
    if (i >= 0 && i < linhas && j >= 0 && j < colunas && M[i][j] != 'T' && dist[i][j] == -1)
        return 1;

    return 0;
}

void BFS(pii s)
{
    queue<pii> q;

    q.push(s);
    dist[s.f][s.s] = 0;

    while (!q.empty())
    {
        pii atual = q.front();
        q.pop();

        for (auto add : mv)
        {
            if (val(atual.f + add.f, atual.s + add.s))
            {
                q.push({atual.f + add.f, atual.s + add.s});
                dist[atual.f + add.f][atual.s + add.s] = dist[atual.f][atual.s] + 1;
            }
        }
    }
}

void solve()
{
    vector<pair<pair<int, int>, int>> pos_trei;

    cin >> linhas >> colunas;

    pii saida;
    pii laila;

    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
        {
            cin >> M[i][j];

            if (M[i][j] >= '1' && M[i][j] <= '9')
                pos_trei.pb({{i, j}, M[i][j] - '0'});

            else if (M[i][j] == 'E')
                saida = {i, j};

            else if (M[i][j] == 'S')
                laila = {i, j};
        }

    BFS(saida);

    int Laila = dist[laila.f][laila.s];

    int ans = 0;

    for (auto p : pos_trei)
    {
        pii coords = p.f;
        int distancia = dist[coords.f][coords.s];

        if (Laila >= distancia)
        {
            ans += p.s;
        }
    }

    cout << ans;
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
