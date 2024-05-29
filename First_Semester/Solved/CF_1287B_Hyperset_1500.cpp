#include <bits/stdc++.h>
using namespace std;

#define _                                                                                                              \
    ios_base ::sync_with_stdio(0);                                                                                     \
    cin.tie(0);
#define vi vector<int>
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define f first
#define s second
#define all(x) x.begin(), x.end()

int main()
{
    _ int cartas, features, cnt = 0, achou = 0;
    cin >> cartas >> features;
    vector<string> baralho(cartas);

    string carta_procurada;
    map<string, int> mp;

    for (int i = 0; i < cartas; i++)
    {
        cin >> baralho[i];
        mp[baralho[i]] = 1;
    }

    sort(all(baralho));

    for (int i = 0; i < cartas - 2; i++)
    {
        for (int j = i + 1; j < cartas - 1; j++)
        {
            carta_procurada = "";

            for (int k = 0; k < features; k++)
            {
                if (baralho[i][k] == baralho[j][k])
                    carta_procurada += baralho[i][k];
                else
                    carta_procurada += ('S' + 'E' + 'T' - baralho[i][k] - baralho[j][k]);
            }

            if (mp[carta_procurada] == 1 && carta_procurada > baralho[j])
            {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
