#include <bits/stdc++.h>
using namespace std;

#define insert_vector(a, b) copy(a.begin(), a.end(), back_inserter(b))
#define all(x) x.begin(), x.end()
#define vi vector <int>

void solve()
{
    int length, m, add, resto = 1; 
    cin >> length;
    cin >> m;
    vi array;
    string LR;

    for (int i = 0; i < length; i++)
    {
        cin >> add;
        array.push_back(add);
    }

    vi ordem(length);
    cin >> LR;

    for (int i = 0, inicio = 0, fim = length - 1; i < length; i ++)
    {
        if (LR[i] == 'L') { ordem[i] = array[inicio]; inicio ++; }
        else if (LR[i] == 'R') { ordem[i] = array[fim]; fim --; }
    }

    vi ans;

    for (int i = length - 1; i >= 0; i --)
    {
        resto = (resto * ordem[i]) % m;
        ans.push_back(resto);
    }

    for (int i = length - 1; i >= 0; i --)
    {
        cout << ans[i] << ' ';
    }

    cout << endl;

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