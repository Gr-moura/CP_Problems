/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; i++) if (a % i == 0) return 0; return 1; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int n, m, p;
int v[9];
int respostas[9];
// tipo, dist, player
int board[1000][1000][3];

bool valido(int x, int y, int player, int dist)
{
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (board[x][y][0] != '.') return false;
    if (dist >= board[x][y][1]) return false;

    return true;
}

vector<pii> movimentos = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void BFS(int player)
{
    // Se board[x][y][0] >= 1 && <= 9, dist = 0
    // dist = dist % v[player]

    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, player, 0});
    while (!q.empty())
    {
        auto [x, y, player, dist] = q.front();
        q.pop();

        if (!valido(x, y, player, dist % v[player])) continue;

        board[x][y][1] = dist % v[player];
        board[x][y][2] = player;

        for (auto [dx, dy] : movimentos)
        {
            int nx = x + dx;
            int ny = y + dy;
            q.push({nx, ny, player, dist + 1});
        }
    }
}

void solve()
{
    cin >> n >> m >> p;
    for (int i = 0; i < p; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j][0];
            board[i][j][1] = -1;
            board[i][j][2] = -1;
        }
    }

    for (int i = 0; i < p; i++)
    {
        BFS(i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j][0] == '.')
            {
                respostas[board[i][j][2]]++;
            }
        }
    }

    for (int i = 0; i < p; i++)
    {
        cout << respostas[i] << " ";
    }

    cout << endl;

    // distancia de cada jogador i mod p[i]
    // rodar BFS até 9 vezes, olhar distancia mais proxima
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
