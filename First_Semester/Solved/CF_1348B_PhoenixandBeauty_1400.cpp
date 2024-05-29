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
#define pb push_back

void solve()
{
    int tam, period, add;
    cin >> tam >> period;
    int ultimo;
    set<int> s;
    vi original;

    for (int i = 0; i < tam; i++)
    {
        cin >> add;
        s.insert(add);
        original.pb(add);
    }

    if (s.size() > period)
    {
        cout << "-1\n";
        return;
    }

    int len = 0;
    int vezes = -1;
    for (auto i : s)
    {
        if (count(all(original), i) > vezes)
            vezes = count(all(original), i);
    }

    int completar = period - s.size();

    vezes += 15;

    int soma = 0;
    for (auto i : s)
    {
        soma += i;
    }
    soma += completar;
    vezes = 9999 / period;
    cout << period * vezes + 1 << endl;

    if (s.size() == period)
    {
        for (int i = 0; i < vezes; i++)
        {
            for (auto j : s)
            {

                cout << j << " ";
                ultimo = j;
            }
        }
        cout << *s.begin();
    }

    else
    {

        for (int i = 0; i < vezes; i++)
        {
            for (auto j : s)
            {
                cout << j << " ";
                ultimo = j;
            }

            for (int j = 1; j <= completar; j++)
            {
                cout << "1 ";
                ultimo = 1;
            }
        }
        cout << *s.begin();
    }

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

 
