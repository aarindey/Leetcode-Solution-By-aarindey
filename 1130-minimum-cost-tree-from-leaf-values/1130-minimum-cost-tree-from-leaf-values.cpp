class Solution {
public:
    map<pair<int,int>,pair<int,int>> memo;
    pair<int,int> fun(int l,int r,vector<int> &arr)
    {
        if(l>r)   
        return {0,1000000};    
        if(l==r)  // leaf nodes (sum=0)
        return {arr[l],0};
        if(memo.find({l,r})!=memo.end())
        return memo[{l,r}];
        pair<int,int> ans;
        ans.first=0;
        ans.second=1000000;
        //first max         second sum
        for(int i=l;i<r;i++)
        {
            pair<int,int> left,right;
            left=fun(l,i,arr);
            right=fun(i+1,r,arr);
            int total=left.second+right.second+left.first*right.first;
            if(total<ans.second)
            {
                ans.first=max(left.first,right.first);
                ans.second=total;
            }
        }
        return memo[{l,r}]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        return fun(0,arr.size()-1,arr).second;
    }
};