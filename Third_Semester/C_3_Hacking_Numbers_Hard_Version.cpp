/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
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
int add(int y)
{
    cout << "add " << y << endl;
    fflush(stdout);

    int ans;
    cin >> ans;

    return ans;
}

int mult(int y)
{
    cout << "mul " << y << endl;
    fflush(stdout);

    int ans;
    cin >> ans;

    return ans;
}

int digit()
{
    cout << "digit" << endl;
    fflush(stdout);

    int ans;
    cin >> ans;

    return ans;
}

void f()
{
    cout << "!" << endl;
    fflush(stdout);

    int ans;
    cin >> ans;
}

void solve()
{
    int n;
    cin >> n;

    // Quando um número em [1, 10^d] é multiplicado por 10^d -1, a soma de todos os seus dígitos
    // passa a ser igual a 9 * d. Assim, quando multiplicamos qualquer número em [1, 10^9]
    // por 10^9 - 1, a soma de todos os seus dígitos passa a ser igual a 9 * 9 = 81.

    // x e [1, 1e9]
    int ans1 = mult(1e9 - 1); // 1
    int ans2 = digit();       // 2

    // x e [81, 81]
    if (n == 81)
    {
        f();
        return;
    }

    int ans3 = add(n - 81); // 3
    f();
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
