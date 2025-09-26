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

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

void solve()
{
    int n1, n2, n3, n4, n5;
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    int a[n1][n2][n3][n4][n5];
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            for (int k = 0; k < n3; k++)
                for (int l = 0; l < n4; l++)
                    for (int m = 0; m < n5; m++)
                        cin >> a[i][j][k][l][m];

    int b[n1 + 1][n2 + 1][n3 + 1][n4 + 1][n5 + 1];
    memset(b, 0, sizeof(b));

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            for (int k = 0; k < n3; k++)
                for (int l = 0; l < n4; l++)
                    for (int m = 0; m < n5; m++)
                        b[i + 1][j + 1][k + 1][l + 1][m + 1] =
                            b[i][j + 1][k + 1][l + 1][m + 1] + b[i + 1][j][k + 1][l + 1][m + 1] +
                            b[i + 1][j + 1][k][l + 1][m + 1] + b[i + 1][j + 1][k + 1][l][m + 1] +
                            b[i + 1][j + 1][k + 1][l + 1][m] - b[i][j][k + 1][l + 1][m + 1] -
                            b[i][j + 1][k][l + 1][m + 1] - b[i][j + 1][k + 1][l][m + 1] - b[i][j + 1][k + 1][l + 1][m] -
                            b[i + 1][j][k][l + 1][m + 1] - b[i + 1][j][k + 1][l][m + 1] - b[i + 1][j][k + 1][l + 1][m] -
                            b[i + 1][j + 1][k][l][m + 1] - b[i + 1][j + 1][k][l + 1][m] - b[i + 1][j + 1][k + 1][l][m] +
                            b[i][j][k][l + 1][m + 1] + b[i][j][k + 1][l][m + 1] + b[i][j][k + 1][l + 1][m] +
                            b[i][j + 1][k][l][m + 1] + b[i][j + 1][k][l + 1][m] + b[i][j + 1][k + 1][l][m] +
                            b[i + 1][j][k][l][m + 1] + b[i + 1][j][k][l + 1][m] + b[i + 1][j][k + 1][l][m] +
                            b[i + 1][j + 1][k][l][m] - b[i][j][k][l][m + 1] - b[i][j][k][l + 1][m] -
                            b[i][j][k + 1][l][m] - b[i][j + 1][k][l][m] - b[i + 1][j][k][l][m] + b[i][j][k][l][m] +
                            a[i][j][k][l][m];

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l1, l2, l3, l4, l5, r1, r2, r3, r4, r5;
        cin >> l1 >> l2 >> l3 >> l4 >> l5 >> r1 >> r2 >> r3 >> r4 >> r5;
        l1--, l2--, l3--, l4--, l5--;

        cout << b[r1][r2][r3][r4][r5] - b[l1][r2][r3][r4][r5] - b[r1][l2][r3][r4][r5] - b[r1][r2][l3][r4][r5] -
                    b[r1][r2][r3][l4][r5] - b[r1][r2][r3][r4][l5] + b[l1][l2][r3][r4][r5] + b[l1][r2][l3][r4][r5] +
                    b[l1][r2][r3][l4][r5] + b[l1][r2][r3][r4][l5] + b[r1][l2][l3][r4][r5] + b[r1][l2][r3][l4][r5] +
                    b[r1][l2][r3][r4][l5] + b[r1][r2][l3][l4][r5] + b[r1][r2][l3][r4][l5] + b[r1][r2][r3][l4][l5] -
                    b[l1][l2][l3][r4][r5] - b[l1][l2][r3][l4][r5] - b[l1][l2][r3][r4][l5] - b[l1][r2][l3][l4][r5] -
                    b[l1][r2][l3][r4][l5] - b[l1][r2][r3][l4][l5] - b[r1][l2][l3][l4][r5] - b[r1][l2][l3][r4][l5] -
                    b[r1][l2][r3][l4][l5] - b[r1][r2][l3][l4][l5] + b[l1][l2][l3][l4][r5] + b[l1][l2][l3][r4][l5] +
                    b[l1][l2][r3][l4][l5] + b[l1][r2][l3][l4][l5] + b[r1][l2][l3][l4][l5] - b[l1][l2][l3][l4][l5]
             << endl;
    }
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
