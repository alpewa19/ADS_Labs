#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a;
    cin>>a;
    vector<int> v(a);
    for (int i=0;i<a;i++) cin>>v[i];
    int x;
    cin>>x;
    if (find(v.begin(), v.end(), x) != v.end()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}