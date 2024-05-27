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
    //pega um index tal que o anterior e o proximo sao iguais, e iguala o atual a eles
    int len; cin >> len;
    vi v(len); for (auto& i: v) cin >> i;

    int inicio = v[0];
    int menor_dist = 10e6;
    int dist = 0;

    for (int i = 0; i < len; i++)
    {
        dist++;

        if (v[i] != inicio)
        {
            if (dist < menor_dist) menor_dist = dist;
            dist = 0;
        }
    }

    if (dist < len && dist < menor_dist) {cout << dist << endl; return;}
    if (menor_dist == 10e6) cout << "-1\n";
    else cout << menor_dist - 1 << endl;
    


}
 
int main()
{ _
    int a; cin >> a;
    while (a--) solve();
 
 
    return 0;
}