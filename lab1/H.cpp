#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    bool check = is_prime(N);
    if(check){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}