#include <bits/stdc++.h>
using namespace std;

#define N 200005
vector<int>adj[N];
int lev[N];
int arr[N];
void dfs(int u,int p){
    for(auto v: adj[u]){
        if(p == v) continue;
        lev[v] = lev[u]+1;
        dfs(v,u);
    }
}
void naf() {
    int n; cin >> n;
    for(int i =0;i<n-1;i++){

        
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);
    int mx = 0, mx_node = 1;

    for(int i = 1;i<=n;i++){
        if(lev[i] > mx){
            
            mx = lev[i];
            mx_node = i;
        }
     }
     lev[mx_node] = 0;
     
     int end1 = mx_node;

     mx = 0;
     dfs(mx_node,0);
     for(int i = 1;i<=n;i++){
        if(lev[i] > mx){
            mx = lev[i];
            mx_node = i;
        }
     }
     int end2 = mx_node;
     for(int i  =1;i<=n;i++) arr[i] = lev[i];
          lev[mx_node] = 0;
     dfs(end2,0);
          for(int i  =1;i<=n;i++){
             arr[i] = max(arr[i],lev[i]);
             cout << arr[i]<<" ";
          }

     

}

int main() {
    naf();
}
