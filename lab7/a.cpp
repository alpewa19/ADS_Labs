#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge_by_len(vector<string>& a, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = a[l + i];
    for (int j = 0; j < n2; ++j) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].size() <= R[j].size()) a[k++] = L[i++];
        else                             a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void merge_sort_by_len(vector<string>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    merge_sort_by_len(a, l, m);
    merge_sort_by_len(a, m + 1, r);
    merge_by_len(a, l, m, r);
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    string dummy; getline(cin, dummy);
    for (int tc = 0; tc < T; ++tc) {
        string line; 
        getline(cin, line);

        vector<string> words;
        string cur;
        for (int i = 0; i <= line.size(); ++i) {
            if (i < line.size() && line[i] != ' ') cur += line[i];
            else {
                if (!cur.empty()) { words.push_back(cur); cur.clear(); }
            }
        }

        if (!words.empty()) {
            merge_sort_by_len(words, 0, (int)words.size() - 1);
        }

        for (int i = 0; i < words.size(); ++i) {
            if (i) cout << ' ';
            cout << words[i];
        }
        if (tc + 1 < T) cout << "\n";
    }
    return 0;
}
