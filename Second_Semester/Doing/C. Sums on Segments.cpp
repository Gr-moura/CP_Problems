#include "Headers.h"
#include <bits/stdc++.h>
#include <unordered_map>
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
    int n;
    cin >> n;

    vi nums(n);

    set<int> s;
    s.insert(0);

    int index = 0;
    int dif = -1;

    for (auto &i : nums)
    {
        cin >> i;

        if (i != 1 && i != -1)
            dif = index;

        s.insert(i);
        index++;
    }

    int maiorIncluindo = 0;
    int menorIncluindo = 0;
    int maiorAntes = 0;
    int menorAntes = 0;
    int maiorDepois = 0;
    int menorDepois = 0;

    int tempMin = 0;
    int tempMax = 0;

    for (int i = 0; i < dif; i++)
    {
        tempMin += nums[i];
        tempMax += nums[i];

        menorAntes = min(menorAntes, tempMin);
        maiorAntes = max(maiorAntes, tempMax);

        tempMin = min(tempMin, 0ll);
        tempMax = max(tempMax, 0ll);

        s.insert(menorAntes);
        s.insert(maiorAntes);
    }

    tempMin = 0;
    tempMax = 0;

    for (int i = dif + 1; i < n; i++)
    {
        tempMin += nums[i];
        tempMax += nums[i];

        menorDepois = min(menorDepois, tempMin);
        maiorDepois = max(maiorDepois, tempMax);

        tempMin = min(tempMin, 0ll);
        tempMax = max(tempMax, 0ll);

        s.insert(menorDepois);
        s.insert(menorDepois);
    }

    tempMin = nums[dif];
    tempMax = nums[dif];
    menorIncluindo = nums[dif];
    maiorIncluindo = nums[dif];

    for (int i = dif - 1; i >= 0; i--)
    {
        tempMin += nums[i];
        tempMax += nums[i];

        menorIncluindo = min(menorIncluindo, tempMin);
        maiorIncluindo = max(maiorIncluindo, tempMax);

        s.insert(maiorIncluindo);
        s.insert(menorIncluindo);
    }

    tempMin = nums[dif];
    tempMax = nums[dif];

    for (int i = 0; i < n; i++)
    {
        tempMax += nums[i];
        tempMin += nums[i];

        maiorIncluindo = max(maiorIncluindo, tempMax);
        menorIncluindo = min(menorIncluindo, tempMin);

        s.insert(maiorIncluindo);
        s.insert(menorIncluindo);
    }

    for (int i = dif - 1; i >= 0; i--)
    {
        tempMax += nums[i];
    }

    for (int i = dif + 1; i < n; i++)
    {
        tempMax += nums[i];
        maiorIncluindo = max(maiorIncluindo, tempMax);
    }

    for (int i = menorAntes; i <= maiorAntes; i++)
    {
        s.insert(i);

        if (dif != -1)
            s.insert(i + nums[dif]);
    }

    for (int i = menorDepois; i <= menorDepois; i++)
    {
        s.insert(i);

        if (dif != -1)
            s.insert(i + nums[dif]);
    }

    for (int i = menorAntes + menorDepois; i <= maiorAntes + maiorDepois; i++)
    {
        if (dif != -1)
            s.insert(i + nums[dif]);
    }

    cout << s.size() << endl;

    for (auto i : s)
    {
        cout << i << " ";
    }

    cout << endl;
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
