/*
ID: gabriel139
LANG: C++
TASK: test
*/

/* clang-format off */
#include <bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
struct Eertree
{
    struct Node
    {
        int len, link, quick;
        int num; // Quantidade de palindromos terminando neste nó (depth do suffix link)
        int next[26];

        Node(int l = 0, int k = 0, int q = 0, int n = 0) : len(l), link(k), quick(q), num(n)
        {
            memset(next, 0, sizeof(next));
        }
    };

    struct State
    {
        int lastNode, newNode, noPai, charPai;
        int prevDiff; // Quanto este passo adicionou ao total
    };

    vector<Node> t;
    vector<State> h;
    string s;
    int last;
    int totalPalindromes = 0; // Resultado acumulado

    Eertree()
    {
        t.eb(0, 1, 1);  // 0: Even root
        t.eb(-1, 0, 0); // 1: Odd root
        last = 0;
        s = "#";
    }

    int get_link(int v)
    {
        int n = s.size();
        while (1)
        {
            int l = t[v].len;
            if (n - 2 - l >= 0 && s[n - 2 - l] == s.back()) break;

            if (t[v].link > 1 && s[n - 2 - t[t[v].link].len] != s.back()) v = t[v].quick;
            else v = t[v].link;
        }
        return v;
    }

    void add(char c)
    {
        s += c;
        int cur = get_link(last);
        int let = c - 'a';

        State st = {last, -1, cur, let, 0};

        if (!t[cur].next[let])
        {
            int len = t[cur].len + 2;
            int link = (len == 1) ? 0 : t[get_link(t[cur].link)].next[let];

            int qlink = 0;
            if (link > 1)
            {
                int pos = s.size() - 1;
                if (s[pos - t[link].len] == s[pos - t[t[link].link].len]) qlink = t[link].quick;
                else qlink = t[link].link;
            }

            else qlink = (t[link].len == -1) ? 1 : 0;

            // O próprio palindromo + contagem do seu maior sufixo
            int num = 1 + t[link].num;

            t.eb(len, link, qlink, num);

            t[cur].next[let] = t.size() - 1;
            st.newNode = t.size() - 1;
        }

        last = t[cur].next[let];

        totalPalindromes += t[last].num;
        h.pb(st);
    }

    void pop()
    {
        if (h.empty()) return;

        totalPalindromes -= t[last].num;

        State st = h.back();
        h.pop_back();

        last = st.lastNode; // Restaura ponteiro do maior sufixo
        if (st.newNode != -1)
        {                                     // Se criou nó
            t[st.noPai].next[st.charPai] = 0; // Remove aresta
            t.pop_back();                     // Remove nó da memória
        }

        s.pop_back(); // Remove char da string
    }
};

void solve()
{
    int q;
    cin >> q;

    Eertree eertree;

    string s;
    cin >> s;

    for (auto c : s)
    {
        if (c == '-') eertree.pop();
        else eertree.add(c);

        cout << eertree.totalPalindromes << " ";
    }
}

int32_t main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
