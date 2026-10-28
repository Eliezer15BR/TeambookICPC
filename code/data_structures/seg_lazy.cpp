struct SegLazy{
    int n; vector<Node> st; vector<ll>lazy;
    SegLazy(int n, vector<ll> &v){
        this->n=n;
        st.assign(4*n,Node());
        lazy.assign(4*n,0);
        build(1,0,n-1,v);
    }
    void build(int node, int l, int r, const vector<ll>&v){
        if(l==r){
            st[node]=Node(v[l]);
            return;
        }
        int mid=(l+r)/2;
        build(node*2,l,mid,v);
        build(node*2+1,mid+1,r,v);
        st[node]=st[node*2]+st[node*2+1];
    }
    void apply(int node, int l,int r, ll val){
        st[node].val+=val*(r-l+1);
        lazy[node]+=val;
    }
    void push(int node, int l, int r){
        if(lazy[node]!=0 && l!=r){
            int mid=(l+r)/2;
            apply(node*2,l,mid,lazy[node]);
            apply(node*2+1,mid+1,r,lazy[node]);
            lazy[node]=0;
        }
    }
    void update(int node, int l, int r, int ql, int qr, ll val){
        if(ql>r || qr<l) return;
        if(ql<=l && r<=qr){
            apply(node,l,r,val);
            return;
        }
        push(node,l,r);
        int mid=(l+r)/2;
        update(node*2,l,mid,ql,qr,val);
        update(node*2+1,mid+1,r,ql,qr,val);
        st[node]=st[node*2]+st[node*2+1];
    }
    Node query(int node, int l, int r, int ql, int qr){
        if(ql>r || qr<l) return Node();
        if(ql<=l && r<=qr) return st[node];
        push(node,l,r);
        int mid=(l+r)/2;
        return query(node*2,l,mid,ql,qr)+query(node*2+1,mid+1,r,ql,qr);
    }
    void update(int l, int r, ll val){
        update(1,0,n-1,l,r,val);
    }
    Node query(int l, int r){
        return query(1,0,n-1,l,r);
    }//all in [l,r]
};