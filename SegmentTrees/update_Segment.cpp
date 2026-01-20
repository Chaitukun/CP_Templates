   void updateSegmentTree(int index,int val,int i,int l,int r,vector<int> &segmentTree){
        if(l == r){
            segmentTree[i] = val; //update at one index 
            return;
        }

        int mid = l+(r-l)/2;
        if(index <= mid){
            updateSegmentTree(index,val,2*i+1,l,mid,segmentTree);
        }else{
            updateSegmentTree(index,val,2*i+2,mid+1,r,segmentTree);
        }

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }