class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
     vector<vector<int>> ans;
        int n=nums.size();
        int z=1<<n;
        for(int i=0;i<z;i++)
        {
            int j=i;
            int idx=0;
            vector<int> temp;
            while(j>0)
            {
                if(j&1)
                {
                    temp.push_back(nums[idx]);
                }
                idx++;
                j=j>>1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};