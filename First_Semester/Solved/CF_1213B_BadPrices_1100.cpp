#include <bits/stdc++.h>
using namespace std;

#define fori(inicio, fim) for(long long i = inicio; i < fim; i++)
#define _ ios_base :: sync_with_stdio(0); cin.tie(0);
#define vll vector <long long>
#define vi vector <int>
#define ll long long
#define endl '\n'

/*
    Começamos do final e vemos se existe algum número maior do que ele.
    Se sim, aumentamos a qt de dias ruins.
    Se não, então esse número passa a ser o novo menor número.
*/
void solve()
{
    int days, count = 0; cin >> days;
    vi prices(days + 1);

    fori (1, days + 1) cin >> prices [i];
    
    int atual_menor = prices [days];

    for (int i = days; i > 0; i--)
    {
        if (prices[i-1] > atual_menor)
        {
            count++;
        }

        else
        {
            atual_menor = prices[i-1];
        }
    }

    cout << count;

}

int main()
{
    int t; cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }
    
    return 0;
}