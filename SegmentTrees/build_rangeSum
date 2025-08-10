void buildSegmentTree(int i,int l,int r,vector<int> &segmentTree,int arr[]){
        if(l == r){
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid =  l + (r-l) /2;
        buildSegmentTree(2*i+1,l,mid,segmentTree,arr);
        buildSegmentTree(2*i+2,mid+1,r,segmentTree,arr);
        
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
        
    }

     int rangeSum(int start,int end,int i,int l,int r,vector<int> &segmentTree){
        if(l > end || r < start){
            return 0; //out of bound
        }
        
        if(l>=start && r <= end){
            return segmentTree[i]; // totally inside the range
        }
        
        int mid = l + (r-l)/2;
        return rangeSum(start,end,2*i+1,l,mid,segmentTree) + rangeSum(start,end,2*i+2,mid+1,r,segmentTree);
    }