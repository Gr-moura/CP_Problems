#include <bits/stdc++.h>
using namespace std;

#define forn(variavel, inicio, fim) for(int variavel = inicio; variavel < fim; variavel++)
#define _ ios_base :: sync_with_stdio(0); cin.tie(0);
#define vll vector <long long>
#define ll long long
#define endl '\n'



void solve()
{
    string a, b; cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[a.size() - 1 - i]) 
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main()
{
    solve();
    
    return 0;
}