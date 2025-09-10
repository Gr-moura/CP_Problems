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
vector<vector<pii>> iniciais(9);
queue<pair<int, int>> q;

int n, m, p;
int v[9];
int cells[9];
char board[1000][1000];
int minDist[1000][1000];

bool valido(int x, int y, int player, int dist)
{
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (board[x][y] != '.' and board[x][y] != player + '1') return false;
    if (dist > v[player] or dist >= minDist[x][y]) return false;

    return true;
}

vector<pii> movimentos = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void BFS()
{
    for (int i = 0; i < p; i++)
    {
        for (auto u : iniciais[i])
        {
            for (auto [dx, dy] : movimentos)
            {
                int nx = u.f + dx, ny = u.s + dy;
                if (valido(nx, ny, i, 1))
                {
                    q.push({u.f, u.s});
                    break;
                }
            }
        }
    }

    queue<tuple<int, int, int>> q2;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        int player = board[x][y] - '1';

        while (!q.empty() && board[q.front().f][q.front().s] - '1' == player)
        {
            minDist[q.front().f][q.front().s] = 0;
            q2.push({q.front().f, q.front().s, 0});
            q.pop();
        }

        while (!q2.empty())
        {
            auto [x2, y2, d2] = q2.front();
            q2.pop();

            if (d2 == v[player])
            {
                q.push({x2, y2});
                continue;
            }

            for (auto [i, j] : movimentos)
            {
                if (valido(x2 + i, y2 + j, player, d2 + 1))
                {
                    if (board[x2 + i][y2 + j] == '.') cells[player]++;

                    board[x2 + i][y2 + j] = player + '1';
                    minDist[x2 + i][y2 + j] = d2 + 1;

                    q2.push({x2 + i, y2 + j, d2 + 1});
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> v[i];
        v[i] = min(v[i], n * m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            minDist[i][j] = INF;

            cin >> board[i][j];
            if (board[i][j] >= '1' && board[i][j] <= '9')
            {
                minDist[i][j] = 0;

                cells[board[i][j] - '1']++;
                iniciais[board[i][j] - '1'].push_back({i, j});
            }
        }
    }

    BFS();

    for (int i = 0; i < p; i++)
    {
        cout << cells[i] << " ";
    }

    cout << endl;
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
