class Solution {
public:
    void func(int k,int &n,int i,int sum,vector<int> &v,vector<int> curr,vector<vector<int>> &ans)
    {
        if(sum==n&&k==0)
        {
            ans.push_back(curr);
            return;
        }
        if(sum>n)
        return;
        if(k<0)
        return;
        if(i>8)
        return;
    
        curr.push_back(v[i]);
        func(k-1,n,i+1,sum+v[i],v,curr,ans);
        curr.pop_back();
        func(k,n,i+1,sum,v,curr,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        func(k,n,0,0,v,{},ans);
        return ans;
    }
};