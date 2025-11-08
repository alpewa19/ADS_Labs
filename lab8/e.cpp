#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<long long> p2(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p2[i] = p2[i - 1] * 2;
    }

    string s = "";
    long long p_prev = 0;

    for (int i = 0; i < n; ++i) {
        long long diff = p[i] - p_prev;
        long long val = diff / p2[i];
        s += (char)(val + 97);
        p_prev = p[i];
    }

    cout << s << "\n";

    return 0;
}