int lowerBound(vector<int> &v,int target){
  int l=0;
  int r=v.size();
  while(l<r){
    int mid=l+(r-l)/2;
    /*To change to upper use <= instead of <*/
    if(v[mid]<target)
        l=mid+1;
    else
        r=mid;
  }
  return l;
}