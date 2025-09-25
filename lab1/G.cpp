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
    vector<int> p_new;
    vector<int> superP;
    for (int i = 2; i <= 10000; i++) {
        if (p[i] == 0) {
            p_new.push_back(i);
        }
    }
    for (int i = 0; i < p_new.size(); i++) {
        if(is_prime(i+1)){
            superP.push_back(p_new[i]);
        }
    }
    cout << superP[n-1];
    return 0;
}