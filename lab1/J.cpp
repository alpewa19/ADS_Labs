#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
    char ch;
    int number;
    deque<int> zhansaya;
    vector<int> sums;
    while(true){
        cin >> ch;
        if(ch == '!'){
            break;
        }
        else if(ch == '+'){
            cin >> number;
            zhansaya.push_front(number);
        }
        else if(ch == '-'){
            cin >> number;
            zhansaya.push_back(number);
        }
        else if (ch == '*') {
            if(zhansaya.empty()){
                cout << "error" << endl;
            }
            else if (zhansaya.size() >= 2) {
                int sum = zhansaya.back() + zhansaya.front();
                cout << sum << endl;
                zhansaya.pop_front();
                zhansaya.pop_back();
            }
            else if (zhansaya.size() == 1) {
                int sum = zhansaya.front() + zhansaya.front();
                cout << sum << endl;
                zhansaya.pop_front();
            }
            else{
                continue;
            }
        }
    }
}