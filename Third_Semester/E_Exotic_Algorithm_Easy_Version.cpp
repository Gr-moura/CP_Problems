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

vector<int> id;
vector<int> sz;

int find(int x)
{
    return id[x] = id[x] == x ? x : find(id[x]);
}

void uni(int x, int y)
{
    x = find(x), y = find(y);

    if (x == y) return;

    if (sz[x] > sz[y])
    {
        sz[x] += sz[y];
        id[y] = id[x];
        return;
    }

    id[y] = id[x];
    sz[y] += sz[x];
}

void solve()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        id.pb(i);
        sz.pb(0);
    }

    for (int mid = 0; mid < s.size(); mid++)
    {
        int left = mid - 1, right = mid + 1;

        // impar
        while (left >= 0 and right < s.size() and s[left] == s[right])
        {
            uni(left, right);
            left--, right++;
        }

        // par
        left = mid, right = mid + 1;
        while (left >= 0 and right < s.size() and s[left] == s[right])
        {
            uni(left, right);
            left--, right++;
        }
    }

    set<int> ans;
    for (int i = 0; i < s.size(); i++)
    {
        ans.insert(find(i));
    }

    cout << ans.size() << endl;
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
