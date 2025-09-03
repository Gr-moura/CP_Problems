#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int maior = 0;
    string maiorPalindromo = "";

    for (int meio = 0; meio < (int)s.size(); meio++)
    {
        int l = meio, r = meio;
        while (l >= 0 && r < (int)s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }

        if (r - l > maior)
        {
            maior = r - l;
            maiorPalindromo = s.substr(l + 1, r - l - 1);
        }

        l = meio, r = meio + 1;
        while (l >= 0 && r < (int)s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }

        if (r - l > maior)
        {
            maior = r - l;
            maiorPalindromo = s.substr(l + 1, r - l - 1);
        }
    }

    cout << maiorPalindromo << endl;
}