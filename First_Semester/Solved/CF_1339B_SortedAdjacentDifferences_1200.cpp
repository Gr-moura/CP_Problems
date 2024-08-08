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

void solve()
{
    int len, add;
    cin >> len;
    vi lista(len);
    vi resposta;

    for (int i = 0; i < len; i++)
        cin >> lista[i];
    sort(all(lista));

    for (int inicio = 0, fim = len - 1; inicio <= fim; inicio++, fim--)
    {
        if (inicio == fim)
            resposta.push_back(lista[fim]);
        else
        {
            resposta.push_back(lista[inicio]);
            resposta.push_back(lista[fim]);
        };
    }

    reverse(all(resposta));

    for (int i = 0; i < len; i++)
        cout << resposta[i] << " ";
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
