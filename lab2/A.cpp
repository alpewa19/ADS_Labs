#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> array;
    for(int i = 0; i < N; i++){
        int a; cin>> a;
        array.push_back(a);
    }
    int k; cin >> k;
    int index = 0;
    int min = abs(array[0] - k);
    for(int i = 1; i < N; i++){
        if(abs(array[i] - k) < min) {
            min = abs(array[i] - k);
            index = i;
        }
    }
    cout << index;
    return 0;
}