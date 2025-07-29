#include <bits/stdc++.h>
using namespace std;

#define N 200005
vector<int> adj[N];

int n, m;
int indeg[N];

void Naf() {
    cin >> n >> m;
    for(int i =0;i<m;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int>q;
    vector<int>top;
    for(int i = 1;i<=n;i++)    if(indeg[i] == 0) q.push(i);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        top.push_back(u);

        for(auto v : adj[u]){
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }

    if(top.size() != n) cout <<"IMPOSSIBLE";
    else{
        for(auto u : top) cout << u <<" ";
    }
    

}

int main() {
    // int t;
    // cin >> t;
    // while (t--) 
    Naf();
}
