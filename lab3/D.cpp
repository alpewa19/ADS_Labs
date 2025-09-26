#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> array(N);
    for(int i = 0; i < N; ++i){
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    for(int i = 0; i < Q; ++i){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        auto lower1 = lower_bound(array.begin(), array.end(), l1);
        auto upper1 = upper_bound(array.begin(), array.end(), r1);
        long long count1 = upper1 - lower1;
        
        auto lower2 = lower_bound(array.begin(), array.end(), l2);
        auto upper2 = upper_bound(array.begin(), array.end(), r2);
        long long count2 = upper2 - lower2;
        
        long long intersection_count = 0;
        int l_intersect = max(l1, l2);
        int r_intersect = min(r1, r2);
        if (l_intersect <= r_intersect) {
            auto lower_intersect = lower_bound(array.begin(), array.end(), l_intersect);
            auto upper_intersect = upper_bound(array.begin(), array.end(), r_intersect);
            intersection_count = upper_intersect - lower_intersect;
        }
        cout << count1 + count2 - intersection_count << endl;
    }

    return 0;
}