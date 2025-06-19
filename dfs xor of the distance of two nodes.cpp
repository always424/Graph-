#include <bits/stdc++.h>
using namespace std;

#define N 200005
vector<pair<int,int>>adj[N];
int _xor[N];
void dfs(int u,int par){
    for(auto child : adj[u]){

        int v = child.first;
        int w = child.second;


        if(v == par) continue;
        _xor[v] = _xor[u]^w;
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

    int a, b; cin >> a >> b;
    cout << (_xor[a] ^ _xor[b]);

     

}

int main() {
    naf();
}
