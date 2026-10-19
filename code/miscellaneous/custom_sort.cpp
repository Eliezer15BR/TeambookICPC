void sol(){
    vector<pair<int,int>> v;
    sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    });
}