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
    if (n == 0) return h;
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

ll get_string_hash(const string& s) {
    ll hash_val = 0;
    for (int i = 0; i < s.length(); ++i) {
        hash_val = (hash_val * P + (s[i] - 'a' + 1)) % M;
    }
    return hash_val;
}

int main() {
    precompute_powers(100000); 

    int n;
    while (cin >> n && n != 0) {
        vector<string> patterns(n);
        map<int, map<ll, vector<int>>> patterns_by_len;
        
        for (int i = 0; i < n; ++i) {
            cin >> patterns[i];
            int len = patterns[i].length();
            ll hash_p = get_string_hash(patterns[i]);
            patterns_by_len[len][hash_p].push_back(i);
        }

        string text;
        cin >> text;
        
        if (text.length() == 0) {
            cout << 0 << "\n";
            for(int i=0; i<n; ++i) cout << patterns[i] << "\n";
            continue;
        }

        vector<ll> h_text = compute_prefix_hashes(text);
        vector<int> frequencies(n, 0);

        for (auto const& [len, hash_map] : patterns_by_len) {
            if (len > text.length()) continue;
            
            for (int i = 0; i <= text.length() - len; ++i) {
                ll sub_hash = get_substring_hash(h_text, i, i + len - 1);
                if (hash_map.count(sub_hash)) {
                    for (int idx : hash_map.at(sub_hash)) {
                        frequencies[idx]++;
                    }
                }
            }
        }

        int max_freq = 0;
        for (int freq : frequencies) {
            max_freq = max(max_freq, freq);
        }

        cout << max_freq << "\n";
        for (int i = 0; i < n; ++i) {
            if (frequencies[i] == max_freq) {
                cout << patterns[i] << "\n";
            }
        }
    }

    return 0;
}