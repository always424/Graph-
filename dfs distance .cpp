#include <bits/stdc++.h>
using namespace std;

#define N 200005
vector<pair<int,int>>adj[N];
int dis[N];
void dfs(int u,int par){
    for(auto child : adj[u]){

        int v = child.first;
        int w = child.second;
        if(v == par) continue;
        dis[v] = dis[u]+w;
        dfs(v,u);

    }
}
void naf() {
    int n; cin >> n;
    for(int i =0;i<n-1;i++){
        int u,v,w; cin >> u >> v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dfs(1,0);


    for(int i = 1;i<=n;i++){
        cout << dis[i]<<"\n";
    }

     

}

int main() {
    naf();
}
