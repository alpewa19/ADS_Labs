#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<int> primes() {
    vector<int> is_prime(10000, 0);
    for (int i = 2; i * i <= 10000; i++) {
        if (is_prime[i] == 0) {
            for (int j = i * i; j <= 10000; j += i) {
                is_prime[j] = 1;
            }
        }
    }
    return is_prime;
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    vector<int> p = primes();
    for (int i = 2; i <= 10000; i++) {
        if (p[i] == 0) {
            count += 1;
        }
        if(count == n){
            cout << i;
            return 0;
        }
    }
    cout << endl;
    return 0;
}