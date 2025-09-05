/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; i++) if (a % i == 0) return 0; return 1; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
vector<int> seg, seg2, v;

int build(int l, int r, int i)
{
    if (l == r)
    {
        if (v[l] == 1) return seg[i] = 1;
        else return seg[i] = 0;
    }

    int m = (l + r) / 2;
    return seg[i] = build(l, m, 2 * i + 1) + build(m + 1, r, 2 * i + 2);
}

int upd(int idx, int l, int r, int i, int va)
{
    if (l == r)
    {
        v[l] += va;
        if (v[l] == 1) return seg[i] = 1;
        else return seg[i] = 0;
    }

    if (l > idx or r < idx) return seg[i];
    int m = (l + r) / 2;
    return seg[i] = upd(idx, l, m, 2 * i + 1, va) + upd(idx, m + 1, r, 2 * i + 2, va);
}

int query(int lx, int rx, int l, int r, int i)
{
    if (lx >= l and rx <= r) return seg[i];
    if (lx > r or rx < l) return 0;

    int m = (lx + rx) / 2;
    return query(lx, m, l, r, 2 * i + 1) + query(m + 1, rx, l, r, 2 * i + 2);
}

int build2(int l, int r, int i)
{
    if (l == r)
    {
        if (v[l] == 0) return seg2[i] = 1;
        else return seg2[i] = 0;
    }

    int m = (l + r) / 2;
    return seg2[i] = build2(l, m, 2 * i + 1) + build2(m + 1, r, 2 * i + 2);
}

int upd2(int idx, int l, int r, int i)
{
    if (l == r)
    {
        if (v[l] == 0) return seg2[i] = 1;
        else return seg2[i] = 0;
    }

    if (l > idx or r < idx) return seg2[i];
    int m = (l + r) / 2;
    return seg2[i] = upd2(idx, l, m, 2 * i + 1) + upd2(idx, m + 1, r, 2 * i + 2);
}

int query2(int lx, int rx, int l, int r, int i)
{
    if (lx >= l and rx <= r) return seg2[i];
    if (lx > r or rx < l) return 0;

    int m = (lx + rx) / 2;
    return query2(lx, m, l, r, 2 * i + 1) + query2(m + 1, rx, l, r, 2 * i + 2);
}

vector<int> qt;
void solve()
{
    int n, q;
    cin >> n >> q;

    int auxn = 1;
    while (auxn < n)
        auxn *= 2;

    v = vector<int>(auxn, -1);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    seg = vector<int>(auxn * 2, 0);
    seg2 = vector<int>(auxn * 2, 0);

    build(0, auxn - 1, 0);
    build2(0, auxn - 1, 0);

    for (int i = 0; i < q; i++)
    {
        string a;
        int b, c;

        cin >> a >> b >> c;
        if (a == "R")
        {

            upd(c - 1, 0, auxn - 1, 0, b);
            upd2(c - 1, 0, auxn - 1, 0);

            continue;
        }

        int uns = query(0, auxn - 1, b - 1, c - 1, 0);
        int zeros = query2(0, auxn - 1, b - 1, c - 1, 0);

        int ganhador = !((uns + ((c - b) - zeros)) % 2);
        if (ganhador)
        {
            std::cout << "FRANK\n";
            continue;
        }

        std::cout << "JUAN\n";
    }
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);

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
