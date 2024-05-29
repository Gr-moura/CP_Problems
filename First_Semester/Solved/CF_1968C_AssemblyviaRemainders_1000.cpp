#include <bits/stdc++.h>
using namespace std;

#define _                                                                                                              \
    ios_base ::sync_with_stdio(0);                                                                                     \
    cin.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back

void solve()
{
    int length;
    cin >> length;
    vll v(length - 1);
    vll a(length);

    for (int i = 0; i < length - 1; i++)
    {
        cin >> v[i];
        // dbg(v[i]);
    }

    a[0] = 2 * 10e5;

    for (int i = 1; i < length; i++)
    {
        a[i] = (v[i - 1] + a[i - 1]);
        // dbg(a[i]);
    }

    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    _ int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

 
