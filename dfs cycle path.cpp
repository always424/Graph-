#include <bits/stdc++.h>
using namespace std;

int n,m;
int vis[100005];
int lev[100005];
int pre[100005];
bool cycle_found = false;
int cycle_start, cycle_end;
vector<int>adj[100005];

void dfs(int u,int prev){
    vis[u] = 1;
    pre[u] = prev;
    for(auto v : adj[u]){
        if(v == prev) continue;
        if(vis[v]){
            if(!cycle_found){
                cycle_found = 1;
                cycle_start = v;
                cycle_end = u;
            }
            continue;
        }

        dfs(v,u);
    }
}

void naf() {
    cin >> n >> m;

    for(int i = 0;i<m;i++){
        int u,v; cin >>u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i =1;i<=n;i++){
        if(vis[i]) continue;

        dfs(i,0);
    }

    if(!cycle_found) cout <<"IMPOSSIBLE";
    else{
        vector<int>path;
        path.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = pre[v]) {
            path.push_back(v);
        }
        path.push_back(cycle_start); 
        reverse(path.begin(), path.end());
        cout << path.size()<<"\n";
        for(auto u : path) cout << u <<" ";
    }
}

int main() {
    // int t; cin >> t;
    // for(int i = 1;i<=t;t++){
    naf();
}
