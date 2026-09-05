/*
ID: gabriel139
LANG: C++
TASK: castle
*/

/* clang-format off */
#include <bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back

// Índice base 0 do primeiro elemento maior ou igual a x em log n
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())

// Índice base 0 do primeiro elemento  estritamente maior que x em log n
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

struct answer
{
    int x, y;
    char direction;

    answer(int x, int y, char direction) : x(x), y(y), direction(direction) {}

    bool operator<(const answer &other) const
    {
        if (y == other.y)
        {
            if (x == other.x)
            {
                return direction > other.direction;
            }
            return x > other.x;
        }
        return y < other.y;
    }
};

int n, m;
int sz = 0;
void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int x, int y)
{
    if (x >= n or y >= m) return;
    if (vis[x][y]) return;

    vis[x][y] = true;
    sz++;

    int peso = 15 - grid[x][y];
    for (int k = 8; k > 0 and peso > 0; k /= 2)
    {
        if (peso - k >= 0)
        {
            peso -= k;

            if (k == 8 and x + 1 < n) dfs(grid, vis, x + 1, y);
            else if (k == 4 and y + 1 < m) dfs(grid, vis, x, y + 1);
            else if (k == 2 and x - 1 >= 0) dfs(grid, vis, x - 1, y);
            else if (k == 1 and y - 1 >= 0) dfs(grid, vis, x, y - 1);
        }
    }
}

// rooms, maxSize
pii findComponents(vector<vector<int>> &grid)
{
    int maxSize = 0;
    int rooms = 0;

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                sz = 0;
                dfs(grid, vis, i, j);
                maxSize = max(maxSize, sz);

                rooms++;
            }
        }
    }

    return {rooms, maxSize};
}

void solve()
{
    cin >> m >> n;

    vector<vi> grid(n, vi(m, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    auto [rooms, maxSize] = findComponents(grid);

    vector<answer> ans;
    int maxSizeRetirando = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int somaAcumulada = 0;
            for (int k = 8; k > 0; k /= 2)
            {
                int inicial = grid[i][j];
                if (grid[i][j] >= somaAcumulada + k)
                {
                    grid[i][j] -= k;

                    // Temos de atualizar os módulos dos lados também
                    if (k == 8 && i + 1 < n) grid[i + 1][j] -= 2;
                    else if (k == 4 && j + 1 < m) grid[i][j + 1] -= 1;
                    else if (k == 2 && i - 1 >= 0) grid[i - 1][j] -= 8;
                    else if (k == 1 && j - 1 >= 0) grid[i][j - 1] -= 4;

                    auto [newRooms, newMaxSize] = findComponents(grid);

                    if (newMaxSize > maxSizeRetirando)
                    {
                        maxSizeRetirando = newMaxSize;
                        char maxDirection = k == 8 ? 'S' : k == 4 ? 'E' : k == 2 ? 'N' : 'W';

                        ans.clear();
                        ans.eb(i, j, maxDirection);
                    }

                    else if (newMaxSize == maxSizeRetirando)
                    {
                        char maxDirection = k == 8 ? 'S' : k == 4 ? 'E' : k == 2 ? 'N' : 'W';
                        ans.eb(i, j, maxDirection);
                    }

                    if (k == 8 && i + 1 < n) grid[i + 1][j] += 2;
                    else if (k == 4 && j + 1 < m) grid[i][j + 1] += 1;
                    else if (k == 2 && i - 1 >= 0) grid[i - 1][j] += 8;
                    else if (k == 1 && j - 1 >= 0) grid[i][j - 1] += 4;

                    somaAcumulada += k;
                }

                grid[i][j] = inicial;
            }
        }
    }

    sort(all(ans));
    int maxX = ans[0].x;
    int maxY = ans[0].y;
    char maxDirection = ans[0].direction;

    cout << rooms << endl;
    cout << maxSize << endl;
    cout << maxSizeRetirando << endl;
    cout << maxX + 1 << " " << maxY + 1 << " " << maxDirection << endl;
}

int32_t main()
{
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

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
