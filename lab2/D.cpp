#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> array;
    map<int, int> dict;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        dict[a] += 1;
    }
    int max = 0;
    for (const auto& pair : dict) {
        if(pair.second > max){
            max = pair.second;
        }
    }
    for (const auto& pair : dict) {
        if(pair.second == max){
            array.push_back(pair.first);
        }
    }
    sort(array.begin(), array.end());
     for (int i = array.size()-1; i >= 0; i--) {
        cout << array[i] << " ";
    }
}