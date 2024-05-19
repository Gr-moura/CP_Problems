#include <bits/stdc++.h>
using namespace std;

#define forn(a,b) for(int a = 0; a < b; a++)
#define endl '\n'

void solve()
{
    int rows, columns;
    cin >> rows >> columns;
    
    int matriz [rows][columns];
    int somas [rows + columns];
    int maior = 0;

    forn(i, rows + columns)
    {
        somas [i] = 0;

    }

    forn (i, rows)
    {
        forn (j, columns)
        {
            cin >> matriz [i][j];
            somas [i] = somas [i] + matriz [i][j];
            
        }
        if (somas [i] > maior) maior = somas[i]; 

    }

    forn (j, columns)
    {
        forn (i, rows)
        {
            somas [rows + j] += matriz [i][j];

        }
        if (somas [rows + j] > maior) maior = somas[rows + j];

    }
    
    cout << maior;

}

int main()
{
    solve();

    return 0;
}