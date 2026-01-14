ll dist[505][505];
void always(){
    int n,m,q; cin>>n>>m>>q;
    for(int i =1;i<=n;i++){
        for(int j =0;j<=n;j++){
            if(i!=j) dist[i][j]=LLONG_MAX;
        }
    }
    for(int i =1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u] =min(dist[v][u],w);
    }
    for(int k =1;k<=n;k++){
        for(int i =1;i<=n;i++){
            for(int j =1;j<=n;j++){
                if(dist[i][k]  !=LLONG_MAX && dist[k][j] !=LLONG_MAX) dist[i][j] =min(dist[i][k] + dist[k][j],dist[i][j]);
            }
        }
    }
    while(q--){
        int u,v; cin>>u>>v;
        if(dist[u][v] == LLONG_MAX) cout<<-1;
        else cout<<dist[u][v];
        nll;
    }

}
