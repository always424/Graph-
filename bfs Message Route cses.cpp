#include <bits/stdc++.h>
using namespace std;

#define N 100005

vector<int> adj[N];
int vis[N], par[N];
bool found = false;

void dfs(int u, int parent, int target) {
    vis[u] = 1;
    par[u] = parent;

    if(u == target) {
        found = true;
        return;
    }

    for(auto v : adj[u]) {
        if(!vis[v]) {
            dfs(v, u, target);
            if(found) return; // stop recursion if target found
        }
    }
}

void naf() {
    int n, m;
    cin >> n >> m;

    // clear previous data
    for(int i = 0; i <= n; i++) {
        adj[i].clear();
        vis[i] = 0;
        par[i] = -1;
    }
    found = false;

    for(int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, n);

    if(!found) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> path;
    for(int u = n; u != -1; u = par[u])
        path.push_back(u);

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(auto u : path) cout << u << " ";
    cout << "\n";
}

int main() {
    naf();
}
