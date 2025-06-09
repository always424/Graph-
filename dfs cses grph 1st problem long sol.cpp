#include <bits/stdc++.h>
using namespace std;
#define ll long long

void naf() {
    int n,m; cin >> n >> m;
    char grid[n][m];
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++) cin >> grid[i][j];
    }
    int visited[n][m];
    memset(visited,0,sizeof visited);

    int count = 0;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == '#' || visited[i][j] == 1) continue;

            
            queue<pair<int,int>> q;
            q.push({i,j});
            
            count++;
            while(!q.empty()){
                pair<int,int> u = q.front();
                q.pop();
                int x = u.first;
                int y = u.second;

                if(x-1 >= 0){
                    if(visited[x-1][y] == 0 &&grid[x-1][y] =='.' ){
                        q.push({x-1,y});
                        visited[x-1][y] = 1;
                    }
                }
                if(y+1 < m){
                    if(visited[x][y+1] == 0 &&grid[x][y+1] =='.' ){
                        q.push({x,y+1});
                        visited[x][y+1] = 1;
                    }
                }if(x+1 < n){
                    if(visited[x+1][y] == 0 &&grid[x+1][y] =='.' ){
                        q.push({x+1,y});
                        visited[x+1][y] = 1;
                    }
                }if(y-1 >= 0){
                    if(visited[x][y-1] == 0 &&grid[x][y-1] =='.' ){
                        q.push({x,y-1});
                        visited[x][y-1] = 1;
                    }
                }
                
            }
        }
    }

    cout << count;
}

int main() {
    int t;
    // cin >> t;
    // while (t--)
        naf();
}
