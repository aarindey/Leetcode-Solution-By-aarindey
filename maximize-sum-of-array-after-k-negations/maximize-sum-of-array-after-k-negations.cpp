class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum=0,c_neg=0;
        for(auto x:nums)
        {
        sum+=x;
        if(x<0)
        c_neg++;
        }
        if(nums[0]>0)
        {
            if(k%2==0)
            return sum;
            else
            return sum-2*nums[0];
        }
        else
        {
            if(c_neg>=k)
            {
                int i=0;
                while(k>0)
                {
                    sum-=2*nums[i];
                    k--;
                    i++;
                }
                return sum;
            }
            else
            {
                for(int i=0;i<c_neg;i++)
                {
                    sum-=2*nums[i];
                    k--;
                }
                if(k%2==0)
                return sum;
                else
                {
                if(c_neg<nums.size())
                return sum-2*min(abs(nums[c_neg-1]),nums[c_neg]);
                else
                return sum-2*abs(nums[c_neg-1]);
            }
         }
        }
        return 0;
    }
};