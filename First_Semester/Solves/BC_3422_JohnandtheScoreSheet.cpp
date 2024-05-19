#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base :: sync_with_stdio(0); cin.tie(0);
#define int long long
#define vi vector <int>
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back

void solve()
{
    int min, tempo; string s; cin >> min >> s; tempo = s[0] - '0';
    if (tempo == 1)
    {
        if (min > 45)
        {
            cout << "45+" << min%45 << endl;
            return;
        }

        else cout << min << endl;
    }

    if (tempo == 2)
    {
        if (min > 45)
        {
            cout << "90+" << min%45 << endl;
            return;
        }

        else cout << 45 + min << endl;
    }

}
 
int32_t main()
{ _
    int t; cin >> t;
    while(t--) 
    solve();

    return 0;
}