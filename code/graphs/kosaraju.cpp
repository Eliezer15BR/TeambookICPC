void sol(){
    int n,m; cin>>n>>m;
    vector<vector<int>> graph(n+1),rev(n+1);
    vector<int> ord,group(n+1,-1);
    vector<bool> used(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        rev[v].push_back(u);
    }
    auto dfs=[&](auto &self,int node)->void{
        used[node]=true;
        for(auto son:graph[node]){
            if(!used[son]) self(self,son);
        }
        ord.push_back(node);
    };
    for(int i=1;i<=n;i++){
        if(!used[i])dfs(dfs,i);
    } 
    int code=0;
    reverse(ord.begin(),ord.end());
    used.assign(n+1,false);
    int k=ord.size();
    auto dfs2=[&](auto &self,int node)->void{
        used[node]=1;
        group[node]=code;
        for(auto son:rev[node]){
            if(!used[son]) self(self,son);
        }
    };
    for(int i=0;i<k;i++){
        if(!used[ord[i]]){
            code+=1;
            dfs2(dfs2,ord[i]);
        }
    }
}