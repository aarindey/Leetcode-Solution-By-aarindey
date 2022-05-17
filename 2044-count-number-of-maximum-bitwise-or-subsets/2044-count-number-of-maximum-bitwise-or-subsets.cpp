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
            int k=0,idx=0;
            int j=i;
            while(j)
            {
                if(j&1)
                {
                    curr_or|=nums[idx];
                }
                idx++;
                j=j>>1;
            }
            if(curr_or==max_or)
            ans++;
        }
        return ans;
        
    }
};