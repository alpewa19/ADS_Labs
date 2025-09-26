#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, K;
    cin >> N >> K;
    vector<int> houses;
    for(int i = 0; i < N; ++i){
        int ghouls;
        cin >> ghouls;
        houses.push_back(ghouls);
    }
    long long lower_bound = houses[0];
    long long upper_bound = houses[0];
    for(int i = 1; i < N; ++i){
        if(houses[i] > lower_bound){
            lower_bound = houses[i];
        }
        upper_bound += houses[i];
    }
    long long ans = upper_bound;
    while (lower_bound <= upper_bound) {
        long long mid_bound = (upper_bound + lower_bound) / 2;
        long long blocks = 1;
        long long sum = 0;
        bool check = true;
        for (long long house_ghouls : houses) {
            if (house_ghouls > mid_bound) {
                check = false;
                break;
            }
            if (sum + house_ghouls <= mid_bound) {
                sum += house_ghouls;
            } else {
                blocks++;
                sum = house_ghouls;
            }
        }
        if (check && blocks <= K) {
            ans = mid_bound;
            upper_bound = mid_bound - 1;
        } else {
            lower_bound = mid_bound + 1;
        }
    }

    cout << ans << endl;
    return 0;
}