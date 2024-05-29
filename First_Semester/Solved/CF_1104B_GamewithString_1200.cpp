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
    _ string str;
    cin >> str;
    int cnt = 0;

    for (int i = 1; i < str.size(); i++)
    {
        char atual = str[i];
        char anterior = str[i - 1];

        if (atual == anterior)
        {
            cnt++;

            str.erase(str.begin() + i);
            str.erase(str.begin() + i - 1);

            i = i - 2;
        }
    }

    if (cnt % 2)
        cout << "Yes";
    else
        cout << "No";
}

 
