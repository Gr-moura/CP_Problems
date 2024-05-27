#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define int long long
#define vi vector<int>
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(a) ((int)((a).size()))
#define char unsigned char
const int INF = 0x3f3f3f3f;

typedef long double ld;

int turn_into_ms(string s)
{
    int min, sec, ms;
    if (s.size() == 8)
    {
        min = s[0] - '0';
        sec = (s[2] - '0') * 10 + (s[3] - '0');
        ms = (s[5] - '0') * 100 + (s[6] - '0') * 10 + (s[7] - '0');
    }

    else
    {
        min = (s[0] - '0') * 10 + (s[1] - '0');
        sec = (s[3] - '0') * 10 + (s[4] - '0');
        ms = (s[6] - '0') * 100 + (s[7] - '0') * 10 + (s[8] - '0');
    }

    int solve = min * 60 * 1000 + sec * 1000 + ms;
    return solve;
}

int32_t main()
{
    int drivers, laps, num, tempo_total, tempo_parcial;
    vi tts;
    cin >> drivers >> laps;
    map<int, pair<int, int>> tempos; // tempo da lap, quando terminou ela, numero
    map<int, int> tt;
    int menor = INF;
    for (int i = 0; i < drivers; i++)
    {
        cin >> num;
        tempo_total = 0;
        for (int j = 0; j < laps; j++)
        {

            string temp;
            cin >> temp;
            int add = turn_into_ms(temp);
            tempo_parcial = add;
            tempo_total += add;
            if (tempo_parcial < menor || (tempo_parcial == menor && tempo_total < tempos[tempo_parcial].f))
            {
                menor = tempo_parcial;
                tempos[tempo_parcial].f = tempo_total;
                tempos[tempo_parcial].s = num;
            }
        }

        tt[num] = tempo_total;
        tts.pb(tempo_total);
    }

    sort(all(tts));
    int mais_rapida = tempos.begin()->first;
    int corredor_mais_rapido = tempos[mais_rapida].s;
    int tempo_total_volta_rapida = tt[corredor_mais_rapido];

    for (int i = 0; i < 10; i++)
    {
        if (tts[i] == tempo_total_volta_rapida)
        {
            cout << corredor_mais_rapido << endl;
            return 0;
        }
    }

    cout << "NENHUM\n";
    return 0;
}
