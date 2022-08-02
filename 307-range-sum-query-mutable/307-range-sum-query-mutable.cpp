class NumArray {
    vector<int>seg_tree,nums;
    int n;
    void build(vector<int>& nums,int node,int start,int end)
    {
        if(start==end)
        {seg_tree[node]=nums[start];return;}
        
        int mid=(start+end)/2;
        
        build(nums,node*2,start,mid);
        build(nums,node*2+1,mid+1,end);
        seg_tree[node]=seg_tree[node*2]+seg_tree[node*2+1];
    }
    void update(int node,int start,int end,int idx,int diff)
    {
        if(start>end||end<idx||start>idx)return;
        
        seg_tree[node]+=diff;
        if(start==end)return;
        
        int mid=(start+end)/2;
        
        update(node*2,start,mid,idx,diff);
        update(node*2+1,mid+1,end,idx,diff);
    }
    int range_sum(int node,int start,int end,int l,int r)
    {
        if(end<l||start>r)return 0;
        
        if(start>=l&&end<=r)return seg_tree[node];
        
        if(start==end)return seg_tree[node];
        
        int mid=(start+end)/2;
        int left=range_sum(node*2,start,mid,l,r);
        int right=range_sum(node*2+1,mid+1,end,l,r);
        return left+right;
    }
public:
    NumArray(vector<int>& num) {
        n=num.size();
        seg_tree=vector<int>(4*n,0);
        nums=num;
        build(nums,1,0,n-1);
    }
    
    void update(int index, int val) {
        int diff=val-nums[index];
        nums[index]=val;
        update(1,0,n-1,index,diff);
    }
    
    int sumRange(int left, int right) {
        return range_sum(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */