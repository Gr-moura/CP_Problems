#include <bits/stdc++.h>
#include <string>
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

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// O nosso objetivo é contar quantos bits são diferentes entre dois números
// Para isso, podemos utilizar o operador XOR e depois converter
// a resposta para binário

int transformar(int num)
{
    string ans;
    int soma = 0;
    cout << num;
    // A saída estará ao contrário, mas a gente só precisa contar o número de "1"
    while (num > 0)
    {
        ans += to_string(num % 2);
        num = num / 2;
    }

    cout << ans;
    return soma;
}

void solve()
{
    int a;
    cin >> a;

    cout << transformar(a);
}

int32_t main()
{
    fast_io;
    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
