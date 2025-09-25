#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int numberOfWords, shift;
    cin >> numberOfWords >> shift;
    deque<string> poem;
    for(int i = 0; i < numberOfWords; i++){
        string a; cin >> a;
        poem.push_back(a);
    }
    for(int i = 0; i < shift; i++){
        poem.push_back(poem.front());
        poem.pop_front();
    }
    for(int i = 0; i < numberOfWords; i++){
        cout << poem.front() << " ";
        poem.pop_front();
    }
    return 0;
}