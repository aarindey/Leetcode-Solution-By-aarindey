class Solution {
public:
    void buildtree(vector<int>&tree,vector<int>&a,int index,int s,int e)
    {   
        if(s>e)
            return;
        if(s==e)
        {
            tree[index]=a[s];
            return;
        }
        int mid=(s+e)/2;
        buildtree(tree,a,2*index,s,mid);
        buildtree(tree,a,2*index+1,mid+1,e);
        int left=tree[2*index];
        int right=tree[2*index+1];
        tree[index]=left+right;
    }
    int query(vector<int>&tree2,vector<int>&tree,int index,int s,int e,int qs,int qe,int ispos)
    {   
        if(qs>e || qe<s)
            return 0;
        if(qs<=s && qe>=e)
        {
            if(ispos)
            {
                return tree[index];
            }
            else
            {
                return tree2[index];
            }
        }
        int mid=(s+e)/2;
        int leftans=query(tree2,tree,2*index,s,mid,qs,qe,ispos);
        int rightans=query(tree2,tree,2*index+1,mid+1,e,qs,qe,ispos);
        return leftans+rightans;
    }
    void updatenode(vector<int>&tree2,vector<int>&tree,int index,int s,int e,int i,int value,int ispos)
    {   
        if(i<s || i>e)
            return;
        if(s==e)
        {   
            if(ispos)
                tree[index]=value;
            else
                tree2[index]=value;
            return;
        }
        int mid=(s+e)/2;
        updatenode(tree2,tree,2*index,s,mid,i,value,ispos);
        updatenode(tree2,tree,2*index+1,mid+1,e,i,value,ispos);
        int left,right;
        if(ispos)
        {
            left=tree[2*index];
            right=tree[2*index+1];
            tree[index]=left+right;
        }
        else
        {
            left=tree2[2*index];
            right=tree2[2*index+1];
            tree2[index]=left+right;
        }
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(10004,0);
        vector<int>tree(4*10004,0);
        vector<int>a2(10004,0);
        vector<int>tree2(4*10004,0);
        buildtree(tree,a,1,0,10001);
        buildtree(tree2,a2,1,0,10001);
        vector<int>ans(n);
        int neg=0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>0)
            {
                int sum=query(tree2,tree,1,0,10001,0,nums[i]-1,1);
                ans[i]=sum+neg;
                a[nums[i]]++;
                updatenode(tree2,tree,1,0,10001,nums[i],a[nums[i]],1);
            }
            else
            {
                int sum=query(tree2,tree,1,0,10001,abs(nums[i])+1,10001,0);
                ans[i]=sum;
                a2[abs(nums[i])]++;
                updatenode(tree2,tree,1,0,10001,abs(nums[i]),a2[abs(nums[i])],0);
                neg++;
            }
        }
        return ans;
    }
};