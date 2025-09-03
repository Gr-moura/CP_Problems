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

set<int> A;

// quantas maneiras que eu tenho de fazer a soma ate o indice i usando os primeiros a, b, c, d elementos
int dp[8003][8003][5];
int qtNumero[8003];
int qtOriginal[8003];

int buscar(int soma, int qtElementos, int primeiraVez = 0)
{
    if (qtElementos == 1)
    {
        if (qtNumero[soma] > 0) return qtNumero[soma];
        else return 0;
    }

    if (dp[soma][qtElementos] != -1) return dp[soma][qtElementos];

    int ans = 0;

    for (int i = 0; i < 8003; i++)
    {
        if (qtOriginal[i] > 0 && A.count(i) && qtElementos > 1 && primeiraVez)
        {
            int qt = Combinacao(qtOriginal[i], qtElementos);
            ans += qt * buscar(soma - i, qtElementos - 1);
        }
    }

    return dp[soma][qtElementos] = ans;
}

void solve()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    memset(qtNumero, 0, sizeof(qtNumero));
    memset(qtOriginal, 0, sizeof(qtOriginal));

    for (int i = 0; i < 8003; i++)
    {
        dp[i][1] = 0;
        dp[i][0] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x += 1000;
        A.insert(x);

        qtNumero[x]++;
        qtOriginal[x]++;
        dp[x][1]++;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        x += 4000;

        cout << buscar(x, 4) << endl;
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
