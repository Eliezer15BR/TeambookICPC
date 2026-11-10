void sol(){
    int n; cin>>n;
    int l=__lg(n)+2;
    vector<vector<int>> up(l,vector<int>(n+1));
    //up[x][y] desde y hasta (1<<x)
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        up[1][i]=x;
    }
    for(int i=2;i<l;i++){
        for(int j=1;j<=n;j++){
            int ant=up[i-1][up[i-1][j]];
            up[i][j]=ant;
        }
    }
    auto go_up=[&](int x, int k)->int{
        int current=x;
        int aux=1;
        while(k){
            if(k&1) current=up[aux][current];
            aux++;
            k>>=1;
        }
        return current;
    };
}