typedef pair<ll,ll> Esp;
void dijkstra(){
    vector<vector<Esp>> graph(n+1); 
    vector<ll> dist(n+1,INF);
    priority_queue<Esp,vector<Esp>,greater<Esp>> pq;
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        auto [n_dist,node]=pq.top(); pq.pop();
        if(n_dist>dist[node]) continue;
        for(auto [v2,cost]:graph[node]){
            if(dist[v2]>n_dist+cost){
                dist[v2]=dist[node]+cost;
                pq.push({dist[v2],v2});
            }
        }
    }
}