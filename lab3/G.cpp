#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long flights_needed(vector<long long> c, long long cap) {
    long long total = 0;
    for (int i = 0; i < (int)c.size(); i++) {
        total += (c[i] + cap - 1) / cap;
    }
    return total;
}

int main() {
    int n;
    long long f;
    cin >> n >> f;
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    long long L = 1;  
    long long R = *max_element(c.begin(), c.end());

    while (L < R) {
        long long mid = L + (R - L) / 2;
        if (flights_needed(c, mid) <= f) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }

    cout << L << "\n";
    return 0;
}