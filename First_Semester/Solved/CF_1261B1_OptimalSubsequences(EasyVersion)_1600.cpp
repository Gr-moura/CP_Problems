#include <bits/stdc++.h>
using namespace std;

#define _                                                                                                              \
    ios_base ::sync_with_stdio(0);                                                                                     \
    cin.tie(0);
#define vi vector<int>
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl;

int main()
{
    _ int length;
    cin >> length;
    vi atual(length);

    for (int i = 0; i < length; i++)
        cin >> atual[i];

    vector<int> s;

    int t, tam, pos;
    cin >> t;

    vector<vector<int>> res(t, vector<int>(2));

    // pego os pedidos
    map<int, vector<int>> posicoes;
    map<int, map<int, int>> respostas;

    for (int i = 0; i < t; i++)
    {
        cin >> tam >> pos;

        res[i][0] = tam;
        res[i][1] = pos;
        posicoes[tam].push_back(pos);

        if (count(s.begin(), s.end(), tam) == 0)
        {
            s.push_back(tam);
        }
    }

    sort(s.begin(), s.end(), greater<>());
    int menor;
    int size_we_want;
    vi sorted = atual;
    sort(sorted.begin(), sorted.end(), greater<>());

    // pego os tamanhos que pedem e vou resolvendo em ordem decrescente
    for (auto i : s)
    {

        length = atual.size();
        size_we_want = i;

        while (length - size_we_want)
        {
            length = atual.size();

            auto it = find(atual.rbegin(), atual.rend(), sorted[sorted.size() - 1]);

            if (it != atual.rend())
            {
                atual.erase((it + 1).base()); // Convert reverse iterator to forward iterator
            }

            sorted.pop_back();
            length--;
        }

        for (int u = 0; u < posicoes[size_we_want].size(); u++)
        {
            respostas[size_we_want][posicoes[size_we_want][u]] = atual[posicoes[size_we_want][u] - 1];
        }
    }

    // printo as respostas
    for (int i = 0; i < t; i++)
    {
        cout << respostas[res[i][0]][res[i][1]] << endl;
    }

    return 0;
}
