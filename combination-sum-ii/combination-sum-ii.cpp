class Solution {
public:
    void solve(int i,int target,vector<vector<int>> &ans,vector<int> &ds,vector<int>& arr)
    {
      if(target==0)
      {
          ans.push_back(ds);
          return;
      }
        for(int j=i;j<arr.size();j++)
        {
            if(j>i&&arr[j]==arr[j-1])
                continue;
            if(arr[j]>target)
                break;
            ds.push_back(arr[j]);
            solve(j+1,target-arr[j],ans,ds,arr);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> empty;
        sort(candidates.begin(),candidates.end());
        solve(0,target,ans,empty,candidates);
        return ans;
    }
};