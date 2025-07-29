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
        if(vis[v] == 1) continue;
        dfs(v);
        
    }
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
    int ans1[n+2];
    int nxt[n+2];
    for(int i = 1;i<=n;i++) {
        ans1[i] = INT_MIN;
        nxt[i] = -1;
    }

    ans1[n] = 1;

    for(int i = n-1;i>=0;i--){
        int u = ans[i];
        if(u == n) continue;

        int mx = INT_MIN;
        int node = 0;

        for(auto v : adj[u]){
            if(ans1[v] > mx){
                mx = ans1[v];
                node = v;

            }
        }
        ans1[u] = mx+1;
        nxt[u] = node;
    }

    if(ans1[1] < 0) cout << "IMPOSSIBLE";
    else{
        cout <<ans1[1]<<"\n";
        for(int i = 1;i!=-1;i=nxt[i]) {
            cout << i <<" ";
            if(i ==n) break;
        }
    }

}

int main() {
    // int t;
    // cin >> t;
    // while (t--) 
    Naf();
}
