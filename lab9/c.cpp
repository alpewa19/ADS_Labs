#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int pattern_in_rotation(string text, string pattern) {
    string doubled = text + text;
    string s = pattern + "#" + doubled;
    vector<int> pi = prefix_function(s);
    int m = pattern.size();

    for (int i = m + 1; i < s.size(); i++) {
        if (pi[i] == m) {
            return s.size()-i-1;
        }
    }

    return -1;
}

int main() {
    string text, pattern;
    cin >> text;
    cin >> pattern;
    int shift = pattern_in_rotation(text, pattern);
    cout << shift;
    return 0;
}