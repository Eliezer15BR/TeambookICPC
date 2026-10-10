struct Node{
    Node operator+(const Node &other) const{
        //merge
    }
};
struct SegmentTree {
    int n;
    vector<Node> st;
    SegmentTree(int n, vector<ll>& v) {
        this->n = n;
        st.assign(2 * n, Node());
        for (int i = 0; i < n; i++) st[n + i] = Node(v[i]);
        for (int i = n - 1; i > 0; i--) 
            st[i] = st[i << 1]+st[i << 1 | 1];
    }
    void update(int pos, ll value) {
        pos += n;
        st[pos] = value; 
        for (int i = pos >> 1; i > 0; i >>= 1) {
            st[i] = st[i << 1]+st[i << 1 | 1];
        }
    }
    Node query(int l, int r) {
        Node resL = Node(), resR = Node();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1){
                resL = resL+ st[l]; l++;
            } 
            if (r & 1){
                r--; resR =st[r]+ resR; 
            } 
        }
        return resL+ resR;
    }
};