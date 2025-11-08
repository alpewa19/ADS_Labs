#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

const ll P = 53;
const ll M = 1e9 + 9;

vector<ll> p_pow;
vector<ll> h_s;

ll get_substring_hash(int l, int r) {
    ll hash_val = h_s[r];
    if (l > 0) {
        hash_val = (hash_val - (h_s[l - 1] * p_pow[r - l + 1]) % M + M) % M;
    }
    return hash_val;
}

ll compute_hash(const string& s) {
    ll hash_val = 0;
    for (int i = 0; i < s.length(); ++i) {
        hash_val = (hash_val * P + (s[i] - 'a' + 1)) % M;
    }
    return hash_val;
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;

    int N = s.length();

    p_pow.resize(N + 1);
    h_s.resize(N);
    p_pow[0] = 1;
    for (int i = 1; i <= N; ++i) {
        p_pow[i] = (p_pow[i - 1] * P) % M;
    }
    h_s[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < N; ++i) {
        h_s[i] = (h_s[i - 1] * P + (s[i] - 'a' + 1)) % M;
    }

    vector<string> tapes(n);
    vector<ll> h_tapes(n);
    for (int i = 0; i < n; ++i) {
        cin >> tapes[i];
        h_tapes[i] = compute_hash(tapes[i]);
    }

    vector<int> max_len_at(N, 0);

    for (int k = 0; k < n; ++k) {
        int m = tapes[k].length();
        if (m > N) continue;

        for (int i = 0; i <= N - m; ++i) {
            if (get_substring_hash(i, i + m - 1) == h_tapes[k]) {
                max_len_at[i] = max(max_len_at[i], m);
            }
        }
    }

    vector<int> max_reach(N);
    max_reach[0] = max_len_at[0] - 1;

    for (int i = 1; i < N; ++i) {
        int current_tape_reach = (max_len_at[i] > 0) ? (i + max_len_at[i] - 1) : -1;
        max_reach[i] = max(max_reach[i - 1], current_tape_reach);
    }

    int current_end = -1;

    while (current_end < N - 1) {
        int next_pos_to_check = current_end + 1;
        int next_end = max_reach[next_pos_to_check];

        if (next_end <= current_end) {
            cout << "NO" << "\n";
            return 0;
        }
        current_end = next_end;
    }

    cout << "YES" << "\n";

    return 0;
}