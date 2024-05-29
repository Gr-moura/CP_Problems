#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int maior, temp, maiorindex;
    int stop = 0;

    int tam = a.size();

    for (int i = 0; i < tam && stop == 0; i++)
    {

        if (a[i] > b[i])
        {
            maior = 1;
            maiorindex = i;
            stop = 1;
        }

        if (a[i] < b[i])
        {
            maior = 2;
            maiorindex = i;
            stop = 1;
        }
    }

    stop = 0;

    if (maior == 1)
    {
        for (int i = maiorindex + 1; i < tam && stop == 0; i++)
        {
            if (a[i] > b[i])
            {
                temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            }
        }
    }

    if (maior == 2)
    {
        for (int i = maiorindex + 1; i < tam && stop == 0; i++)
        {
            if (b[i] > a[i])
            {
                temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            }
        }
    }
    cout << a << '\n' << b << '\n';
}

int main()
{

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
