#include <bits/stdc++.h>
using namespace std;

#define N 200005
vector<int>adj[N];

int n,m; 
int vis[N];
int is_pos = 1;
int col[N];

void dfs(int u,int c){
    vis[u] = 1;
    col[u] = c;
    for(auto v: adj[u]){
        if(vis[v]){
            if(col[v] == c) continue;
            else{
                is_pos = 0;
                continue;
            }
            
        }

        dfs(v,3-c);
    }
}

void naf() {
    cin >> n>>m;
    for(int i =0;i<m;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i<=n;i++){
        if(vis[i]) continue;

        dfs(i,1);
    }
    if(is_pos == 0) cout <<"IMPOSSIBLE";
    else for(int i = 1;i<=n;i++) cout << col[i]<<" ";


}

int main() {
    naf();
}
