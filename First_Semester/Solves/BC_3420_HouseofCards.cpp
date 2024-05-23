#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base ::sync_with_stdio(0);cin.tie(0);
#define int long long
#define vi vector<int>
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(a) ((int)((a).size()))
#define char unsigned char

typedef long double ld;

int32_t main()
{ _ 
    vector<pair<int, int>> v;
    int t = 1;
    cin >> t;
    vector <int> pedidos(t); for (auto& i : pedidos) cin >> i;
    
    int cartas = 2;
    v.push_back({2, 1});
    for (int i = 1; cartas <= 1000000000000000000; i++)
    {
        cartas = v[i - 1].f + i + (i + 1) * 2;
        v.pb(cartas);
    }
    

    for (int i = 1; i <= t; i++)
    {
        int c;
        cin >> c;
        int j;
        for (j = 0; v[j] <= c; j++)
            ;
        cout << j << endl;
    }

#ifdef ONPC
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
