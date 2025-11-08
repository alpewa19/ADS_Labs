#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

const ll P = 31;
const ll M = 1e9 + 9;

ll get_substring_hash(const vector<ll>& h, const vector<ll>& p_pow, int l, int r) {
    ll hash_val = h[r];
    if (l > 0) {
        hash_val = (hash_val - (h[l - 1] * p_pow[r - l + 1]) % M + M) % M;
    }
    return hash_val;
}

vector<ll> compute_prefix_hashes(const string& s, const vector<ll>& p_pow) {
    int n = s.length();
    vector<ll> h(n);
    h[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < n; ++i) {
        h[i] = (h[i - 1] * P + (s[i] - 'a' + 1)) % M;
    }
    return h;
}

int main() {
    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    int n1 = s1.length();
    int n2 = s2.length();
    int m = t.length();

    if (m > n1 || m > n2) {
        cout << 0 << "\n";
        return 0;
    }

    int max_len = max(n1, n2);
    vector<ll> p_pow(max_len + 1);
    p_pow[0] = 1;
    for (int i = 1; i <= max_len; ++i) {
        p_pow[i] = (p_pow[i - 1] * P) % M;
    }

    ll h_t = 0;
    for (int i = 0; i < m; ++i) {
        h_t = (h_t * P + (t[i] - 'a' + 1)) % M;
    }

    vector<ll> h_s1 = compute_prefix_hashes(s1, p_pow);
    vector<ll> h_s2 = compute_prefix_hashes(s2, p_pow);

    int common_count = 0;
    int max_start_index = min(n1, n2) - m;

    for (int i = 0; i <= max_start_index; ++i) {
        ll hash_s1_sub = get_substring_hash(h_s1, p_pow, i, i + m - 1);
        ll hash_s2_sub = get_substring_hash(h_s2, p_pow, i, i + m - 1);

        if (hash_s1_sub == h_t && hash_s2_sub == h_t) {
            common_count++;
        }
    }

    cout << common_count << "\n";

    return 0;
}