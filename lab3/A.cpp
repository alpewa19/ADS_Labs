#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    vector<int> valuesToFind;
    for(int i = 0; i < T; i++){
        int value;
        cin >> value;
        valuesToFind.push_back(value);
    }
    int N, M;
    cin >> N >> M;
    map<int, pair<int, int>> coordinatesOfNumbers;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int number;
            cin >> number;
            coordinatesOfNumbers[number] = {i, j};
        }
    }
    for(int i = 0; i < T; i++){
        if(coordinatesOfNumbers.count(valuesToFind[i])){
            pair<int, int> coords = coordinatesOfNumbers[valuesToFind[i]];
            cout << coords.first << " " << coords.second << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}