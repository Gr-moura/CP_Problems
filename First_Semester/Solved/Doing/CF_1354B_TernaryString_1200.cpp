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
void solve()
{

    map<char, int> qt;
    string n = "123";

    int len = 0;
    string nums;
    cin >> nums;
    int l = 0, r = 1;
    qt[nums[l]]++;

    for (; r < nums.size() && !(qt['1'] != 0 && qt['2'] != 0 && qt['3'] != 0); r++)
    {
        qt[nums[r]]++;
    }

    // r estará um após achar o perfeito
    if (qt['1'] != 0 && qt['2'] != 0 && qt['3'] != 0)
    {
        len = r;
    }

    while (r < nums.size())
    {
        qt[nums[l]]--;
        l++;

        for (; r < nums.size() && !(qt['1'] != 0 && qt['2'] != 0 && qt['3'] != 0); r++)
        {
            qt[nums[r]]++;
        }

        if (qt['1'] != 0 && qt['2'] != 0 && qt['3'] != 0 && (r - l < len))
            len = r - l;
    }

    cout << len << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
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
