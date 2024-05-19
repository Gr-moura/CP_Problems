#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base :: sync_with_stdio(0); cin.tie(0);
#define vi vector <int>
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back

void solve()
{
    int n, l, d; cin >> n >> l >> d;
    long long necessario = n * d;
    l = l * 1000;
    cout << ((n * d + l - 1)/l)*l/1000 << endl;
}
 
int main()
{ _
    int a; cin >> a;
    while (a--) 
    solve();
 
 
    return 0;
}