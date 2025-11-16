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
    string s = pattern + "#" + text;
    vector<int> pi = prefix_function(s);
    int m = pattern.size();
    int count = 0;

    for (int i = m + 1; i < s.size(); i++) {
        if (pi[i] == m) {
            count++;
        }
    }

    return count;
}

int main() {
    string s1,s2;
    int k;
    cin >> s1 >> k >> s2;
    int count = count_occurrences(s2, s1);
    if(count >= k){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}