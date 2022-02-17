class Solution {
public:
    void solve(int i,int target,vector<vector<int>> &ans,vector<int> &ds,vector<int>& candidates)
    {
        if(i==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[i]<=target)
        {
            ds.push_back(candidates[i]);
            solve(i,target-candidates[i],ans,ds,candidates);
            ds.pop_back();
        }
        solve(i+1,target,ans,ds,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> empty;
        solve(0,target,ans,empty,candidates);
        return ans;
    }
};