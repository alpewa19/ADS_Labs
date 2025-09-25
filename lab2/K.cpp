#include <iostream>
#include <queue>
using namespace std;

int main() {

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; 
        cin >> N;

        int freq[26] = {0};    
        queue<char> q;

        for (int i = 0; i < N; ++i) {
            char c; 
            cin >> c;

            ++freq[c - 'a'];
            q.push(c);

            while (!q.empty() && freq[q.front() - 'a'] > 1) q.pop();

            if (q.empty()) cout << -1;
            else cout << q.front();

            if (i + 1 < N) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}