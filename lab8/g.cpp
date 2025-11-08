#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

const ll P = 31;
const ll M = 1e9 + 9;

vector<ll> p_pow;

void precompute_powers(int max_len) {
    p_pow.resize(max_len + 1);
    p_pow[0] = 1;
    for (int i = 1; i <= max_len; i++) {
        p_pow[i] = (p_pow[i - 1] * P) % M;
    }
}

vector<ll> compute_prefix_hashes(const string& s) {
    int n = s.length();
    vector<ll> h(n);
    h[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < n; i++) {
        h[i] = (h[i - 1] * P + (s[i] - 'a' + 1)) % M;
    }
    return h;
}

ll get_substring_hash(const vector<ll>& h, int l, int r) {
    ll hash_val = h[r];
    if (l > 0) {
        int len = r - l + 1;
        ll hash_to_subtract = (h[l - 1] * p_pow[len]) % M;
        hash_val = (hash_val - hash_to_subtract + M) % M;
    }
    return hash_val;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();

    precompute_powers(n);
    vector<ll> h = compute_prefix_hashes(s);

    map<int, map<ll, int>> hash_counts_by_len;
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            ll sub_hash = get_substring_hash(h, i, i + len - 1);
            hash_counts_by_len[len][sub_hash]++;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; 
        r--; 
        int len = r - l + 1;
        ll target_hash = get_substring_hash(h, l, r);
        cout << hash_counts_by_len[len][target_hash] << "\n";
    }

    return 0;
}