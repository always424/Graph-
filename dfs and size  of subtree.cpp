#include <bits/stdc++.h>
using namespace std;

#define N 100005

vector<int> adj[N];
int visited[N];
int sz[N];

void dfs(int u){
    visited[u] = 1;
    sz[u] = 1;
    for(auto v : adj[u]){
        if(visited[v]) continue;
        dfs(v);
        sz[u] += sz[v];
    }
}

int main() {
    int n, m; 
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for(int i = 1; i <= n; i++) 
        cout << sz[i] << " ";

    return 0;
}
