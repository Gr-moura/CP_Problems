/*
ID: gabriel139
LANG: C++
TASK: test
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

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
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

#include <bits/stdc++.h>
using namespace std;

/* Seja 0 <= i < m e 0 <= j < n

Se tivermos uma DP da forma:
dp[i][j] = min{ dp[i - 1][k - 1] + Custo(k, j) },

onde 0 <= k <= j e o custo satisfaz a propriedade de quadrangle inequality, ou seja:
Custo(a, c) + Custo(b, d) <= Custo(a, d) + Custo(b, c) para a <= b <= c <= d

Então podemos otimizar o cálculo da DP usando a técnica de Divide and Conquer DP,
que reduz a complexidade de O(m * n^2) para O(m * n log n).
*/

const int maxM = 3010, maxN = 3010;
int dp[maxM][maxN]; // dp[i][j] representa o custo mínimo para a i-ésima etapa e j-ésimo estado
int arr[maxN];
int pref[maxN];

int Custo(int k, int j)
{
    int sum = pref[j] - (k ? pref[k - 1] : 0);
    return sum * sum;
}

void compute(int etapaAtual, int l, int r, int optLB, int optUB)
{
    if (l > r) return;

    int mid = (l + r) / 2;
    pair<int, int> best = {LLONG_MAX, -1};

    for (int k = optLB; k <= min(mid, optUB); ++k)
    {
        int cost = dp[etapaAtual - 1][k - 1] + Custo(k, mid);
        if (cost < best.first) best = {cost, k};
    }

    dp[etapaAtual][mid] = best.first;
    int optMid = best.second;

    compute(etapaAtual, l, mid - 1, optLB, optMid);
    compute(etapaAtual, mid + 1, r, optMid, optUB);
}

void divideAndConquerDP(int m, int n)
{
    // Inicialização da primeira linha da DP, caso base
    for (int j = 0; j < n; ++j)
    {
        dp[0][j] = Custo(0, j); // Custo de criar uma subarray indo de 0 a j
    }

    for (int i = 1; i < m; ++i)
    {
        compute(i, 0, n - 1, 0, n - 1);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    partial_sum(arr, arr + maxN, pref);

    divideAndConquerDP(k, n);
    cout << dp[k - 1][n - 1] << endl;
}

int32_t main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

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
