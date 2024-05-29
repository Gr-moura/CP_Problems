#include <bits/stdc++.h>
using namespace std;

#define _                                                                                                              \
    ios_base ::sync_with_stdio(0);                                                                                     \
    cin.tie(0);
#define vi vector<int>
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl;
#define f first
#define s second

void solve()
{
    string str;
    cin >> str;
    map<pair<pair<int, int>, pair<int, int>>, int> caminhos;

    pair<int, int> pos_atual = {0, 0};
    pair<int, int> destino = {0, 0};

    int len = str.size();
    int time = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'N')
            destino.s++;
        if (str[i] == 'S')
            destino.s--;
        if (str[i] == 'W')
            destino.f++;
        if (str[i] == 'E')
            destino.f--;

        // se não existir o caminho atual e nem o inverso
        if (caminhos[{pos_atual, destino}] == 0 && caminhos[{destino, pos_atual}] == 0)
            time += 5;
        else
            time += 1;
        caminhos[{pos_atual, destino}] = 1;
        pos_atual = destino;
    }
    cout << time << endl;
}

int main()
{
    _ int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

 
