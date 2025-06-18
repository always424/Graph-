#include <bits/stdc++.h>
using namespace std;

#define N 100005
int lev[N];
vector<int> adj[N];
int visited[N];
int main() {
    int n, m; 
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   int a,b; cin >> a >> b;

   queue<int>q;
   visited[a] = 1;
   q.push(a);
   while(!q.empty()){
        int k = q.front();
        q.pop();

        for(auto u : adj[k]){
            if(visited[u]) continue;
            lev[u] = lev[k]+1;
            visited[u] = 1;
            q.push(u);
        }
   }

   if(visited[b]) cout <<"YES \n" << lev[b];
   else cout <<"NO\n";

    return 0;
}
