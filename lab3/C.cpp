#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> array;
    for(int i = 0; i < N; ++i){
        int number;
        cin >> number;
        array.push_back(number);
    }
    for(int i = 0; i < Q; ++i){
        int l1, r1, l2, r2, count = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        for(int j = 0; j < N; ++j){
            if((array[j] >= l1 & array[j] <= r1) || (array[j] >= l2 & array[j] <= r2)) count++;
        }
        cout << count << endl;
    }
    return 0;
}