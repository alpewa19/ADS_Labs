#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

using ll = long long;

const ll P1 = 31;
const ll M1 = 1e9 + 9;

const ll P2 = 53;
const ll M2 = 1e9 + 7;

vector<ll> p_pow1;
vector<ll> p_pow2;

void precompute_powers(int max_len) {
    p_pow1.resize(max_len + 1);
    p_pow2.resize(max_len + 1);
    p_pow1[0] = 1;
    p_pow2[0] = 1;
    for (int i = 1; i <= max_len; i++) {
        p_pow1[i] = (p_pow1[i - 1] * P1) % M1;
        p_pow2[i] = (p_pow2[i - 1] * P2) % M2;
    }
}

struct PrefixHashes {
    vector<ll> h1;
    vector<ll> h2;
};

PrefixHashes compute_prefix_hashes(const string& s) {
    int n = s.length();
    PrefixHashes hashes;
    hashes.h1.resize(n);
    hashes.h2.resize(n);

    hashes.h1[0] = (s[0] - 'a' + 1);
    hashes.h2[0] = (s[0] - 'a' + 1);

    for (int i = 1; i < n; i++) {
        hashes.h1[i] = (hashes.h1[i - 1] * P1 + (s[i] - 'a' + 1)) % M1;
        hashes.h2[i] = (hashes.h2[i - 1] * P2 + (s[i] - 'a' + 1)) % M2;
    }
    return hashes;
}

ll get_substring_hash1(const vector<ll>& h, int l, int r) {
    ll hash_val = h[r];
    if (l > 0) {
        int len = r - l + 1;
        ll hash_to_subtract = (h[l - 1] * p_pow1[len]) % M1;
        hash_val = (hash_val - hash_to_subtract + M1) % M1;
    }
    return hash_val;
}

ll get_substring_hash2(const vector<ll>& h, int l, int r) {
    ll hash_val = h[r];
    if (l > 0) {
        int len = r - l + 1;
        ll hash_to_subtract = (h[l - 1] * p_pow2[len]) % M2;
        hash_val = (hash_val - hash_to_subtract + M2) % M2;
    }
    return hash_val;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    precompute_powers(n);
    PrefixHashes h = compute_prefix_hashes(s);

    vector<pair<ll, ll>> all_hashes;
    
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            ll hash1 = get_substring_hash1(h.h1, i, i + len - 1);
            ll hash2 = get_substring_hash2(h.h2, i, i + len - 1);
            all_hashes.push_back({hash1, hash2});
        }
    }

    sort(all_hashes.begin(), all_hashes.end());
    
    auto it = unique(all_hashes.begin(), all_hashes.end());
    
    cout << distance(all_hashes.begin(), it) << "\n";

    return 0;
}