    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
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

                    for(int k = 0;k<4;k++){
                        int r = x+dx[k];
                        int c = y+dy[k];

                        if(r >= 0 && r < n && c >= 0 && c < m){
                            if(grid[r][c] == '.' && visited[r][c] == 0 ){
                                visited[r][c] = 1;
                                q.push({r,c});
                            }
                        }
                    }
                    
                }
            }
        }

        cout << count;
    }

    int main() {
        // int t;
        // cin >> t;
        // while (t--)
            naf();
    }
