void updateRange(int start,int end,int i,int l,int r,int val,vector<int> &segmentTree){
    vector<int> lazy(segmentTree.size(), 0);

    if(lazy[i] != 0) { //use  lazy propagate
        segmentTree[i] += (r - l + 1) * lazy[i] ; //no.of nodes * lazy value
        if(l != r) { //propagate down
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    if(l > end || r < start || l > r) {
        return; //out of bound
    }

    if(l >= start && r <= end) { //within range -> lazy propagate 
        segmentTree[i] += (r - l + 1) * val; 
        if(l != r) { 
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    }
    //overlapping
    int mid = l + (r - l) / 2;
    updateRange(start, end, 2*i+1, l, mid, val, segmentTree);
    updateRange(start, end, 2*i+2, mid+1, r, val, segmentTree);
    
    segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
}