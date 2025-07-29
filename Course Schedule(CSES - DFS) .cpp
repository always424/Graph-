#include <bits/stdc++.h>
using namespace std;

#define N 200005
vector<int> adj[N];
vector<int>ans;
int n, m;
int vis[N];
int ispo = 1;
void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(vis[v] == 2) continue;
        if(vis[v] == 0 ) dfs(v);
        else if(vis[v] == 1){
            ispo = 0;
        }
    }
    vis[u] =2;
    ans.push_back(u);
}

void Naf() {
    cin >> n >> m;
    for(int i =0;i<m;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i =1;i<=n;i++) if(!vis[i]) dfs(i);
    reverse(ans.begin(),ans.end());

    if(!ispo) cout <<"IMPOSSIBLE";
    else{
        for(auto node : ans) cout << node <<" ";
    }

}

int main() {
    // int t;
    // cin >> t;
    // while (t--) 
    Naf();
}
