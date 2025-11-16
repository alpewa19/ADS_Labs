#include <bits/stdc++.h>
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

int count_occurrences(string text, string pattern) {
    int count = 0;
    string a = text;
    while(text.size() < pattern.size()){
        text += a;
        count++;
    }
    string s = pattern + "#" + text;
    vector<int> pi = prefix_function(s);
    int m = pattern.size();
    for (int i = m + 1; i < s.size(); i++) {
        if (pi[i] == m) {
            return count+1;
        }
    }
    text += a;
    count++;
    string s2 = pattern + "#" + text;
    vector<int> pi2 = prefix_function(s2);
    int m2 = pattern.size();
    for (int i = m2 + 1; i < s2.size(); i++) {
        if (pi2[i] == m2) {
            return count+1;
        }
    }
    return -1;
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int count = count_occurrences(s1, s2);
    cout << count;
    return 0;
}