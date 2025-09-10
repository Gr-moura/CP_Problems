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
void solve(int a, int b)
{

    if (b % 2 == 1 and a % 2 == 0)
    {
        cout << -1 << endl;
        return;
    }

    if (a % 2 == 0 and b % 2 == 1)
    {
        cout << -1 << endl;
    }

    if (b % 2 == 0 and b % 4 != 0 and a % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }

    if (a % 2 == 1 and b % 2 == 1)
    {
        cout << a * b + 1 << endl;
        return;
    }

    cout << a * b / 2 + 2 << endl;
}

void solve2(int a, int b)
{
    long long a, b;
    cin >> a >> b;

    int t = __builtin_ctzll(b); // v2(b), works for nonzero b
    vector<long long> cand;

    if ((a & 1LL) == 0)
    { // a even
        if (t == 0)
        {
            cout << -1 << '\n';
            continue;
        }
        cand.push_back(1);
        cand.push_back(b / 2);
    }
    else
    { // a odd
        if (t == 0)
        {
            cand.push_back(b);
        }
        else if (t == 1)
        {
            cout << -1 << '\n';
            continue;
        }
        else
        { // t >= 2
            cand.push_back(2);
            cand.push_back(b / 2);
        }
    }

    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    bool found = false;
    long long best = 0;
    for (auto k : cand)
    {
        if (k == 0 || b % k != 0) continue;
        long long val = a * k + b / k;
        if ((val & 1LL) == 0)
        { // even
            if (!found || val > best)
            {
                best = val;
                found = true;
            }
        }
    }

    if (!found) cout << -1 << '\n';
    else cout << best << '\n';
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
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;
        solve(a, b);
        solve2(a, b);

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
