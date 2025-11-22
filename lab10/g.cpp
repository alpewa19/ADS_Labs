#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start = -1, cycle_end = -1;

bool dfs_find_cycle(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs_find_cycle(u)) return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool is_acyclic_check(int v, int skip_u, int skip_v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (v == skip_u && u == skip_v) continue;
        if (color[u] == 1) return false; 
        if (color[u] == 0) {
            if (!is_acyclic_check(u, skip_u, skip_v)) return false;
        }
    }
    color[v] = 2;
    return true;
}

int main() {
    if (!(cin >> n >> m)) return 0;

    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    cycle_start = -1;

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && dfs_find_cycle(i)) break;
    }

    if (cycle_start == -1) {
        cout << "YES" << endl;
        return 0;
    }

    vector<pair<int, int>> cycle_edges;
    cycle_edges.push_back({cycle_end, cycle_start});
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle_edges.push_back({parent[v], v});
    }

    for (auto& edge : cycle_edges) {
        color.assign(n + 1, 0);
        bool possible = true;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                if (!is_acyclic_check(i, edge.first, edge.second)) {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}