#include <bits/stdc++.h>
using namespace std;
int ehvogal(char s)
{
    vector<char> vogais = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};
    for (auto c: vogais)
    {
        if (c==s)
        {
            return 1;
        }
    }

    return 0;
}


int main () 
{
    string s; cin >> s;
    for (auto c: s)
    {
        if (!ehvogal(c)) cout << "." << (char)tolower(c);
    }
    return 0;
} 
