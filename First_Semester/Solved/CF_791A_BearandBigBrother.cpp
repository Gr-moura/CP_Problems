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
    int a, b, vezes = 1; cin >> a >> b;
    while (a*3 <= b*2)
    {
        vezes++;
        a *= 3; b *= 2;
    }
    cout << vezes;

}
 
int32_t main()
{ _
    // int t; cin >> t;
    // while(t--) 
    solve();

    return 0;
}