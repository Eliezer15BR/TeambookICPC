vector<int> genLps(string &cad){
    int len=0;
    int j=1;
    int n=cad.size();
    vector<int> lps(n);
    lps[0]=0;
    while(j<n){
        if(cad[len]==cad[j]){
            len++;
            lps[j]=len;
            j++;
        }
        else{
            if(len!=0) len=lps[len-1];
            else{
                lps[j]=0;
                j++;
            }
        }
    }
    return lps;
}
vector<int> kmp(string &text, string &pat){
    vector<int> lps=genLps(pat);
    vector<int> ans;
    int i=0;
    int j=0;
    int n=text.size();
    while(i<n){
        if(pat[j]==text[i]){
            i++; j++;
            if(j==pat.size()){
                ans.push_back(i-j);
                j=lps[j-1];
            } 
        }
        else{
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
    return ans;
}