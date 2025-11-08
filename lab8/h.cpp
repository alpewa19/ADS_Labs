#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

using ll = long long;

const ll P = 53;
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

bool check(int len, int k, const vector<string>& s, const vector<vector<ll>>& h) {
    if (len == 0) return true;

    set<ll> common_hashes;
    int n0 = s[0].length();
    for (int i = 0; i <= n0 - len; i++) {
        common_hashes.insert(get_substring_hash(h[0], i, i + len - 1));
    }

    for (int i = 1; i < k; i++) {
        set<ll> current_hashes;
        int ni = s[i].length();
        for (int j = 0; j <= ni - len; j++) {
            ll sub_hash = get_substring_hash(h[i], j, j + len - 1);
            if (common_hashes.count(sub_hash)) {
                current_hashes.insert(sub_hash);
            }
        }
        if (current_hashes.empty()) return false;
        common_hashes = current_hashes;
    }

    return !common_hashes.empty();
}

int main() {
    int k;
    cin >> k;
    vector<string> s(k);
    int min_len = 5001;
    int max_len = 0;
    for (int i = 0; i < k; i++) {
        cin >> s[i];
        min_len = min(min_len, (int)s[i].length());
        max_len = max(max_len, (int)s[i].length());
    }

    precompute_powers(max_len);

    vector<vector<ll>> h(k);
    for (int i = 0; i < k; i++) {
        h[i] = compute_prefix_hashes(s[i]);
    }

    int l = 0, r = min_len;
    int ans_len = 0;
    string ans_str = "";

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, k, s, h)) {
            ans_len = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (ans_len > 0) {
        set<ll> common_hashes;
        int n0 = s[0].length();
        for (int i = 0; i <= n0 - ans_len; i++) {
            common_hashes.insert(get_substring_hash(h[0], i, i + ans_len - 1));
        }

        for (int i = 1; i < k; i++) {
            set<ll> current_hashes;
            int ni = s[i].length();
            for (int j = 0; j <= ni - ans_len; j++) {
                ll sub_hash = get_substring_hash(h[i], j, j + ans_len - 1);
                if (common_hashes.count(sub_hash)) {
                    current_hashes.insert(sub_hash);
                }
            }
            common_hashes = current_hashes;
        }
        
        ll ans_hash = *common_hashes.begin();
         for (int i = 0; i <= s[0].length() - ans_len; i++) {
            if (get_substring_hash(h[0], i, i + ans_len - 1) == ans_hash) {
                ans_str = s[0].substr(i, ans_len);
                break;
            }
        }
    }

    cout << ans_str << "\n";

    return 0;
}