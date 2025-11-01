#include <iostream>
#include <vector>
using namespace std;

bool compare_rows(const vector<int>& a, const vector<int>& b) {
    long long sa = 0, sb = 0;
    for (int x : a) sa += x;
    for (int x : b) sb += x;

    if (sa != sb) return sa > sb;        
    for (int i = 0; i < a.size(); ++i) 
        if (a[i] != b[i]) return a[i] < b[i];
    return false;              
}

void merge_rows(vector<vector<int>>& a, int L, int M, int R, vector<vector<int>>& tmp) {
    int i = L, j = M + 1, k = L;
    while (i <= M && j <= R) {
        if (compare_rows(a[i], a[j])) tmp[k++] = a[i++];
        else                           tmp[k++] = a[j++];
    }
    while (i <= M) tmp[k++] = a[i++];
    while (j <= R) tmp[k++] = a[j++];
    for (int t = L; t <= R; ++t) a[t] = tmp[t];
}

void merge_sort_rows(vector<vector<int>>& a, int L, int R, vector<vector<int>>& tmp) {
    if (L >= R) return;
    int M = L + (R - L) / 2;
    merge_sort_rows(a, L, M, tmp);
    merge_sort_rows(a, M + 1, R, tmp);
    merge_rows(a, L, M, R, tmp);
}

int main() {
  
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    vector<vector<int>> tmp(n, vector<int>(m));
    if (n) merge_sort_rows(matrix, 0, n - 1, tmp);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j]<<' ';
        }
        cout << '\n';
    }
    return 0;
}
