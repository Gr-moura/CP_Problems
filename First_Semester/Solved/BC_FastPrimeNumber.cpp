#include <bits/stdc++.h>
using namespace std;

#define forn(a,b) for(int a = 0; a < b; a++)
#define endl '\n'


void solve()
{
    int numero;
    cin >> numero;
    if ((numero % 2 == 0 || numero == 1) && numero != 2)
    {
        cout << "Not Prime\n";
        return;
    }

    for (int i = 3; i*i <= numero; i += 2)
    {
        if (numero % i == 0)
        {
            cout << "Not Prime\n";
            return;
        }
    }
    
    cout << "Prime\n";

}

int main()
{
    int t; cin >> t;

    while (t--)
    {
        solve();

    }

    return 0;
}
