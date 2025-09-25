#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
    string S;
    cin >> S;
    stack<char> sequence;
    for(int i = 0; i < S.size(); i++){
        if(!sequence.empty() && sequence.top() == S[i]){
            sequence.pop();
        }else{
            sequence.push(S[i]);
        }
    }
    if(sequence.empty()){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}