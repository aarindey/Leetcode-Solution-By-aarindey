class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or=0,ans=0;
        int n=nums.size();
        for(auto num:nums)
        {
            max_or|=num;
        }
        int z=(1<<n);
        for(int i=0;i<z;i++)
        {
            int curr_or=0;
            int k=0;
            for(int j=0;j<17;j++)
            {
                if(i&(1<<j))
                {
                curr_or|=nums[j];
                }
            }
            if(curr_or==max_or)
            ans++;
        }
        return ans;
        
    }
};