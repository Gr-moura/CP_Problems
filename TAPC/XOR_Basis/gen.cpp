/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

int rand(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

int32_t main(int32_t argc, char **argv)
{
    _, srand(atoi(argv[1]));

    int t = 1;
    cout << t << endl;
    for (int i = 0; i < t; i++)
    {
        int n = rand(1, 5);
        cout << n << " " << rand(1, 10) << endl;
        for (int j = 0; j < n; j++)
        {
            cout << rand(1, 10) << " ";
        }
        cout << endl;

        for (int j = 0; j < n; j++)
        {
            cout << rand(1, 10) << " ";
        }
        cout << endl;
    }

    return 0;
}