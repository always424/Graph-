// Start ----
int n,m; 
vector<pair<int,int>>adj[MAXN];
vector<int> dis(MAXN,INT_MAX);
void always424() {
    cin>> n >> m;
    int s; cin >> s;
    for(int i =0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        pii cur = pq.top();
        int d = cur.first;
        int u = cur.second;
        pq.pop();
        if(dis[u] != d) continue;
        for(auto v : adj[u]){
            int nd = v.second+d;
            if(nd < dis[v.first]){
                dis[v.first] = nd;
                pq.push({nd,v.first});
            }
        }
    }
    for(int i =1;i<=n;i++) cout << dis[i]<<" ";
}
