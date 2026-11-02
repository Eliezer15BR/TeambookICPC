void sol(){
    int n,q; cin>>n>>q;
    vector<vector<int>> graph(n+1);
    int l=__lg(n)+2;
    vector<vector<int>> up(l,vector<int>(n+1));
    //Calculate binary lifting
    vector<int> dp(n+1);
    //Calculate the dept from root
    while(q--){
        int a,b; cin>>a>>b;
        if(dp[a]<dp[b])swap(a,b);
        int dif=dp[a]-dp[b];
        a=go_up(a,dif);
        if(b==a){cout<<a<<"\n"; continue;}
        //b is father of a
        for(int i=l-1;i>=1;i--){
            int aux_a=up[i][a];
            int aux_b=up[i][b];
            if(aux_a!=aux_b){
                a=aux_a;
                b=aux_b;
            }
        }
        cout<<up[1][a]<<"\n";
    }
}