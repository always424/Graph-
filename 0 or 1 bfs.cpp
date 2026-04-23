void solve(){
    int n,m; cin>>n>>m;
    vector<pii>adj[n+5];
    for(int i =0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({w,v});
    }
    deque<int>dq;
    vector<int>dist(n+1,INT_MAX);
    int start; cin>>start;
    dist[start]=0;
    dq.push_back({start});
    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        for(auto [v,w]:adj[u]){
            if(w+dist[u]<dist[v]){
                dist[v]=w+dist[u];
                if(w==0) dq.push_front(v);
                else dq.push_back(v);
            }
        }

    }
}
