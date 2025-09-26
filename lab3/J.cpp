#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool can(long long K, const vector<long long>& bags, long long H) {
    long long hours = 0;
    for (long long x : bags) {
        hours += (x + K - 1) / K;
        if (hours > H) return false; 
    }
    return hours <= H;
}
int main() {
    int N;
    long long H;
    cin >> N >> H;
    vector<long long> bags(N);
    for (int i = 0; i < N; i++) cin >> bags[i];
    long long lo = 1;
    long long hi = *max_element(bags.begin(), bags.end()); 
    long long ans = hi;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (can(mid, bags, H)) {
            ans = mid;      
            hi = mid - 1;   
        } else {
            lo = mid + 1;  
        }
    }
    cout << ans << "\n";
    return 0;
}