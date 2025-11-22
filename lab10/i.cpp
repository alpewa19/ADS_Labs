#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    
    vector<int> in_degree(n + 1, 0);

    for (int k = 0; k < m; ++k) {
        int u, v;
        cin >> u >> v;
        // u is a prerequisite for v
        adj[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        
        for (int v : adj[u]) {
            in_degree[v]--; 
            if (in_degree[v] == 0) {
                q.push(v); 
            }
        }
    }
    if (result.size() < n) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i = 0; i < n; ++i) {
            cout << result[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}