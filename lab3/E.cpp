#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int s = max(x2,y2);
        a[i]=s;
    }
    sort(a.begin(),a.end());
    cout << a[K-1];
    return 0;
}