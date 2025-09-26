#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> pref(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum += num;
        pref[i] = sum; 
    }

    for (int i = 0; i < M; i++) {
        long long x;
        cin >> x;
        int block = int(lower_bound(pref.begin(), pref.end(), x) - pref.begin());
        cout << block + 1 << "\n"; 
    }

    return 0;
}