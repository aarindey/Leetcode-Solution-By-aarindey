class Solution {
public:
    void recurse(int i,vector<int> &v,vector<vector<int>> &ans,vector<int>& nums)
    {
        if(i==nums.size())
        {
            if(find(ans.begin(),ans.end(),v)==ans.end())
            ans.push_back(v);
            return;
        }   
        
        v.push_back(nums[i]);
        recurse(i+1,v,ans,nums);
        v.pop_back();
        recurse(i+1,v,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> empty;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        recurse(0,empty,ans,nums);
        return ans;
    }
};