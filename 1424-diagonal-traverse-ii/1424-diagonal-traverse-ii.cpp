class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<vector<int> > tuple;
        for(int i=0;i<n;i++)
        {
            vector<int> v=nums[i];
            for(int j=0;j<v.size();j++)
            {
                tuple.push_back({i+j,j,v[j]});
            }   
        }
        sort(tuple.begin(),tuple.end(),comp);
        vector<int> ans;
        for(auto v:tuple)
        {
            ans.push_back(v[2]);
        }
        return ans;
    }
};