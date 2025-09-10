/* clang-format off */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct FenwickXor {
    int n;
    vector<ull> bit; // guarda XORs
    FenwickXor(int n=0): n(n), bit(n+1, 0) {}
    void init(int n_) { n = n_; bit.assign(n+1, 0); }
    // aplica XOR em posição i (1-indexed)
    void update(int i, ull val) {
        for (; i <= n; i += i & -i) bit[i] ^= val;
    }
    // XOR prefixo [1..i]
    ull query(int i) const {
        ull res = 0;
        for (; i > 0; i -= i & -i) res ^= bit[i];
        return res;
    }
    // XOR no intervalo [l..r]
    ull range_query(int l, int r) const {
        return query(r) ^ query(l-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<ll> a(N+1);
    for (int i = 1; i <= N; ++i) cin >> a[i];

    FenwickXor fw(N);
    // constrói BIT com os valores iniciais
    for (int i = 1; i <= N; ++i) fw.update(i, (ull)a[i]);

    for (int qi = 0; qi < Q; ++qi) {
        char t; 
        cin >> t;
        if (t == 'P') {
            int l, r; cin >> l >> r;
            ull xr = fw.range_query(l, r);
            if (xr != 0) cout << "FRANK\n"; // primeiro vence
            else          cout << "JUAN\n";
        } else { // 'R' ritual: R k x  (soma x em a[k])
            int k; ll x; cin >> k >> x;
            ll novo = a[k] + x;
            ull delta = (ull)a[k] ^ (ull)novo; // diferença para o BIT de XOR
            fw.update(k, delta);
            a[k] = novo;
        }
    }
    return 0;
}
