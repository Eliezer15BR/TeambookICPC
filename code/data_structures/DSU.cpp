struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n,1);
        for (int i=0;i<n;i++)
            parent[i]=i;
    }
    int find_set(int v) {
        if(v==parent[v]) return v;
        return parent[v]=find_set(parent[v]); 
    }
    bool join(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a, b); 
            parent[b]=a;
            sz[a]+=sz[b];
            return true;
        }
        return false;
    }
    int size(int a){ 
        return sz[find_set(a)];
    }
};