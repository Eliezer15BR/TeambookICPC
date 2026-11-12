void sol(){
    int n,m; cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<bool> stacked(n+1,false);
    vector<int> tin(n+1,-1),low(n+1,-1),id(n+1,-1),st;
    int cnt=0, comp=0;
    auto dfs=[&](auto &dfs,int node)->void{
        tin[node]=low[node]=++cnt;
        stacked[node]=1;
        st.push_back(node);
        for(auto son:graph[node]){
            if(tin[son]==-1) dfs(dfs,son);
            if(stacked[son])
                low[node]=min(low[node],low[son]);
        }
        if(tin[node]==low[node]){
            comp++;
            while(true){
                int n_node=st.back();
                st.pop_back();
                stacked[n_node]=false;
                id[n_node]=comp;
                if(n_node==node) break;
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(tin[i]==-1) dfs(dfs,i);
    }
    cout<<comp<<"\n";
    for(int i=1;i<=n;i++){
        cout<<id[i]<<" ";
    }
    cout<<"\n";
}