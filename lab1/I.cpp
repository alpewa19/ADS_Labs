#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    queue<int> SAKAYANAGI, KATSURAGI;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S'){
            SAKAYANAGI.push(i);
        }
        else {
            KATSURAGI.push(i);
        }
    }


    while (!SAKAYANAGI.empty() && !KATSURAGI.empty()){
        int checkS = SAKAYANAGI.front(); 
        SAKAYANAGI.pop();
        int checkK = KATSURAGI.front(); 
        KATSURAGI.pop();
        if (checkS < checkK) {
            SAKAYANAGI.push(checkS + n);
        } else {
            KATSURAGI.push(checkK + n);
        }
    }

    if (KATSURAGI.empty()){
        cout << "SAKAYANAGI\n";
    }
    else{
        cout << "KATSURAGI\n";
    }
    return 0;
}