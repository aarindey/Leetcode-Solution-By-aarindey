class Solution {
public:
    vector<vector<int> > ans;
    void generate(vector<int> &v,int i,vector<int> &nums)
    {
        if(i==nums.size())
        {
        ans.push_back(v);
        return;
        }
        generate(v,i+1,nums);
        v.push_back(nums[i]);
        generate(v,i+1,nums);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty;
        generate(empty,0,nums);
        return ans;
    }
};