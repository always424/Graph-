#include <bits/stdc++.h>
using namespace std;

#define N 100005

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
    int c=0;
    for(int i = 1;i<=n;i++){
     
        if(visited[i]) continue;

        c++;
        visited[i] = 1;
        queue<int>q;
        q.push(i);

        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(auto u:adj[k]){
                if(visited[u] ) continue;
                visited[u] = 1;
                q.push(u);
            }

        }
    }

    cout << c;
    return 0;
}
