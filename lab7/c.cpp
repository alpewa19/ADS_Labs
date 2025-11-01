#include <iostream>
#include <vector>
using namespace std;

void merge_range(vector<int>& v, int L, int M, int R, vector<int>& tmp) {
    int i = L, j = M + 1, k = L;
    while (i <= M && j <= R) {
        if (v[i] <= v[j]) tmp[k++] = v[i++];
        else              tmp[k++] = v[j++];
    }
    while (i <= M) tmp[k++] = v[i++];
    while (j <= R) tmp[k++] = v[j++];
    for (int t = L; t <= R; ++t) v[t] = tmp[t];
}

void mergesort(vector<int>& v, int L, int R, vector<int>& tmp) {
    if (L >= R) return;
    int M = L + (R - L) / 2;
    mergesort(v, L, M, tmp);
    mergesort(v, M + 1, R, tmp);
    merge_range(v, L, M, R, tmp);
}

int main() {
    int n, m;
   cin>>n>>m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < m; ++j) cin >> b[j];
    vector<int> ta(n), tb(m);
    if (n) mergesort(a, 0, n - 1, ta);
    if (m) mergesort(b, 0, m - 1, tb);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            cout << a[i] << ' ';  
            ++i; ++j;
        } else if (a[i] < b[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    return 0;
}
