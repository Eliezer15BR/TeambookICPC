void sol(){
    int n,m; cin>>n>>m;
    vector<vector<int>> graph(2*m+20);
    for(int i=0;i<n;i++){
        char type; cin>>type;
        int top; cin>>top;
        top*=2; top^=(type=='-')?1:0;
        char type2; cin>>type2;
        int top2; cin>>top2;
        top2*=2; top2^=(type2=='-')?1:0;
        //a v b = -a -> b
        graph[top^1].push_back(top2);
        graph[top2^1].push_back(top);
    }
    //Implement scc
    for(int i=1;i<=m;i++){
        int j=i*2;
        if(ids[j^1]==ids[j]){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
    vector<int> res(m+1);
    for(int i=1;i<=m;i++){
        int j=2*i;
        if(ids[j]<ids[j^1]) res[i]=1;
    }
    //Tarjan <
    //Kosaraju >
}